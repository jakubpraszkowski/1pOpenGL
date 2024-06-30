#pragma once

#include <iostream>

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image/stb_image.h>
#endif

#include <glad/glad.h>

class Texture
{
public:
    Texture(uint64_t width, uint64_t height, unsigned char *data, uint64_t nr_channels);
    ~Texture();

private:
    GLenum CheckFormat(uint64_t nr_channels);

    uint64_t id_ = 0;
    uint64_t width_ = 0, height_ = 0;
    uint64_t wrap_s_ = 0, wrap_t_ = 0, filter_min_ = 0, filter_max_ = 0;
};