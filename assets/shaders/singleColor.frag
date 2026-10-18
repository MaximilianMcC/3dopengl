#version 460 core

uniform vec3 Color;

out vec4 FragmentColor;

void main()
{
	FragmentColor = vec4(Color, 1.0);
}