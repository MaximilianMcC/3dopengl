#version 460 core

layout (location = 0) in vec3 Position;

uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

out vec3 TextureDirection;

void main()
{
	TextureDirection = Position;
	gl_Position = ProjectionMatrix * ViewMatrix * vec4(Position, 1.0);
}