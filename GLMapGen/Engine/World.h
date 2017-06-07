#pragma once
#include <vector>
#include "ECS/ComponentCollection.h"
#include "ECS/System.h"
#include "ECS/TestComponent.h"

class World {
public:
	World() {
		TestComponent* tComp = testComponents.createComponent();
		testSystem.addCollection(&testComponents);
	}
private:
	ComponentCollection<TestComponent> testComponents;
	System<TestComponent> testSystem;
};