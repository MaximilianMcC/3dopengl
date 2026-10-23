#pragma once

#include "Graphics.hpp"

void Graphics::Shaders::LoadDefaultShaders()
{
	basic = ShaderLoader::CreateProgram("./assets/shaders/default.vert", "./assets/shaders/default.frag");
	singleColor = ShaderLoader::CreateProgram("./assets/shaders/default.vert", "./assets/shaders/singleColor.frag");
	skybox = ShaderLoader::CreateProgram("./assets/shaders/skybox.vert", "./assets/shaders/skybox.frag");
}

GLuint Graphics::Shaders::GetBasicShader() { return basic; }
GLuint Graphics::Shaders::GetSingleColorShader() { return singleColor; }
GLuint Graphics::Shaders::GetSkyboxShader() { return skybox;  }