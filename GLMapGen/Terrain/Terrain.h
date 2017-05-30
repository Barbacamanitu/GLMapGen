#pragma once
#include <vector>
#include "..\Engine\GLHelper\ShaderProgram.h"
#include <memory>
#include <GL\glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <tuple>

class Terrain
{
public:
	Terrain(float width, float height, unsigned int horizontalSubdivisions, unsigned int verticalSubdivisions);
	Terrain(glm::vec2 size, glm::uvec2 subdivisions);
	Terrain();

	void SetSize(float width, float height);
	void SetSize(glm::vec2 size);

	void SetSubdivisions(unsigned int horizontal, unsigned int vertical);
	void SetSubdivisions(glm::uvec2 subdivisions);
	~Terrain();
	std::shared_ptr<ShaderProgram> shaderProgram;
	void CreateVertices();
	void CreateElements();
	void CreateShader();
private:
	std::vector<glm::vec3> vertices;
	std::vector<float> vertexFloats;
	std::vector<GLuint> elements;

	glm::vec2 mSize;
	glm::uvec2 mSubdivisions;

	
};

