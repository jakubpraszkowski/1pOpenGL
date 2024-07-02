#include <LearnOpenGL/game.hpp>

void FramebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void MouseCallback(GLFWwindow *window, double x_pos_in, double y_pos_in)
{
    Game *game = static_cast<Game *>(glfwGetWindowUserPointer(window));
    if (game)
    {
        float x_pos = static_cast<float>(x_pos_in);
        float y_pos = static_cast<float>(y_pos_in);

        if (game->GetFirstMouse())
        {
            game->SetLastX(x_pos);
            game->SetLastY(y_pos);
            game->SetMouse(false);
        }

        float x_offset = x_pos - game->GetLastX();
        float y_offset = game->GetLastY() - y_pos;

        game->SetLastX(x_pos);
        game->SetLastY(y_pos);

        game->GetCamera()->ProcessMouseMovement(x_offset, y_offset);
    }
}

void ScrollCallback(GLFWwindow *window, double x_offset, double y_offset)
{
    Game *game = static_cast<Game *>(glfwGetWindowUserPointer(window));
    if (game)
    {
        game->GetCamera()->ProcessMouseScroll(y_offset);
    }
}

Game::Game()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window_ = std::unique_ptr<GLFWwindow>(glfwCreateWindow(kScrWidth, kScrHeight, "First OpenGL game", nullptr, nullptr));

    if (window_ == nullptr)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window_.get());
    glfwSetWindowUserPointer(window_.get(), this);
    glfwSetFramebufferSizeCallback(window_.get(), FramebufferSizeCallback);
    glfwSetCursorPosCallback(window_.get(), MouseCallback);
    glfwSetScrollCallback(window_.get(), ScrollCallback);
}

void Game::GameLoop()
{
    player_ = std::make_unique<Player>();

    while (!glfwWindowShouldClose(window_.get()))
    {
        float current_frame = glfwGetTime();
        delta_time_ = current_frame - last_frame_;
        last_frame_ = current_frame;

        ProcessInput(window_);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window_.get());
        glfwPollEvents();
    }

    glfwTerminate();
}

float Game::GetDeltaTime() const
{
    return delta_time_;
}

float Game::GetLastFrame() const
{
    return last_frame_;
}

bool Game::GetFirstMouse() const
{
    return first_mouse_;
}

float Game::GetLastX() const
{
    return last_x;
}

float Game::GetLastY() const
{
    return last_y;
}

std::unique_ptr<Camera> &Game::GetCamera()
{
    return camera_;
}

void Game::SetLastX(float x)
{
    last_x = x;
}

void Game::SetLastY(float y)
{
    last_y = y;
}