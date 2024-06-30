#pragma once

#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>

struct Vertex {
    glm::vec3 position = glm::vec3(0.0f);
    glm::vec3 normal = glm::vec3(0.0f);
    glm::vec2 tex_coords = glm::vec2(0.0f);
};

class Mesh {
public:
    Mesh(const std::vector<Vertex>& vertices, const std::vector<uint64_t>& indices);

    void Render() const;

private:
    void SetupMesh();   

    std::vector<Vertex> vertices_ = {};
    std::vector<uint64_t> indices_ = {};
    GLuint VAO_ = 0, VBO_ = 0, EBO_ = 0;
};