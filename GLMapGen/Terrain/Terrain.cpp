#include "stdafx.h"
#include "Terrain.h"
#include "..\Utility\Math\Geometry.h"

Terrain::Terrain(glm::vec2 size, glm::uvec2 subdivisions)
{
	SetSize(size);
	SetSubdivisions(subdivisions);
}

Terrain::Terrain(float width, float height, unsigned int horizontalSubdivisions, unsigned int verticalSubdivisions)
{
	SetSize(width, height);
	SetSubdivisions(horizontalSubdivisions, verticalSubdivisions);
}


Terrain::Terrain()
{
	SetSize(100, 100);
	SetSubdivisions(10, 10);
}

void Terrain::SetSize(float width, float height)
{
	mSize = glm::vec2(width, height);
}

void Terrain::SetSize(glm::vec2 size)
{
	mSize = size;
}

void Terrain::SetSubdivisions(unsigned int horizontal, unsigned int vertical)
{
	mSubdivisions = glm::uvec2(horizontal, vertical);
}

void Terrain::SetSubdivisions(glm::uvec2 subdivisions)
{
	mSubdivisions = subdivisions;
}

Terrain::~Terrain()
{
}


void Terrain::CreateVertices()
{
	int vertexCount = (mSubdivisions.x + 1) * (mSubdivisions.y + 1);
	vertices.clear();
	vertices.resize(vertexCount);

	float subdivWidth = (float)mSize.x / (float)mSubdivisions.x;
	float subdivHeight = (float)mSize.y / (float)mSubdivisions.y;
	float halfWidth = (float)mSize.x / 2.f;
	float halfHeight = (float)mSize.y / 2.f;

	for (int y = 0; y <= mSubdivisions.y; y++) {
		float yy = (subdivHeight * (float)y) - halfHeight;
		for (int x = 0; x <= mSubdivisions.x; x++) {
			float xx = (subdivWidth * (float)x) - halfWidth;
			int index = Geometry::flattenArrayIndex(x, y, mSubdivisions.x+1);
			vertices[index] = glm::vec3(xx, yy, 0);
		}
	}

	int a = 1;
}

void Terrain::CreateElements()
{
		for (int y = 0; y < mSubdivisions.y; y++) {
			bool isUp = (y % 2 == 0);
			for (int x = 0; x < mSubdivisions.x; x++)
			{
				isUp = !isUp;
				//Compute indices of 4 corners to current square
				int TL = Geometry::flattenArrayIndex(x, y, mSubdivisions.x + 1);
				int TR = TL + 1;
				int BL = Geometry::flattenArrayIndex(x, y+1, mSubdivisions.x + 1);
				int BR = BL + 1;

				if (isUp) {
					elements.push_back(TL);
					elements.push_back(TR);
					elements.push_back(BL);
					elements.push_back(BR);
					elements.push_back(BL);
					elements.push_back(TR);
				} else {
					elements.push_back(TR);
					elements.push_back(TL);
					elements.push_back(BR);
					elements.push_back(BL);
					elements.push_back(BR);
					elements.push_back(TL);
				}
			}
		}
}

void Terrain::CreateShader()
{
	shaderProgram.reset(new ShaderProgram());
	*shaderProgram = ShaderProgram::createShader("Shaders/terrain.fragment", "Shaders/terrain.vertex");
	shaderProgram->Use();
	shaderProgram->addUniform("viewProj");
	shaderProgram->enableVertexAttribute(VertexAttribute("position",3,GL_FLOAT,3,0));
	int a = 1;
}
