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

    window_ = glfwCreateWindow(kScrWidth, kScrHeight, "First OpenGL game", nullptr, nullptr);

    if (window_ == nullptr)
    {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window_);
    glfwSetWindowUserPointer(window_, this);
    glfwSetFramebufferSizeCallback(window_, FramebufferSizeCallback);
    glfwSetCursorPosCallback(window_, MouseCallback);
    glfwSetScrollCallback(window_, ScrollCallback);
}

void Game::GameLoop()
{
    player_ = std::make_unique<Player>();

    Texture texture;

    unsigned char *data = stbi_load("../src/textures/container.jpg", width, &height, &nrChannels, 0);

    GLint texture1;
    
    player_->GetShader()->Use();
    player_->GetShader()->SetInt("texture1", 0);

    while (!glfwWindowShouldClose(window_))
    {
        float current_frame = glfwGetTime();
        delta_time_ = current_frame - last_frame_;
        last_frame_ = current_frame;

        ProcessInput(window_);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        player_->GetShader()->Use();
        glm::mat4 projection = glm::perspective(glm::radians(camera_->GetZoom()), (float)kScrWidth / (float)kScrHeight, 0.1f, 100.0f);

        player_->GetShader()->SetMat4("projection", projection);

        glm::mat4 view = glm::lookAt(camera_->GetPosition(), camera_->GetPosition() + camera_->GetFront(), camera_->GetUp());
        player_->GetShader()->SetMat4("view", view);

        glBindVertexArray(player_->GetVAO());
        
        for (size_t i = 0; i < 10; ++i) {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, player_->GetPositions()[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            player_->GetShader()->SetMat4("model", model);

            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        glfwSwapBuffers(window_);
        glfwPollEvents();
    }

    glfwTerminate();
}

void Game::ProcessInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    float cameraSpeed = static_cast<float>(2.5 * delta_time_);
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera_->GetPosition() += cameraSpeed * camera_->GetFront();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera_->GetPosition() -= cameraSpeed * camera_->GetFront();
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera_->GetPosition() -= glm::normalize(glm::cross(camera_->GetFront(), camera_->GetUp())) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera_->GetPosition() += glm::normalize(glm::cross(camera_->GetFront(), camera_->GetUp())) * cameraSpeed;
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

void Game::SetMouse(bool value)
{
    first_mouse_ = value;
}