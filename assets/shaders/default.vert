#version 460 core

layout (location = 0) in vec3 Position;
layout (location = 1) in vec2 Uv;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

out vec2 TextureCoordinates;

void main()
{
	gl_Position = ProjectionMatrix * ViewMatrix * ModelMatrix * vec4(Position, 1.0);
	TextureCoordinates = Uv;
}