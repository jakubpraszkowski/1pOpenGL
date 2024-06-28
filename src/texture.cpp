#include <LearnOpenGL/texture.hpp>

Texture::Texture(uint64_t width, uint64_t height, unsigned char *data, uint64_t nr_channels)
{
    width_ = width;
    height_ = height;

    GLenum format = CheckFormat(nr_channels);

    glGenTextures(1, reinterpret_cast<GLuint *>(&id_));
    glBindTexture(GL_TEXTURE_2D, id_);

    if (!data)
    {
        std::cerr << "Failed to load texture" << std::endl;
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrap_s_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrap_t_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter_min_);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter_max_);

    stbi_image_free(data);
}

Texture::~Texture()
{
    glDeleteTextures(1, reinterpret_cast<GLuint *>(&id_));
}

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