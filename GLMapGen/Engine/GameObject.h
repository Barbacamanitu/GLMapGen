#pragma once
#include "Game.h"
class GameObject
{
public:
	GameObject(Game* game);
	~GameObject();
private:
	Game* mGame;
protected:
	Game* getGame();
};

