#pragma once

#include "GameObject.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include "Input.hpp"
#include <cmath>

class SpinningCamera : public GameObject
{
private:
	Camera* camera;
	
	glm::vec3 targetPosition;
	float distance = 5.0f;
	float height = 3.0f;

	float rotation = 0.0f;
	float rotationSpeed = 35.0f;

	bool paused = false;
public:

	void SetCamera(Camera* newCamera) { camera = newCamera; }

	float GetRotationSpeed() { return rotationSpeed; }
	void SetRotationSpeed(float newSpeed) { rotationSpeed = newSpeed; }

	void SetTargetPosition(glm::vec3 newTargetPosition) { targetPosition = newTargetPosition; }
	glm::vec3 GetTargetPosition() { return targetPosition; }

	void SetDistance(float newDistance, float newHeight)
	{
		distance = newDistance;
		height = newHeight;
	}

	float getDistance() { return distance; }
	float getHeight() { return height; }

	void Update() override;
};