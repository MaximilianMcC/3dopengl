#include "Graphics.hpp"

void Graphics::Init()
{
	// Allow depth
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Allow backface culling and set the
	// winding order to counter clockwise
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CCW);

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