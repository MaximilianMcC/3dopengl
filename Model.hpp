#pragma once

#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include "Renderable.hpp"

class Model : public Renderable
{
private:
	GLuint Vao;
	GLuint DrawCount;
	int drawType;

public:
	Model(std::string path);
	void Draw();
};