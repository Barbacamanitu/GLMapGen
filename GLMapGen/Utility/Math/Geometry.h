#pragma once
#include <tuple>
class Geometry
{
public:
	Geometry();
	~Geometry();
	static unsigned int flattenArrayIndex(int x, int y, int arraywidth);
	static std::tuple<unsigned int,unsigned int> expandArrayIndex(int index, int arraywidth);
};

