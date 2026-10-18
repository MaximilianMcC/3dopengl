#pragma once
#include <glm.hpp>
#include <glew.h>
#include <glfw3.h>
#include "Window.hpp"

class Input
{
public:
	static void Init();
	static void Capture();

	static bool KeyHeldDown(int key) { return keysDownCurrently[key]; }
	static bool KeyPressed(int key) { return keysDownCurrently[key] == true && keysDownPreviously[key] == false; }
	static bool KeyReleased(int key) { return keysDownCurrently[key] == false && keysDownPreviously[key] == true; }
	static bool AnyKeyDown();
	static bool AnyKeyPressed();
	static bool AnyKeyReleased();

	static bool MouseButtonDown(int button) { return buttonsDownCurrently[button]; }
	static bool MouseClicked(int button) { return buttonsDownCurrently[button] == true && buttonsDownPreviously[button] == false; }
	static bool MouseReleased(int button) { return buttonsDownCurrently[button] == false && buttonsDownPreviously[button] == true; }

private:
	inline static bool keysDownCurrently[GLFW_KEY_LAST + 1];
	inline static bool keysDownPreviously[GLFW_KEY_LAST + 1];

	inline static bool buttonsDownCurrently[GLFW_MOUSE_BUTTON_LAST + 1];
	inline static bool buttonsDownPreviously[GLFW_MOUSE_BUTTON_LAST + 1];
};