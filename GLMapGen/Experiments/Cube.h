#pragma once
#include "Engine\GLHelper\VertexArrayObject.h"
#include <memory>
#include "Engine\GLHelper\ShaderProgram.h"
class Cube
{
public:
	Cube();
	~Cube();
	void Initialize();
	void GenerateGeometry();
private:
	VertexArrayObject vao;
	GLuint vbo;
	std::shared_ptr<ShaderProgram> shaderProgram;
};

