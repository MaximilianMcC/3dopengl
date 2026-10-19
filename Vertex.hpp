#pragma once

#include <glm.hpp>
#include <TINY/tiny_obj_loader.h>

struct Vertex
{
public:
    glm::vec3 Position = glm::vec3(0.0f);
    glm::vec3 TextureCoordinates = glm::vec3(0.0f);

    Vertex() { }
    Vertex(glm::vec3 position, glm::vec3 textureCoordinates)
    {
        Position = position;
        TextureCoordinates = textureCoordinates;
    }

    void SetPosition(const tinyobj::attrib_t attributes, size_t vertexIndex)
    {
        Position = glm::vec3(
            attributes.vertices[3 * (size_t)vertexIndex + 0],
            attributes.vertices[3 * (size_t)vertexIndex + 1],
            attributes.vertices[3 * (size_t)vertexIndex + 2]
        );
    }
};