#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

enum class Camera_Movement {
    kForward = 0,
    kBackward,
    kLeft,
    kRight
};

class Camera
{
public:
    struct Position {
        float x;
        float y;
        float z;
    };

    Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
    Camera(Position position, Position position_up, float yaw, float pitch);
    void ProcessKeyboard(Camera_Movement direction, float delta_time);
    void ProcessMouseMovement(float x_offset, float y_offset, GLboolean constrain_pitch = true);
    void ProcessMouseScroll(float y_offset);

    /* Getters and setters */
    glm::mat4 GetViewMatrix();
    glm::vec3 GetPosition() const;
    glm::vec3 GetFront() const;
    glm::vec3 GetUp() const;
    float GetZoom() const;
    float GetYaw() const;
    float GetPitch() const;
    float GetMovementSpeed() const;
    float GetMouseSensitivity() const;

private:
    void updateCameraVectors();

    glm::vec3 position_ = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 front_ = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 up_ = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 right_ = glm::vec3(0.0f, 0.0f, 0.0f);
    glm::vec3 world_up_ = glm::vec3(0.0f, 1.0f, 0.0f);
    float yaw_ = -90.0f;
    float pitch_ = 0.0f;
    float movement_speed_ = 2.5f;
    float mouse_sensitivity_ = 0.1f;
    float zoom_ = 45.0f;
};