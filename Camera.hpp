#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Window.hpp"

class Camera
{
private:
	glm::vec3 position = glm::vec3(
		0.0f);
	glm::vec3 direction = glm::vec3(0.0f, 0.0f, -1.0f);
	
	float fovDegrees = -1.0f;
	float fovRadians = -1.0f;

	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

public:
	/***********************************************/

	glm::vec3 GetPosition() { return position; }
	glm::vec3 AddPosition(glm::vec3 addition) { return position += addition; }
	void SetPosition(glm::vec3 newPosition) { position = newPosition; }

	// TODO: Normalise in the setter
	glm::vec3 GetDirection() { return direction; }
	glm::vec3 AddDirection(glm::vec3 addition) { return direction += addition; }
	void SetDirection(glm::vec3 newDirection) { direction = newDirection; }

	// TODO: Normalise in the setter
	glm::vec3 GetUpDirection() { return up; }
	void SetUpDirection(glm::vec3 newUpDirection) { up = newUpDirection; }

	float GetFov() { return fovDegrees; }
	float AddFov(float newFov);
	void SetFov(float newFov);

	/***********************************************/

	glm::mat4 GetViewMatrix();
	glm::mat4 GetProjectionMatrix();

	/***********************************************/

	Camera(glm::vec3 position, float fov = 90.0f);
	Camera() { }

	/***********************************************/

	void LookAt(glm::vec3 position);
};