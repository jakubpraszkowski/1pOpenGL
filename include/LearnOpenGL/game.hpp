#pragma once

#include <cstdint>
#include <memory>
#include <iostream>
#include <vector>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <LearnOpenGL/camera.hpp>
#include <LearnOpenGL/entity.hpp>
#include <LearnOpenGL/player.hpp>

void FramebufferSizeCallback(GLFWwindow *window, int width, int height);
void MouseCallback(GLFWwindow *window, double x_pos, double y_pos);
void ScrollCallback(GLFWwindow *window, double x_offset, double y_offset);

class Game
{
public:
    Game();

    void GameLoop();
    void ProcessInput(std::unique_ptr<GLFWwindow> &window);
    
    /* Getters and setters */
    float GetDeltaTime() const;
    float GetLastFrame() const;
    bool GetFirstMouse() const;
    float GetLastX() const;
    float GetLastY() const;
    std::unique_ptr<Camera> &GetCamera();
    void SetLastX(float x);
    void SetLastY(float y);
    void SetMouse(bool value);

private:
    const uint64_t kScrWidth = 800U, kScrHeight = 600U;

    float delta_time_ = 0.0f, last_frame_ = 0.0f;
    bool first_mouse_ = true;
    float last_x = kScrWidth / 2.0f, last_y = kScrHeight / 2.0f;
    std::unique_ptr<GLFWwindow> window_ = nullptr;
    std::unique_ptr<Camera> camera_ = nullptr;
    std::unique_ptr<Player> player_ = nullptr;
    std::vector<std::shared_ptr<Entity>> entities_;
};