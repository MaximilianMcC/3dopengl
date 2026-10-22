#pragma once

// PUT MODEL MATRIX STUFF IN HERE THEN MAYBE ABSTRACT RENDER METHOD
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Graphics.hpp"
#include "Camera.hpp"

class Renderable
{
private:
	glm::vec3 position = glm::vec3(0.0f);
	glm::vec3 rotation = glm::vec3(0.0f);
	float scale = 1.0f;
public:
	glm::mat4 GetModelMatrix();

	// TODO: Put this in graphics maybe
	void SendMatricesToShader(GLuint shader);
};