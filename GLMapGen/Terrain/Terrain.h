#pragma once
#include <vector>
#include "..\Engine\GLHelper\ShaderProgram.h"
#include <memory>
class Terrain
{
public:
	Terrain();
	~Terrain();
	std::shared_ptr<ShaderProgram> shaderProgram;
private:
	std::vector<float> vertices;
	void Generate();
	
};

