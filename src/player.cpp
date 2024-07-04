#include <LearnOpenGL/player.hpp>

Player::Player() {
    vertices = Coords::player;

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    shader_ = std::make_unique<Shader>("../shaders/player.vs", "../shaders/player.fs");

    // texture_ = std::make_shared<Texture>();
}

void Player::Render(shader_ptr shader) {

}

void Player::Update(float delta_time) {
    // Do something
}