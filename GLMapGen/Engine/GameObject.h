#pragma once
#include "Game.h"
class World;
class GameObject
{
public:
	typedef std::unique_ptr<GameObject> PTR;
	GameObject(World* World);
	~GameObject();
private:
	World* mWorld;
protected:
	World* getWorld();
};

