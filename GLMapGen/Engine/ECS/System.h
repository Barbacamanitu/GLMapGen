#pragma once
#include <vector>
#include <tuple>
#include "TestComponent.h"

//A system works on a set of Component Types, which will be stored as a tuple.
template <typename ... Ts>
class System {
public:

private:
	std::tuple<Ts...> mCompCollections;
};