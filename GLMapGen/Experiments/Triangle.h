#pragma once
#include <vector>
#include <string>
#include <GL\glew.h>
#include "..\Engine\GLHelper\ShaderProgram.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "..\Engine\Camera.h"
class Triangle
{
public:
	Triangle();
	~Triangle();
	GLuint vao;
	void draw(double time);
	Camera* cam;
private:
	GLuint vbo;

	ShaderProgram prog;
	GLint uniColor;
	glm::mat4 trans;
};

