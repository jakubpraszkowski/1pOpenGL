#include <LearnOpenGL/game.hpp>

void FramebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

Game::Game() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_ = std::unique_ptr<GLFWwindow>(glfwCreateWindow(kScrWidth, kScrHeight, "First OpenGL game", nullptr, nullptr));

    if (window_ == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window_.get());
    glfwSetFramebufferSizeCallback(window_.get(), FramebufferSizeCallback);
    glfwSetCursorPosCallback(window_.get(), mouse_callback);
    glfwSetScrollCallback(window_.get(), scroll_callback);
}

float Game::GetDeltaTime() const {
    return delta_time_;
}

float Game::GetLastFrame() const {
    return last_frame_;
}