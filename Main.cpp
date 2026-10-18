#include <iostream>
#include "Window.hpp"
#include "Graphics.hpp"
#include "Camera.hpp"
#include "Input.hpp"

int main()
{
	Window::Init("kia ora rua", 500);

	Camera camera(glm::vec3(0.0f, 0.0f, 10.0f));

	while (Window::IsRunning())
	{
		Window::Update();

		if (Input::KeyPressed(GLFW_KEY_ESCAPE)) Window::Close();

		Graphics::BeginDrawing(&camera);
		Graphics::EndDrawing();
	}
	
	Window::CleanUp();

	return 0;
}