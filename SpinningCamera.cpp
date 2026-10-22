#include "SpinningCamera.hpp"

void SpinningCamera::Update()
{
	// Check for if we'd like to pause or not
	// TODO: Check this really is tab
	Input::ToggleWithKey(paused, GLFW_KEY_TAB);
	if (paused) return;

	// Spin
	rotation += rotationSpeed * Window::GetDeltaTime();
	rotation = std::fmod(rotation, 360);

	// Translate the camera out along the direction of the rotation
	float angle = glm::radians(rotation);
	glm::vec3 position = targetPosition + glm::vec3(
		distance * std::cos(angle),
		height,
		distance * std::sin(angle)
	);

	// Update the camera
	camera->SetPosition(position);
	camera->LookAt(targetPosition);
}