#pragma once
#include "GL\glew.h"
#include <string>
#include <map>


class VertexArrayObject
{
public:
	VertexArrayObject();
	~VertexArrayObject();
	void bind() {
		glBindVertexArray(vao);
	}
private:
	GLuint vao;
};

