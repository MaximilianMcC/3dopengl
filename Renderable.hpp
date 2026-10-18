#pragma once

// PUT MODEL MATRIX STUFF IN HERE THEN MAYBE ABSTRACT RENDER METHOD
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Graphics.hpp"

class Renderable
{
private:
	glm::vec3 position;
	glm::vec3 rotation;
	float scale;
public:
	glm::mat4 GetModelMatrix();

	// TODO: Put this in graphics maybe
	void SendMatricesToShader(GLuint shader);
};