#include "Input.hpp"

void Input::Init()
{
	// Have the arrays empty
	// TODO: Do this when they're made
	for (int i = 0; i < GLFW_KEY_LAST; i++)
	{
		keysDownPreviously[i] = 0;
		keysDownCurrently[i] = 0;
	}

	// Register the mouse movement callback
	glfwSetCursorPosCallback(Window::GetWindow(), CursorPositionCallback);
}

void Input::Capture()
{
	// Loop over every key and capture its current state
	//? space is the first key
	for (int key = GLFW_KEY_SPACE; key <= GLFW_KEY_LAST; key++)
	{
		// First save its old state
		keysDownPreviously[key] = keysDownCurrently[key];

		// Get the new state
		keysDownCurrently[key] = glfwGetKey(Window::GetWindow(), key);
	}

	// Loop over every mouse button and capture its current state
	// TODO: Use callback maybe
	for (int button = 0; button <= GLFW_MOUSE_BUTTON_LAST; button++)
	{
		// First save its old state
		buttonsDownPreviously[button] = buttonsDownCurrently[button];

		// Get the new state
		buttonsDownCurrently[button] = glfwGetMouseButton(Window::GetWindow(), button);
	}
}

bool Input::AnyKeyDown()
{
	for (int key = 0; key < GLFW_KEY_LAST; key++)
	{
		if (KeyHeldDown(key)) return true;
	}

	return false;
}

bool Input::AnyKeyPressed()
{
	for (int key = 0; key < GLFW_KEY_LAST; key++)
	{
		if (KeyPressed(key)) return true;
	}

	return false;
}

bool Input::AnyKeyReleased()
{
	for (int key = 0; key < GLFW_KEY_LAST; key++)
	{
		if (KeyReleased(key)) return true;
	}

	return false;
}

void Input::ToggleWithKey(bool &boolean, int key)
{
	if (KeyPressed(key)) boolean = !boolean;
}

void Input::CursorPositionCallback(GLFWwindow *window, double x, double y)
{
	mouseX = (float)x;
	mouseY = (float)y;
}
