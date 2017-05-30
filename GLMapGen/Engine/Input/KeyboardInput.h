#pragma once
#include <GLFW/glfw3.h>
#include <glm/common.hpp>
#include <map>
#include "../Commands/Command.h"
class KeyboardInput
{
public:
	KeyboardInput(GLFWwindow* window);
	~KeyboardInput();
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void handleKeypress(int key, int scancode, int mods);
	void addCommand(int key, Command::PTR command);
	bool isKeyPressed(int key);
private:
	GLFWwindow* mWindow;
	std::map<int, Command::PTR> mCommands;
};

