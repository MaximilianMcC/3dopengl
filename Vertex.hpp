#pragma once

#include <glm.hpp>
#include <tiny_obj_loader.h>

struct Vertex
{
private:
	bool hasNormals = false;
	bool hasTextures = false;

public:
	glm::vec3 Position = glm::vec3(0.0f);
	glm::vec2 TextureCoordinates = glm::vec2(0.0f);
	glm::vec3 Normal = glm::vec3(0.0f);

	Vertex() { }
	Vertex(glm::vec3 position, glm::vec2 textureCoordinates, glm::vec3 normal)
	{
		Position = position;
		TextureCoordinates = textureCoordinates;
		Normal = normal;
	}

	Vertex(const tinyobj::attrib_t& attributes, tinyobj::index_t& vertex)
	{
		// Set the position
		Position = glm::vec3(
			attributes.vertices[3 * (size_t)vertex.vertex_index + 0],
			attributes.vertices[3 * (size_t)vertex.vertex_index + 1],
			attributes.vertices[3 * (size_t)vertex.vertex_index + 2]
		);

		// Set the texture coordinates (if we have any)
		hasTextures = vertex.texcoord_index >= 0;
		if (HasTextures())
		{
			TextureCoordinates = glm::vec2(
				attributes.texcoords[2 * (size_t)vertex.texcoord_index + 0],
				attributes.texcoords[2 * (size_t)vertex.texcoord_index + 1]
			);
		}

		// Set the normals (if we have any)
		hasNormals = vertex.normal_index >= 0;
		if (HasNormals())
		{
			Normal = glm::vec3(
				attributes.normals[3 * (size_t)vertex.normal_index + 0],
				attributes.normals[3 * (size_t)vertex.normal_index + 1],
				attributes.normals[3 * (size_t)vertex.normal_index + 2]
			);
		}
	}

	bool HasNormals() { return hasNormals; }
	bool HasTextures() { return hasTextures; }

	// TODO: Rename
	//? position (vector 3)
	//? texture (vector 2)
	//? normals (vector 3)
	static int NumberOfNumbers() { return 3 + 2 + 3; }

	static int SizeOfNumberOfNumbers() { return (3 + 2 + 3) * sizeof(GLfloat); }
};