#pragma once

#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <LearnOpenGL/game.hpp>

class Movement {
public:
    void ProcessInput(std::unique_ptr<GLFWwindow>& window);
    void ScrollCallback(GLFWwindow* window, double x_offset, double y_offset);
    void MouseCallback(GLFWwindow* window, double x_pos_in, double y_pos_in);

private:
    std::unique_ptr<Game> game_;
};