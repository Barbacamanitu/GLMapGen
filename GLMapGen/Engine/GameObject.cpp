#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(Game* game)
{
	mGame = game;
}


GameObject::~GameObject()
{
}

Game* GameObject::getGame()
{
	return mGame;
}
