#include "stdafx.h"
#include "KeyboardInput.h"

KeyboardInput* thisKb;
KeyboardInput::KeyboardInput(GLFWwindow* window)
{
	mWindow = window;
	thisKb = this;
	glfwSetInputMode(mWindow, GLFW_STICKY_KEYS, 1);
}


KeyboardInput::~KeyboardInput()
{
}

void KeyboardInput::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (thisKb == NULL) {
		return;
	}

	if (key > 0) {
		if (action == GLFW_PRESS) {
			thisKb->handleKeypress(key, scancode, mods);
		}
	}
}

void KeyboardInput::handleKeypress(int key, int scancode, int mods)
{
	auto it = mCommands.find(key);
	if (it != mCommands.end()) {
		it->second->execute();
	}
}

void KeyboardInput::addCommand(int key, Command::PTR command)
{
	mCommands.insert(std::make_pair(key, std::move(command)));
}

bool KeyboardInput::isKeyPressed(int key)
{
	int state = glfwGetKey(mWindow, key);
	return (state == GLFW_PRESS);
}

