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
	const float distance = 5.0f;
	const float height = 5.0f;

	float rotation = 0.0f;
	float rotationSpeed = 50.0f;

	bool paused = false;
public:

	void SetCamera(Camera* newCamera) { camera = newCamera; }

	void Update() override;
};