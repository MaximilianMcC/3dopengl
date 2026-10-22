#pragma once

#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <tiny_obj_loader.h>
#include "Renderable.hpp"
#include "Vertex.hpp"

class Model : public Renderable
{
private:
	GLuint vao;
	GLuint drawCount;

public:
	Model(std::string path);
	void Draw();
};