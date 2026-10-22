#include <iostream>
#include "Window.hpp"
#include "Graphics.hpp"
#include "Camera.hpp"
#include "Input.hpp"
#include "Model.hpp"
#include "Texture.hpp"
#include "Scene.hpp"

int main()
{
	Window::Init("kia ora", 500);

	Camera mainCamera;
	Graphics::SetCamera(&mainCamera);

	Scene scene;
	
	SpinningCamera spinningCamera;
	spinningCamera.SetCamera(&mainCamera);
	scene.Add(&spinningCamera);

	SpaceShuttle spaceShuttle;
	scene.Add(&spaceShuttle);

	while (Window::IsRunning())
	{
		Window::Update();

		if (Input::KeyPressed(GLFW_KEY_ESCAPE)) Window::Close();
		if (Input::KeyPressed(GLFW_KEY_3)) std::cout << "Mouse position:" << Input::GetMouseX() << ", " << Input::GetMouseY() << "\n";
		scene.Update();

		Graphics::BeginDrawing();
		scene.Render();
		Graphics::EndDrawing();
	}
	
	Window::CleanUp();

	return 0;
}