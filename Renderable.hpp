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
protected:
	// TODO: Put this in graphics maybe
	void SendMatricesToShader(GLuint shader);

public:
	glm::mat4 GetModelMatrix();

	glm::vec3 GetPosition() { return position; }
	void SetPosition(glm::vec3 newPosition) { position = newPosition; }
	glm::vec3 AddPosition(glm::vec3 newPosition) { return (position += newPosition); }

	glm::vec3 GetRotation() { return rotation; }
	void SetRotation(glm::vec3 newRotation) { rotation = newRotation; }

	float GetScale() { return scale; }
	void SetPosition(float newScale) { scale = newScale; }
};