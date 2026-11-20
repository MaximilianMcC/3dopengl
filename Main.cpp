#include <iostream>
#include "Window.hpp"
#include "Graphics.hpp"
#include "Camera.hpp"
#include "EditorCamera.hpp"
#include "Input.hpp"
#include "Model.hpp"
#include "Texture.hpp"
#include "Scene.hpp"
#include "Skybox.hpp"

int main()
{
	Window::Init("kia ora", 500);

	Camera mainCamera;
	Graphics::SetCamera(&mainCamera);

	// Skybox skybox("./assets/textures/Corona");

	Scene scene;
	
	EditorCamera editorCamera;
	editorCamera.SetCamera(&mainCamera);
	scene.Add(&editorCamera);

	SpaceShuttle spaceShuttle;
	scene.Add(&spaceShuttle);

	while (Window::IsRunning())
	{
		Window::Update();
		if (Input::KeyPressed(GLFW_KEY_ESCAPE)) Window::Close();
		
		scene.Update();

		Graphics::BeginDrawing();
		// skybox.Render();
		scene.Render();
		Graphics::EndDrawing();
	}
	
	Window::CleanUp();

	return 0;
}