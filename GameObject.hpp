#pragma once

#include <glm.hpp>

class GameObject
{
public:
	virtual void Start() { }
	virtual void Update() { }
	virtual void Render() { }
};