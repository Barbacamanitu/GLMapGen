// GLMapGen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine\Game.h"
#include <memory>
#include <GLFW/glfw3.h>

int main()
{
	glfwInit();
	std::unique_ptr<Game> theGame(new Game());
	theGame->Initialize();
	theGame->Start();
	glfwTerminate();
    return 0;
}

