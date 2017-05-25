#include "stdafx.h"
#include "Terrain.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Terrain::Terrain()
{
}


Terrain::~Terrain()
{
}

void Terrain::Generate()
{
	int size = 100;
	float subdivSize = 10.f;
	for (float x = 0; x < size; x+=subdivSize) {
		for (float y = 0; y < size; y+=subdivSize)
		{
			float centerX = x + subdivSize/2.f;
			float centerY = y + subdivSize / 2.f;
			float top = y;
			float bottom = y + subdivSize;
			float left = x;
			float right = x + subdivSize;
		}
	}
}
