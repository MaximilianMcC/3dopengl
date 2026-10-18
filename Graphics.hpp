#pragma once

#include <string>
#include <glew.h>
#include <glfw3.h>
#include <gtc/type_ptr.hpp>
#include "Window.hpp"
#include "Camera.hpp"
#include "ShaderLoader.h"

static class Graphics
{
private:
	inline static Camera* currentCamera = nullptr;
	inline static bool currentlyDrawing = false;

public:
	static void Init();

	static void BeginDrawing(Camera* camera);
	static void EndDrawing();

	static Camera* GetCurrentCamera() { return currentCamera; }
	static bool IsCurrentlyDrawing() { return currentlyDrawing; }

	static void SetShaderVariable(GLuint shader, std::string variableName, const glm::mat4 matrix);
	static void SetShaderVariable(GLuint shader, std::string variableName, const glm::vec3 vector);
	static void SetShaderVariable(GLuint shader, std::string variableName, const glm::vec2 vector);
	static void SetShaderVariable(GLuint shader, std::string variableName, float value);
	static void SetShaderVariable(GLuint shader, std::string variableName, bool value);
	static void SetShaderVariable(GLuint shader, std::string variableName, int value);

	// TODO: Make a custom colour class then this just converts the colour to a vec4 or whatever
	// static void SetShaderVariable(GLuint shader, std::string variableName, Color color);

	static class Shaders
	{
	public:
		static void LoadDefaultShaders();

		static GLuint GetBasicShader();
		static GLuint GetSingleColorShader();

	private:
		static inline GLuint basic;
		static inline GLuint singleColor;
	};
};