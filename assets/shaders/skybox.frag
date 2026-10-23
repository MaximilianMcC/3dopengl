#version 460 core

in vec3 TextureDirection;

uniform samplerCube Texture0;

out vec4 FragmentColor;

void main()
{
	FragmentColor = texture(Texture0, TextureDirection);
}