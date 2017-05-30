#pragma once
#include "Command.h"
#include "..\Game.h"
class CloseGameCommand : public Command {

public:
	void execute() override
	{
		mGame->End();
	}
	void setGame(Game* game) {
		mGame = game;
	}
private:
	Game* mGame;

};