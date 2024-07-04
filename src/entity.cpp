#include <LearnOpenGL/entity.hpp>

Entity::Entity() {
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
}

Entity::~Entity() {
    glDeleteVertexArrays(1, &this->VAO);
    glDeleteBuffers(1, &this->VBO);
}

void Entity::Update(float delta_time) {

}

void Entity::Render(shader_ptr shader) {

}

void Entity::SetPosition(const glm::vec3& position) {
    position_ = position;
}

void Entity::SetRotation(const glm::vec3& rotation) {
    rotation_ = rotation;
}

void Entity::SetScale(const glm::vec3& scale) {
    scale_ = scale;
}

glm::vec3 Entity::GetPosition() const {
    return position_;
}

glm::vec3 Entity::GetRotation() const {
    return rotation_;
}

glm::vec3 Entity::GetScale() const {
    return scale_;
}

std::shared_ptr<Shader> Entity::GetShader() const {
    return shader_;
}

std::shared_ptr<Texture> Entity::GetTexture() const {
    return texture_;
}