#pragma once
#include <vector>
#include "GameObject.h"
#include <memory>

class World {
public:
	typedef std::vector<std::unique_ptr<GameObject>> GameObjectList;
	GameObject* createGameObject() {
		mGameObjects.emplace_back(new GameObject(this));
		return mGameObjects.back().get();
	}

	GameObjectList const & getGameObjects() {
		return mGameObjects;
	}
private:
	std::vector<GameObject::PTR> mGameObjects;
};