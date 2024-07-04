#include <LearnOpenGL/texture.hpp>
#include "stb_image_impl.cpp"

Texture::Texture(GLuint64 width, GLuint64 height, unsigned char *data, uint64_t nr_channels)
{
    width_ = width;
    height_ = height;

    GLenum format = CheckFormat(nr_channels);

    glGenTextures(1, &id_);
    glBindTexture(GL_TEXTURE_2D, id_);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_set_flip_vertically_on_load(true);

    if (!data)
    {
        std::cerr << "Failed to load texture" << std::endl;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, static_cast<GLsizei>(width_), static_cast<GLsizei>(height_), 0, format, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
}

Texture::~Texture()
{
    glDeleteTextures(1, reinterpret_cast<GLuint *>(&id_));
}

GLuint Texture::getId() const
{
    return id_;
}

/* Private methods */

GLenum Texture::CheckFormat(uint64_t nr_channels)
{
    switch (nr_channels)
    {
    case 1:
        return GL_RED;
    case 3:
        return GL_RGB;
    case 4:
        return GL_RGBA;
    default:
        return GL_RGB;
    }
}