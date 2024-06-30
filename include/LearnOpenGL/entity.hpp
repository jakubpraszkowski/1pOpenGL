#pragma once

#include <memory>

#include <LearnOpenGL/shader.hpp>
#include <LearnOpenGL/mesh.hpp>
#include <LearnOpenGL/texture.hpp>

class Entity {
public:
    Entity();
    virtual ~Entity();

    virtual void Update(float delta_time);
    virtual void Render(std::shared_ptr<Shader> shader);

    /* Getters and setters */
    void SetPosition(const glm::vec3& position);
    void SetRotation(const glm::vec3& rotation);
    void SetScale(const glm::vec3& scale);
    glm::vec3 GetPosition() const;
    glm::vec3 GetRotation() const;
    glm::vec3 GetScale() const;
    glm::mat4 GetTransformMatrix() const;

protected:
    glm::vec3 position_ = glm::vec3(0.0f);
    glm::vec3 rotation_ = glm::vec3(0.0f);
    glm::vec3 scale_ = glm::vec3(1.0f);
    std::shared_ptr<Mesh> mesh_ = nullptr;
    std::shared_ptr<Texture> texture_ = nullptr;
};