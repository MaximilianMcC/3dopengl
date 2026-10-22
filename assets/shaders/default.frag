#version 460 core

in vec2 TextureCoordinates;

uniform sampler2D Texture0;

out vec4 FragmentColor;

void main()
{
	FragmentColor = texture(Texture0, TextureCoordinates);
}