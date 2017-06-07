#pragma once
#include "Component.h"
#include <iostream>
class TestComponent : Component {
public:
	void doTest() {
		std::cout << "DO TEST!" << std::endl;
	}
};