#pragma once

#include <glm.hpp>
#include "Model.hpp"
#include "Texture.hpp"

class GameObject
{
private:
	// GameObject() = delete;
public:
	virtual void Start() { }
	virtual void Update() { }
	virtual void Render() { }
};