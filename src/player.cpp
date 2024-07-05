#include <LearnOpenGL/player.hpp>

Player::Player() {
    vertices_ = Coords::player;
    cube_coords_ = Coords::cube_positions;

    glBufferData(GL_ARRAY_BUFFER, vertices_.size() * sizeof(float), &vertices_.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    shader_ = std::make_unique<Shader>("../shaders/player.vs", "../shaders/player.fs");
}

void Player::Render(shader_ptr shader) {

}

void Player::Update(float delta_time) {

}