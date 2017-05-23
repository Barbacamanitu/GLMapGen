#pragma once
#include <vector>
enum AttributeType {
	Float
};

struct VertexAttribute {
	std::string name;
	AttributeType type;
	unsigned int components;
	unsigned int stride;
	unsigned int offset;

	VertexAttribute(std::string Name, AttributeType Type, unsigned int Components, unsigned int Stride, unsigned int Offset)
	{
		name = Name;
		components = Components;
		stride = Stride;
		offset = Offset;
	}

	VertexAttribute() {

	}
};

