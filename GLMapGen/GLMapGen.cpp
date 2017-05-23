// GLMapGen.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine\Game.h"
#include <memory>

int main()
{
	std::unique_ptr<Game> theGame(new Game());
	theGame->Initialize();
	theGame->Start();
    return 0;
}

