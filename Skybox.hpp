#pragma once

#include <string>
#include <glm.hpp>
#include "Graphics.hpp"
#include "Renderable.hpp"

class Skybox : public Renderable
{
private:
	GLuint texture = 0;
	GLuint vao = 0;
	GLuint vbo = 0;

	void GenerateTexture(std::string skyboxDirectoryPath);
	void GenerateMesh();

public:
	Skybox(std::string skyboxDirectoryPath);

	void Render();
};