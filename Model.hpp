#pragma once

#include <string>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <tiny_obj_loader.h>
#include "Renderable.hpp"
#include "Vertex.hpp"
#include "texture.hpp"

class Model : public Renderable
{
private:
	GLuint vao;
	GLuint drawCount;
	Texture* texture = nullptr;

public:
	Model(std::string path);
	
	void Draw();

	// TODO: Try and make the texture be automatically loaded via mtl file
	Texture* GetTexture() { return texture; }
	void SetTexture(Texture* newTexture) { texture = newTexture; }
};