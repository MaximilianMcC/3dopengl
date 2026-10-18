#pragma once

#include <iostream>
#include <string>
#include <glew.h>
#include <glfw3.h>
#include "Graphics.hpp"
#include "Input.hpp"

static class Window
{
private:
	inline static float width = -1.0f;
	inline static float height = -1.0f;
	inline static std::string title = "NOTHING";

	inline static GLFWwindow* window = nullptr;
	inline static bool windowInitialized = false;
	inline static bool windowRunning = false;

	inline static float time = -1.0f;
	inline static float lastFrameTime = -1.0f;
	inline static float deltaTime = -1.0f;

public:
	/***********************************************/

	// TODO: Maybe rename this to context or glfw or something (window.window is yuck)
	static GLFWwindow* GetWindow() { return window; }

	static float GetWidth();
	static void SetWidth(float newWidth);

	static float GetHeight();
	static void SetHeight(float newHeight);

	static void SetSize(float newWidth, float newHeight);

	static std::string GetTitle();
	static void SetTitle(std::string newTitle);

	static void SetPosition(float x, float y);

	/***********************************************/

	static bool WindowHasBeenInitialized() { return windowInitialized; }

	static bool IsRunning() { return windowRunning; }

	static float GetTime() { return time; }
	static float GetDeltaTime() { return deltaTime; }

	/***********************************************/

	static void Init(std::string title, int width, int height);
	static void Init(std::string title, int size) { Init(title, size, size); }

	static void Update();

	static void Close();

	static void CleanUp();

	/***********************************************/

	static void WindowResizeCallback(GLFWwindow* window, int newWidth, int newHeight);

	static void PrintWindowErrorCallback(int error, const char* description);

	/***********************************************/
};