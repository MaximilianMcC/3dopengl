#pragma once

#include "GameObject.hpp"
#include "Camera.hpp"
#include "Window.hpp"
#include "Input.hpp"
#include <cmath>
#include <algorithm>
#include <iostream>

class EditorCamera : public GameObject
{
private:
	Camera* camera;

	glm::vec3 position;
	glm::vec2 rotation;
	float zoom;

	float sensitivity = 0.2f;
	float speed = 100.0f;
	float zoomSpeed = 5.0f;

	void LookAround();
	void MoveAround();
	void Zoom();

public:
	void Start() override;
	void SetCamera(Camera* newCamera) { camera = newCamera; }
	void Update() override;
};