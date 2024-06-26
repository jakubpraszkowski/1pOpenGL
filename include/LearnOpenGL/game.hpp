#pragma once

#include <cstdint>
#include <memory>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void FramebufferSizeCallback(GLFWwindow* window, int width, int height);

class Game {
public:
    Game();

    /* Getters and setters */
    float GetDeltaTime() const;
    float GetLastFrame() const;

private:
    const uint64_t kScrWidth = 800U, kScrHeight = 600U;

    float delta_time_ = 0.0f, last_frame_ = 0.0f;
    std::unique_ptr<GLFWwindow> window_;
};