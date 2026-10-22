#pragma once

#include "SpinningCamera.hpp"
#include "SpaceShuttle.hpp"
#include <vector>

class Scene
{
private:
	std::vector<GameObject*> gameObjects;

public:
	GameObject* Add(GameObject* newGameObject)
	{
		gameObjects.push_back(newGameObject);
		newGameObject->Start();
		return newGameObject;
	}

	void Update()
	{
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Update();
		}
	}

	void Render()
	{
		for (size_t i = 0; i < gameObjects.size(); i++)
		{
			gameObjects[i]->Render();
		}
	}
};