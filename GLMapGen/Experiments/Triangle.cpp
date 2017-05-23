#include "stdafx.h"
#include "Triangle.h"
#include "../Utility/FileIO.h"

Triangle::Triangle()
{
	GLfloat vertices[] = {
		0.0f,  0.5f, // Vertex 1 (X, Y)
		0.5f, -0.5f, // Vertex 2 (X, Y)
		-0.5f, -0.5f  // Vertex 3 (X, Y)
	};

	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo); // Generate 1 buffer


	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//Shaders
	std::string vertexSource = FileIO::ReadTextFile("Shaders/shader.vertex");
	std::string fragmentSource = FileIO::ReadTextFile("Shaders/shader.frag");
	GLchar* vSource = (GLchar*)vertexSource.c_str();
	GLchar* fSource = (GLchar*)fragmentSource.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vSource, NULL);
	glCompileShader(vertexShader);
	GLint status;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		char buffer[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
	}
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		char buffer[512];
		glGetShaderInfoLog(vertexShader, 512, NULL, buffer);
	}
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glBindFragDataLocation(shaderProgram, 0, "outColor");
	glLinkProgram(shaderProgram);


	glGetShaderiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status != GL_TRUE) {
		char buffer[512];
		glGetShaderInfoLog(shaderProgram, 512, NULL, buffer);
	}


	glUseProgram(shaderProgram);
// 	char buffer[512];
// 	glGetProgramInfoLog(shaderProgram, 512, nullptr, buffer);
	GLint posAttrib = glGetAttribLocation(shaderProgram, "position");
	glVertexAttribPointer(posAttrib, 2, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(posAttrib);
	
}


Triangle::~Triangle()
{
}

void Triangle::draw()
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}
