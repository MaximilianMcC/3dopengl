#include "SpaceShuttle.hpp"

void SpaceShuttle::Start()
{
	model = new Model("./assets/models/space-shuttle.obj");
	texture = new Texture("./assets/textures/space-shuttle.png");
	model->SetTexture(texture);
}

void SpaceShuttle::Update()
{
	FlyAround();

	// If we press R then reset position to the centre of the world
	if (Input::KeyPressed(GLFW_KEY_R)) model->SetPosition(glm::vec3(0.0f));
}

void SpaceShuttle::FlyAround()
{
	Camera* camera = Graphics::GetCamera();

	// Move in the same way the camera faces
	glm::vec3 movementInput = Input::GetWasdQeInput();
	glm::vec3 rightMovement = camera->GetRight() * movementInput.x;
	glm::vec3 forwardMovement = camera->GetForward() * movementInput.z;
	glm::vec3 upMovement = camera->GetUp() * movementInput.y;

	glm::vec3 movement = ((forwardMovement + rightMovement + upMovement) * speed) * Window::GetDeltaTime();
	model->AddPosition(movement);
}


void SpaceShuttle::Render()
{
	model->Draw();
}