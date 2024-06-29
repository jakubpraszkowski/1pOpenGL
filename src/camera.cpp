#include <LearnOpenGL/camera.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : position_(position), world_up_(up), yaw_(yaw), pitch_(pitch) {
    updateCameraVectors();
}

Camera::Camera(Position position, Position position_up, float yaw, float pitch) {
    position_ = glm::vec3(position.x, position.y, position.z);
    world_up_ = glm::vec3(position_up.x, position_up.y, position_up.z);
    yaw_ = yaw;
    pitch_ = pitch;
    updateCameraVectors();
}

void Camera::ProcessKeyboard(Camera_Movement direction, float delta_time)
{
    float velocity = movement_speed_ * delta_time;
    if (direction == Camera_Movement::kForward)
        position_ += front_ * velocity;
    if (direction == Camera_Movement::kBackward)
        position_ -= front_ * velocity;
    if (direction == Camera_Movement::kLeft)
        position_ -= right_ * velocity;
    if (direction == Camera_Movement::kRight)
        position_ += right_ * velocity;
}

void Camera::ProcessMouseMovement(float x_offset, float y_offset, GLboolean constrain_pitch)
{
    x_offset *= mouse_sensitivity_;
    y_offset *= mouse_sensitivity_;

    yaw_ += x_offset;
    pitch_ += y_offset;

    if (constrain_pitch)
    {
        if (pitch_ > 89.0f)
            pitch_ = 89.0f;
        if (pitch_ < -89.0f)
            pitch_ = -89.0f;
    }

    updateCameraVectors();
}

void Camera::ProcessMouseScroll(float y_offset)
{
    zoom_ -= y_offset;
    if (zoom_ < 1.0f)
        zoom_ = 1.0f;
    if (zoom_ > 45.0f)
        zoom_ = 45.0f;
}

glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(position_, position_ + front_, up_);
}

float Camera::GetZoom() const
{
    return zoom_;
}

float Camera::GetYaw() const
{
    return yaw_;
}

float Camera::GetPitch() const
{
    return pitch_;
}

float Camera::GetMovementSpeed() const
{
    return movement_speed_;
}

float Camera::GetMouseSensitivity() const
{
    return mouse_sensitivity_;
}

/* Private methods */

void Camera::updateCameraVectors()
{
    glm::vec3 front;
    front.x = cos(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    front.y = sin(glm::radians(pitch_));
    front.z = sin(glm::radians(yaw_)) * cos(glm::radians(pitch_));
    front_ = glm::normalize(front);
    
    right_ = glm::normalize(glm::cross(front_, world_up_));
    up_ = glm::normalize(glm::cross(right_, front_));
}