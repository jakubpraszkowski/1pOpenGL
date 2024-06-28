#pragma once

#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <LearnOpenGL/game.hpp>

class Movement {
public:
    void ProcessInput(std::unique_ptr<GLFWwindow>& window);
    static void ScrollCallback(GLFWwindow* window, double x_offset, double y_offset);
    static void MouseCallback(GLFWwindow* window, double x_pos_in, double y_pos_in);

private:
    std::unique_ptr<Game> game_ = nullptr;
    glm::vec3 camera_pos_ = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 camera_front_ = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 camera_up_ = glm::vec3(0.0f, 1.0f, 0.0f);
    bool first_mouse_ = true;
    float yaw_   = -90.0f;	
    float pitch_ =  0.0f;
    float last_x_ =  800.0f / 2.0f;
    float last_y_ =  600.0f / 2.0f;
    float fov_ = 45.0f;
};