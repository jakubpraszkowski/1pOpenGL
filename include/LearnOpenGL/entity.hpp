#pragma once

#include <memory>
#include <vector>
#include <variant>

#include <LearnOpenGL/shader.hpp>
#include <LearnOpenGL/texture.hpp>
#include <LearnOpenGL/coords.hpp>

using shader_ptr = std::variant<std::shared_ptr<Shader>, std::unique_ptr<Shader>>;

class Entity {
public:
    Entity();
    virtual ~Entity();

    virtual void Update(float delta_time);
    virtual void Render(shader_ptr shader);

    /* Getters and setters */
    void SetPosition(const glm::vec3& position);
    void SetRotation(const glm::vec3& rotation);
    void SetScale(const glm::vec3& scale);
    glm::vec3 GetPosition() const;
    glm::vec3 GetRotation() const;
    glm::vec3 GetScale() const;
    std::shared_ptr<Shader> GetShader() const;
    std::shared_ptr<Texture> GetTexture() const;

protected:
    unsigned int VBO = 0, VAO = 0;
    glm::vec3 position_ = glm::vec3(0.0f);
    glm::vec3 rotation_ = glm::vec3(0.0f);
    glm::vec3 scale_ = glm::vec3(1.0f);
    std::vector<float> vertices = {};
    std::shared_ptr<Texture> texture_ = nullptr;
    std::shared_ptr<Shader> shader_ = nullptr;
};