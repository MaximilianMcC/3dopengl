#pragma once

#include "Graphics.hpp"

void Graphics::Shaders::LoadDefaultShaders()
{
	basic = ShaderLoader::CreateProgram("./assets/shaders/default.vert", "./assets/shaders/default.frag");
	singleColor = ShaderLoader::CreateProgram("./assets/shaders/default.vert", "./assets/shaders/singleColor.frag");
}

GLuint Graphics::Shaders::GetBasicShader() { return basic; }
GLuint Graphics::Shaders::GetSingleColorShader() { return singleColor; }