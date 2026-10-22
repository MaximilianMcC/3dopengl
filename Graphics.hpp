#pragma once

#include <string>
#include <glew.h>
#include <glfw3.h>
#include <gtc/type_ptr.hpp>
#include "Window.hpp"
#include "ShaderLoader.h"

class Camera;

class Graphics
{
private:
	inline static Camera* currentCamera = nullptr;

	inline static bool currentlyDrawing = false;
	inline static bool wireframeModeEnabled = false;

public:
	static void Init();

	static void BeginDrawing();
	static void EndDrawing();

	static void SetCamera(Camera* newCamera) { currentCamera = newCamera; }
	static Camera* GetCamera() { return currentCamera; }

	static bool IsCurrentlyDrawing() { return currentlyDrawing; }

	static bool WireframeModeEnabled() { return wireframeModeEnabled; }
	static void SetWireframeModeEnabled(bool enabled);

	static void SetShaderVariable(GLuint shader, std::string variableName, const glm::mat4 matrix);
	static void SetShaderVariable(GLuint shader, std::string variableName, const glm::vec3 vector);
	static void SetShaderVariable(GLuint shader, std::string variableName, const glm::vec2 vector);
	static void SetShaderVariable(GLuint shader, std::string variableName, float value);
	static void SetShaderVariable(GLuint shader, std::string variableName, bool value);
	static void SetShaderVariable(GLuint shader, std::string variableName, int value);

	// TODO: Make a custom colour class then this just converts the colour to a vec4 or whatever
	// static void SetShaderVariable(GLuint shader, std::string variableName, Color color);

	class Shaders
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