#pragma once

#include <iostream>

#include <stb_image/stb_image.h>
#include <glad/glad.h>

class Texture
{
public:
    Texture(GLuint64 width, GLuint64 height, unsigned char *data, uint64_t nr_channels);
    ~Texture();

    GLuint getId() const;
private:
    GLenum CheckFormat(uint64_t nr_channels);

    GLuint id_ = 0;
    GLuint64 width_ = 0, height_ = 0;
    GLuint wrap_s_ = 0, wrap_t_ = 0, filter_min_ = 0, filter_max_ = 0;
};