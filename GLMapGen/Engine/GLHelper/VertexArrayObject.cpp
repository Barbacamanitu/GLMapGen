#include "stdafx.h"
#include "VertexArrayObject.h"


VertexArrayObject::VertexArrayObject()
{
	glGenVertexArrays(1, &vao);
}


VertexArrayObject::~VertexArrayObject()
{
}