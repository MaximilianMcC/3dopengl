#include <iostream>
#include "Window.hpp"
#include "Graphics.hpp"
#include "Camera.hpp"
#include "Input.hpp"
#include "Model.hpp"

#include <tiny_obj_loader.h>

int main()
{
	Window::Init("kia ora", 500);

	Camera camera(glm::vec3(0.0f, 0.0f, 10.0f));

	Model model("./assets/models/cube.obj");

	while (Window::IsRunning())
	{
		Window::Update();

		if (Input::KeyPressed(GLFW_KEY_ESCAPE)) Window::Close();

		Graphics::BeginDrawing(&camera);
		model.Draw();
		Graphics::EndDrawing();
	}
	
	Window::CleanUp();

	return 0;
}