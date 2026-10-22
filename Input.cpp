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

glm::vec2 Input::GetWasdInput()
{
	// Get input
	glm::vec2 input = glm::vec2(
		-KeyHeldDown(GLFW_KEY_D) + KeyHeldDown(GLFW_KEY_A),
		-KeyHeldDown(GLFW_KEY_S) + KeyHeldDown(GLFW_KEY_W)
	);

	// Normalise
	if (glm::length(input) > 0) input = glm::normalize(input);

	return input;
}

glm::vec3 Input::GetWasdQeInput()
{
	// Get input
	// TODO: Don't rewrite
	glm::vec3 input = glm::vec3(
		-KeyHeldDown(GLFW_KEY_D) + KeyHeldDown(GLFW_KEY_A),
		-KeyHeldDown(GLFW_KEY_Q) + KeyHeldDown(GLFW_KEY_E),
		-KeyHeldDown(GLFW_KEY_S) + KeyHeldDown(GLFW_KEY_W)
	);

	// Normalise
	// TODO: Don't rewrite
	if (glm::length(input) > 0) input = glm::normalize(input);

	return input;
}

void Input::SetMouseVisible(bool visible)
{
	mouseCursorVisible = visible;
	int cursorMode = mouseCursorVisible ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_HIDDEN;
	glfwSetInputMode(Window::GetWindow(), GLFW_CURSOR, cursorMode);
}

void Input::CursorPositionCallback(GLFWwindow *window, double x, double y)
{
	mouseX = (float)x;
	mouseY = (float)y;
}
