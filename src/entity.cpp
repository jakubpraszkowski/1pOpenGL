#include <LearnOpenGL/entity.hpp>

Entity::Entity() {

}

Entity::~Entity() {

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