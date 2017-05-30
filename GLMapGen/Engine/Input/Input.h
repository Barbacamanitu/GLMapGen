#pragma once
#include "GLFW\glfw3.h"
#include <memory>
#include "MouseInput.h"
#include "KeyboardInput.h"
class Input
{
public:
	Input(GLFWwindow* window);
	~Input();
	MouseInput* getMouse();
	KeyboardInput* getKeyboard();
	void update(double delta);
private:
	GLFWwindow* mWindow;
	std::unique_ptr<MouseInput> mouseInput;
	std::unique_ptr<KeyboardInput> keyboardInput;
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

};

