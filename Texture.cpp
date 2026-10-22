#include "Texture.hpp"

Texture::Texture(std::string filePath)
{
	// Load the texture's data
	int components;
	unsigned char* data = stbi_load(filePath.c_str(), &width, &height, &components, 0);

	// Make a new opengl texture
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	// Set up the UVs to repeat
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// Figure out if we have alpha included
	GLint loadedComponents = (components == 4) ? GL_RGBA : GL_RGB;

	// Add the data to the texture and generate mipmaps
	glTexImage2D(GL_TEXTURE_2D, 0, loadedComponents, width, height, 0, loadedComponents, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Clean up
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);
}