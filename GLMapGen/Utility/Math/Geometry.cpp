#include "stdafx.h"
#include "Geometry.h"


Geometry::Geometry()
{
}


Geometry::~Geometry()
{
}

unsigned int Geometry::flattenArrayIndex(int x, int y, int arraywidth)
{
	return (y * arraywidth) + x;
}

std::tuple<unsigned int, unsigned int> Geometry::expandArrayIndex(int index, int arraywidth)
{
	unsigned int y = index / arraywidth;
	unsigned int x = index % arraywidth;
	return std::tuple<unsigned int, unsigned int>(x, y);
}
