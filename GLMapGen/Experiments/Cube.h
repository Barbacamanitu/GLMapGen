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
private:
	VertexArrayObject vao;
	std::shared_ptr<ShaderProgram> shaderProgram;
};

