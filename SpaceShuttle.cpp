#include "SpaceShuttle.hpp"

void SpaceShuttle::Start()
{
	model = new Model("./assets/models/space-shuttle.obj");
	texture = new Texture("./assets/textures/space-shuttle.png");
	model->SetTexture(texture);
}

void SpaceShuttle::Update()
{

}

void SpaceShuttle::Render()
{
	model->Draw();
}