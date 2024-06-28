#include <LearnOpenGL/movement.hpp>

void Movement::ProcessInput(std::unique_ptr<GLFWwindow>& window) {
    if (glfwGetKey(window.get(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window.get(), true);

    float camera_speed = static_cast<float>(2.5 * game_->GetDeltaTime());

    if (glfwGetKey(window.get(), GLFW_KEY_W) == GLFW_PRESS)
        camera_pos_ += camera_speed * camera_front_;
    if (glfwGetKey(window.get(), GLFW_KEY_S) == GLFW_PRESS)
        camera_pos_ -= camera_speed * camera_front_;
    if (glfwGetKey(window.get(), GLFW_KEY_A) == GLFW_PRESS)
        camera_pos_ -= glm::normalize(glm::cross(camera_front_, camera_up_)) * camera_speed;
    if (glfwGetKey(window.get(), GLFW_KEY_D) == GLFW_PRESS)
        camera_pos_ += glm::normalize(glm::cross(camera_front_, camera_up_)) * camera_speed;
}

void Movement::ScrollCallback(GLFWwindow *window, double x_offset, double y_offset) {
    fov_ -= static_cast<float>(y_offset);
    if (fov_ < 1.0f)
        fov_ = 1.0f;
    if (fov_ > 45.0f)
        fov_ = 45.0f;
}

void Movement::MouseCallback(GLFWwindow *window, double x_pos_in, double y_pos_in) {
    float x_pos = static_cast<float>(x_pos_in);
    float y_pos = static_cast<float>(y_pos_in);

    if (first_mouse_)
    {
        last_x_ = x_pos;
        last_y_ = y_pos;
        first_mouse_ = false;
    }

    float xoffset = x_pos - last_x_;
    float yoffset = last_y_ - y_pos; // reversed since y-coordinates go from bottom to top
    last_x_ = x_pos;
    last_y_ = y_pos;

    float sensitivity = 0.1f; // change this value to your liking
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    yaw_ += xoffset;
    pitch_ += yoffset;

    // make sure that when pitch is out of bounds, screen doesn't get flipped
    if (pitch_ > 89.0f)
        pitch_ = 89.0f;
    if (pitch_ < -89.0f)
        pitch_ = -89.0f;

    glm::vec3 front;
    front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    front.y = sin(glm::radians(pitch_));
    front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    camera_front_ = glm::normalize(front);
}