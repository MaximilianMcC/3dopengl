#include <iostream>
#include "Window.hpp"
#include "Graphics.hpp"
#include "Camera.hpp"
#include "Input.hpp"
#include "Model.hpp"
#include "Texture.hpp"

#include <tiny_obj_loader.h>

int main()
{
	Window::Init("kia ora", 500);

	Camera camera(glm::vec3(0.0f, 0.0f, 2.0f));
	camera.LookAt(glm::vec3(0.0f, 0.0f, 0.0f));

	Model model("./assets/models/cube.obj");
	Texture texture("./assets/textures/test.png");
	model.SetTexture(&texture);

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