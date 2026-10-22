#include "Renderable.hpp"

glm::mat4 Renderable::GetModelMatrix()
{
	glm::mat4 identity = glm::mat4(1.0f);

	// Position
	glm::mat4 translationMatrix = glm::translate(identity, position);

	// Rotation
	// TODO: Don't do all three things like this like this
	glm::mat4 rotationMatrixYaw = glm::rotate(identity, glm::radians(rotation).x, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 rotationMatrixPitch = glm::rotate(identity, glm::radians(rotation).y, glm::vec3(0.0f, 1.0f, 0.0f));
	glm::mat4 rotationMatrixRoll = glm::rotate(identity, glm::radians(rotation).z, glm::vec3(0.0f, 0.0f, 1.0f));
	glm::mat4 rotationMatrix = rotationMatrixYaw * rotationMatrixPitch * rotationMatrixRoll;

	// Scale
	glm::mat4 scaleMatrix = glm::scale(identity, glm::vec3(scale));

	return translationMatrix * rotationMatrix * scaleMatrix;
}

void Renderable::SendMatricesToShader(GLuint shader)
{
	Graphics::SetShaderVariable(shader, "ModelMatrix", GetModelMatrix());
	Graphics::SetShaderVariable(shader, "ViewMatrix", Graphics::GetCamera()->GetViewMatrix());
	Graphics::SetShaderVariable(shader, "ProjectionMatrix", Graphics::GetCamera()->GetProjectionMatrix());
}
