#pragma once

#include <cstdint>
#include <memory>
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <LearnOpenGL/movement.hpp>

void FramebufferSizeCallback(GLFWwindow *window, int width, int height);

class Game
{
public:
    Game();

    void GameLoop();
    
    /* Getters and setters */
    float GetDeltaTime() const;
    float GetLastFrame() const;

private:
    const uint64_t kScrWidth = 800U, kScrHeight = 600U;

    float delta_time_ = 0.0f, last_frame_ = 0.0f;
    std::unique_ptr<GLFWwindow> window_ = nullptr;
    std::unique_ptr<Movement> movement_ = nullptr;
};