#include "stdafx.h"
#include "Input.h"


Input::Input(GLFWwindow* window)
{
	mWindow = window;
	mouseInput.reset(new MouseInput(window));
	keyboardInput.reset(new KeyboardInput(window));
	glfwSetKeyCallback(mWindow, KeyboardInput::key_callback);
}


Input::~Input()
{
}

MouseInput* Input::getMouse()
{
	return mouseInput.get();
}

KeyboardInput* Input::getKeyboard()
{
	return keyboardInput.get();
}

void Input::update(double delta)
{
	mouseInput->update(delta);
}

void Input::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		keyboardInput->handleKeypress(key, scancode, mods);
	}
}
