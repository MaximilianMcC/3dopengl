#pragma once

// Library Includes
#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <unordered_map>

class ShaderLoader
{
public:
	static GLuint CreateProgram(const char* VertexShaderFilename, const char* FragmentShaderFilename);

	// TODO: Make this private and add a getter
	inline static std::unordered_map<const char*, GLint> LoadedShaders;

private:
	ShaderLoader(void) {};
	~ShaderLoader(void) {};


	static GLuint CreateShader(GLenum shaderType, const char* shaderName);
	static std::string ReadShaderFile(const char* filename);
	static void PrintErrorDetails(bool isShader, GLuint id, const char* name);
};
