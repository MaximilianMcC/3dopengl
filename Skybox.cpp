#include "Skybox.hpp"

#include <iostream>
#include <filesystem>
#include <algorithm>
#include <cctype>
#include <stb_image.h>
#include "Camera.hpp"

Skybox::Skybox(std::string skyboxDirectoryPath)
{
	GenerateTexture(skyboxDirectoryPath);
	GenerateMesh();
}

void Skybox::GenerateTexture(std::string skyboxDirectoryPath)
{
	const unsigned int textureCount = 6;

	// Make the opengl texture
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);

	stbi_set_flip_vertically_on_load(false);

	// Loop over every file in the skybox directory
	unsigned int loadedTextures = 0;
	for (const auto& thing : std::filesystem::directory_iterator(skyboxDirectoryPath))
	{
		// Check for if we've got a file
		if (thing.is_regular_file() == false) continue;

		// Get the file name and make it lowercase
		std::string fileName = thing.path().filename().string();
		std::transform(fileName.begin(), fileName.end(), fileName.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });

		// Get what bit of the cubemap we're looking at (based on filename)
		GLenum side = 0;
		if (fileName.rfind("right", 0) == 0) side = GL_TEXTURE_CUBE_MAP_POSITIVE_X;
		else if (fileName.rfind("left", 0) == 0) side = GL_TEXTURE_CUBE_MAP_NEGATIVE_X;
		else if (fileName.rfind("top", 0) == 0) side = GL_TEXTURE_CUBE_MAP_POSITIVE_Y;
		else if (fileName.rfind("bottom", 0) == 0) side = GL_TEXTURE_CUBE_MAP_NEGATIVE_Y;
		else if (fileName.rfind("front", 0) == 0) side = GL_TEXTURE_CUBE_MAP_POSITIVE_Z;
		else if (fileName.rfind("back", 0) == 0) side = GL_TEXTURE_CUBE_MAP_NEGATIVE_Z;
		if (side == 0) continue;

		// Load the actual image
		int width, height, components;
		unsigned char* data = stbi_load(thing.path().string().c_str(), &width, &height, &components, 0);
		if (data == nullptr)
		{
			std::cout << "Issue whilst loading skybox (couldn't load " << thing.path() << ")" << std::endl;
			exit(1);
		}

		// Figure out if we have alpha included
		GLenum loadedComponents = (components == 4) ? GL_RGBA : GL_RGB;

		// Populate the texture
		glTexImage2D(side, 0, loadedComponents, width, height, 0, loadedComponents, GL_UNSIGNED_BYTE, data);

		loadedTextures++;
		stbi_image_free(data);
	}

	// Turn this back on for regular textures
	stbi_set_flip_vertically_on_load(true);

	// Make sure we have all the textures needed
	if (loadedTextures != textureCount)
	{
		std::cout << "Issue whilst loading skybox ";
		std::cout << ((loadedTextures > textureCount) ? "(too many textures)" : "(not enough textures)");
		std::cout << std::endl;
		exit(1);
	}

	// Change all the settings
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glGenerateMipmap(GL_TEXTURE_CUBE_MAP);

	// Unbind (finished)
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void Skybox::GenerateMesh()
{
	// TODO: Put this somewhere else
	const float vertices[] = {
		-1.0f,  1.0f, -1.0f,  -1.0f, -1.0f, -1.0f,   1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,   1.0f,  1.0f, -1.0f,  -1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,  -1.0f, -1.0f, -1.0f,  -1.0f,  1.0f, -1.0f,
		-1.0f,  1.0f, -1.0f,  -1.0f,  1.0f,  1.0f,  -1.0f, -1.0f,  1.0f,

		 1.0f, -1.0f, -1.0f,   1.0f, -1.0f,  1.0f,   1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,   1.0f,  1.0f, -1.0f,   1.0f, -1.0f, -1.0f,

		-1.0f, -1.0f,  1.0f,  -1.0f,  1.0f,  1.0f,   1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,   1.0f, -1.0f,  1.0f,  -1.0f, -1.0f,  1.0f,

		-1.0f,  1.0f, -1.0f,   1.0f,  1.0f, -1.0f,   1.0f,  1.0f,  1.0f,
		 1.0f,  1.0f,  1.0f,  -1.0f,  1.0f,  1.0f,  -1.0f,  1.0f, -1.0f,

		-1.0f, -1.0f, -1.0f,  -1.0f, -1.0f,  1.0f,   1.0f, -1.0f, -1.0f,
		 1.0f, -1.0f, -1.0f,  -1.0f, -1.0f,  1.0f,   1.0f, -1.0f,  1.0f
	};

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Skybox::Render()
{
	GLuint shader = Graphics::Shaders::GetSkyboxShader();
	Camera* camera = Graphics::GetCamera();

	// Get the translation out of the view matrix so the skybox
	// stays centred on the camera and only rotates with it
	glm::mat4 viewMatrix = glm::mat4(glm::mat3(camera->GetViewMatrix()));

	// Don't write depth so everything else draws over us, and
	// turn culling off since we're inside the cube
	glDepthMask(GL_FALSE);
	glDisable(GL_CULL_FACE);

	glUseProgram(shader);

	// TODO: do via renderable class
	Graphics::SetShaderVariable(shader, "ViewMatrix", viewMatrix);
	Graphics::SetShaderVariable(shader, "ProjectionMatrix", camera->GetProjectionMatrix());

	// Set the texture and draw it 
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, texture);
	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 36);

	// Put everything back how we found it
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	glUseProgram(0);

	glEnable(GL_CULL_FACE);
	glDepthMask(GL_TRUE);
}