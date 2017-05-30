#include "stdafx.h"
#include "MouseInput.h"
#include <glm/vec2.hpp>
#include <glm/gtc/matrix_transform.hpp>
MouseInput::MouseInput(GLFWwindow* window)
{
	mWindow = window;
}


MouseInput::~MouseInput()
{
}

void MouseInput::lockCursor()
{
	glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void MouseInput::unlockCursor()
{
	glfwSetInputMode(mWindow, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}

glm::vec2 MouseInput::getMousePos()
{
	return previousMousePos;
}

glm::vec2 MouseInput::getMouseDelta()
{
	return mouseDelta;
}

void MouseInput::update(double delta)
{
	glm::vec2 mPos = pollMousePos();
	glm::vec2 diff = mPos - previousMousePos;
	mouseDelta = diff / (float)delta;
	previousMousePos = mPos;
}

glm::vec2 MouseInput::pollMousePos()
{
	double xpos, ypos;
	glfwGetCursorPos(mWindow, &xpos, &ypos);
	return glm::vec2(xpos, ypos);
}
