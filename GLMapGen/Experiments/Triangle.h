#pragma once
#include <vector>
#include <string>
#include <GL\glew.h>
class Triangle
{
public:
	Triangle();
	~Triangle();
	GLuint shaderProgram;
	GLuint vao;
	void draw();
private:
	GLuint vbo;
	std::string vertexShader;
	std::string fragShader;
};

