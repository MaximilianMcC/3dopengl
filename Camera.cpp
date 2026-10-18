#include "Camera.hpp"

Camera::Camera(glm::vec3 position, float fov)
{
	SetPosition(position);
	SetFov(fov);
}

// TODO: Just make it so set returns it too
float Camera::AddFov(float newFov)
{
	SetFov(GetFov() + newFov);
	return GetFov();
}

void Camera::SetFov(float newFov)
{
	// Limit it to something between 0 and 360
	if (newFov < 0) newFov = 0;
	if (newFov > 360) newFov = 360;

	// Get it in radians and degrees
	fovDegrees = newFov;
	fovRadians = glm::radians(fovDegrees);
}

glm::mat4 Camera::GetViewMatrix()
{
	return glm::lookAt(position, position + direction, up);
}

glm::mat4 Camera::GetProjectionMatrix()
{
	float windowAspectRatio = Window::GetWidth() / Window::GetHeight();
	return glm::perspective(fovRadians, windowAspectRatio, 0.1f, 100.0f);
}

void Camera::LookAt(glm::vec3 targetPosition)
{
	glm::vec3 directionToThing = targetPosition - position;
	direction = directionToThing;
}