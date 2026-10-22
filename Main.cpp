#include <iostream>
#include "Window.hpp"
#include "Graphics.hpp"
#include "Camera.hpp"
#include "Input.hpp"
#include "Model.hpp"
#include "Texture.hpp"
#include "SpinningCamera.hpp"
#include <vector>

#include <tiny_obj_loader.h>

int main()
{
	Window::Init("kia ora", 500);
	Camera mainCamera;

	std::vector<GameObject*> gameObjects;

	SpinningCamera spinningCamera;
	spinningCamera.SetCamera(&mainCamera);
	gameObjects.push_back(&spinningCamera);
	


	Model model("./assets/models/cube.obj");
	Texture texture("./assets/textures/test.png");
	model.SetTexture(&texture);

	while (Window::IsRunning())
	{
		Window::Update();

		if (Input::KeyPressed(GLFW_KEY_ESCAPE)) Window::Close();
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Update();
		}


		
		Graphics::BeginDrawing(&mainCamera);
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Render();
		}
		model.Draw();
		Graphics::EndDrawing();
	}
	
	Window::CleanUp();

	return 0;
}