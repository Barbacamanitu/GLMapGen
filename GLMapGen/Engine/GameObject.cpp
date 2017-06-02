#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject(World* world)
{
	mWorld = world;
}


GameObject::~GameObject()
{
}

World* GameObject::getWorld()
{
	return mWorld;
}
