#pragma once

#include <LearnOpenGL/entity.hpp>

class Player : public Entity {
public:
    Player();

    void Update(float delta_time) override;
    void Render(shader_ptr shader) override;
};