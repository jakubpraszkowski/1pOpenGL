#pragma once

#include <memory>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>

#include <LearnOpenGL/game.hpp>

class Movement {
public:
    void processInput(GLFWwindow *window);
    void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
    void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);

private:
    std::unique_ptr<Game> game;
};