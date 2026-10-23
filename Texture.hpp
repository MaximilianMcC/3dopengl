#pragma once

#include <string>
#include <stb_image.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <glew.h>
#include <glfw3.h>

class Texture
{
private:
	GLuint texture;

	int width;
	int height;

	bool loaded = false;
public:
	Texture() { }
	Texture(std::string filePath);

	bool IsLoaded() { return loaded; }

	void SetWidth(float newWidth) { width = (int)newWidth; }
	void SetHeight(float newHeight) { height = (int)newHeight; }

	GLuint GetTexture() { return texture; }
};