#include "Window.hpp"

float Window::GetWidth()
{
	return width;
}

void Window::SetWidth(float newWidth)
{
	width = newWidth;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glfwSetWindowSize(window, width, height);
}



float Window::GetHeight()
{
	return height;
}

void Window::SetHeight(float newHeight)
{
	height = newHeight;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glfwSetWindowSize(window, width, height);
}

void Window::SetSize(float newWidth, float newHeight)
{
	width = newWidth;
	height = newHeight;
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glfwSetWindowSize(window, width, height);
}

std::string Window::GetTitle()
{
	return title;
}

void Window::SetTitle(std::string newTitle)
{
	title = newTitle;
	glfwSetWindowTitle(window, title.c_str());
}

void Window::SetPosition(float x, float y)
{
	glfwSetWindowPos(window, (int)x, (int)y);
}