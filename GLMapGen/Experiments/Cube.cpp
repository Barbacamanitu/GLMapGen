#include "stdafx.h"
#include "Cube.h"
#include <memory>


Cube::Cube()
{
}


Cube::~Cube()
{
}

void Cube::Initialize()
{
	shaderProgram = std::make_shared<ShaderProgram>(ShaderProgram::createShader("Shaders/shader.fragment", "Shaders/shader.vertex"));
}
