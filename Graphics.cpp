#include "Graphics.hpp"

// TODO: Put this in its own file like tiny obj loader
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

void Graphics::Init()
{
	// Allow depth
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Allow backface culling and set the
	// winding order to counter-clockwise
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

	// Don't have textures upside down
	stbi_set_flip_vertically_on_load(true);

	// Enable transparent textures
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// Load the default shaders
	Shaders::LoadDefaultShaders();
}

void Graphics::BeginDrawing(Camera* camera)
{
	currentlyDrawing = true;

	// Use our camera
	currentCamera = camera;

	// Clear the screen and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Graphics::EndDrawing()
{
	currentlyDrawing = false;

	// Stop using the camera
	currentCamera = nullptr;

	// Rotate in our other buffer
	glfwSwapBuffers(Window::GetWindow());

	// Turn off our previous shader just to be safe
	glUseProgram(0);
}

void Graphics::SetWireframeModeEnabled(bool enabled)
{
	wireframeModeEnabled = enabled;
	if (wireframeModeEnabled) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}