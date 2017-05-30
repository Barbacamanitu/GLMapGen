#pragma once
#include <memory>
#include <GL\glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "..\Engine\GLHelper\ShaderProgram.h"
#include "..\Engine\Camera.h"

class Wireframe
{
public:
	Wireframe();
	~Wireframe();
	std::shared_ptr<ShaderProgram> shaderProgram;
	void Initialize();
	void CreateShader();
	void Render();
	GLuint vao;
	Camera* cam;

};

