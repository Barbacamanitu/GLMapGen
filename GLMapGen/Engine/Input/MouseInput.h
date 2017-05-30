#pragma once
#include <GLFW/glfw3.h>
#include <glm/common.hpp>
class MouseInput
{
public:
	MouseInput(GLFWwindow* window);
	~MouseInput();
	void lockCursor();
	void unlockCursor();
	glm::vec2 getMousePos();

	glm::vec2 getMouseDelta();
	void update(double delta);
private:
	glm::vec2 pollMousePos();

	GLFWwindow* mWindow;
	glm::vec2 previousMousePos;
	glm::vec2 mouseDelta;

};

