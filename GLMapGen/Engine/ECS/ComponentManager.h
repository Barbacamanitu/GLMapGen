#pragma once
#include <memory>
#include <vector>
template <class T>
typedef std::vector<T> ComponentCollection;

//Main Manager of All Component Types
template <class ...CompTypes>
class ComponentManager {
public:
private:
	std::tuple<std::vector<CompTypes>...> mComponents;
};