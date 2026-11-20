#include "EditorCamera.hpp"

void EditorCamera::Start()
{
	Input::SetMouseLocked(true);
}

void EditorCamera::Update()
{
	LookAround();
	MoveAround();
}

void EditorCamera::LookAround()
{
	glm::vec2 input = -Input::GetMouseDelta() * sensitivity;
	float& pitch = rotation.y;
	float& yaw = rotation.x;

	// Look up/down
	pitch += input.y;
	pitch = std::clamp(pitch, -89.0f, 89.0f);

	// Spin around
	yaw += input.x;
	if (yaw > 360.0f) yaw = 0.0f;

	// Turn it into a direction and update the camera
	float yawRad = glm::radians(yaw);
	float pitchRad = glm::radians(pitch);
	camera->SetDirection(glm::vec3(
		sin(yawRad) * cos(pitchRad),
		sin(pitchRad),
		cos(yawRad) * cos(pitchRad)
	));
}

void EditorCamera::MoveAround()
{
	glm::vec3 input = Input::GetWasdQeInput();

	// Get which direction to move in
	glm::vec3 forward = glm::vec3(camera->GetDirection());
	glm::vec3 right = glm::normalize(glm::cross(forward, camera->GetUp()));
	
	// Move
	glm::vec3 movement = (forward * input.z) + (right * input.x);
	position += movement * speed * Window::GetDeltaTime();
	camera->SetPosition(position);
}
