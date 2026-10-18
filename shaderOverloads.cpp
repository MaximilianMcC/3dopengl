#include "Graphics.hpp"

void Graphics::SetShaderVariable(GLuint shader, std::string variableName, const glm::mat4 matrix)
{
	glUseProgram(shader);
	GLint location = glGetUniformLocation(shader, variableName.c_str());
	glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));	
}

void Graphics::SetShaderVariable(GLuint shader, std::string variableName, const glm::vec3 vector)
{
	glUseProgram(shader);
	GLint location = glGetUniformLocation(shader, variableName.c_str());
	glUniform3f(location, vector.x, vector.y, vector.z);	
}

void Graphics::SetShaderVariable(GLuint shader, std::string variableName, const glm::vec2 vector)
{
	glUseProgram(shader);
	GLint location = glGetUniformLocation(shader, variableName.c_str());
	glUniform2f(location, vector.x, vector.y);
}

void Graphics::SetShaderVariable(GLuint shader, std::string variableName, float value)
{
	glUseProgram(shader);
	GLint location = glGetUniformLocation(shader, variableName.c_str());
	glUniform1f(location, value);
}

void Graphics::SetShaderVariable(GLuint shader, std::string variableName, bool value)
{
	SetShaderVariable(shader, variableName, value ? 1 : 0);
}

void Graphics::SetShaderVariable(GLuint shader, std::string variableName, int value)
{
	glUseProgram(shader);
	GLint location = glGetUniformLocation(shader, variableName.c_str());
	glUniform1i(location, value);
}