#include "stdafx.h"
#include "ShaderProgram.h"
#include "..\..\Utility\FileIO.h"
#include "GL\glew.h"
#include <memory>
#include <iostream>


ShaderProgram::ShaderProgram()
{
}


ShaderProgram::~ShaderProgram()
{
}

ShaderProgram ShaderProgram::createShader(std::string fragment, std::string vertex)
{
	ShaderProgram prog;
	std::string fSource = FileIO::ReadTextFile(fragment);
	std::string vSource = FileIO::ReadTextFile(vertex);
	GLchar* fragmentSource = (GLchar*)fSource.c_str();
	GLchar* vertexSource = (GLchar*)vSource.c_str();
	
	char infoLog[512];
	GLint status;

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexSource, NULL);
	glCompileShader(vertexShader);
	
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "Shader Compilation Error(Vertex): " << infoLog << std::endl;
	}
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Shader Compilation Error(Fragment): " << infoLog << std::endl;
	}
	prog.shaderProgram = glCreateProgram();
	glAttachShader(prog.shaderProgram, vertexShader);
	glAttachShader(prog.shaderProgram, fragmentShader);
	//glBindFragDataLocation(prog.shaderProgram, 0, "outColor");


	glLinkProgram(prog.shaderProgram);
	glGetShaderiv(prog.shaderProgram, GL_LINK_STATUS, &status);
	if (status != GL_TRUE) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "Shader Link Error: " << infoLog << std::endl;
	}
	return prog;
}

void ShaderProgram::Use()
{
	glUseProgram(shaderProgram);
}

GLuint ShaderProgram::getProgram()
{
	return shaderProgram;
}

GLuint ShaderProgram::getUniformLocation(std::string uniformName)
{
	return mUniforms.at(uniformName);
}

GLuint ShaderProgram::getAttributeLocation(std::string attributeName)
{
	return mAttributes.at(attributeName);
}

void ShaderProgram::AddUniform(std::string name)
{
	GLuint uniformLocation = glGetUniformLocation(shaderProgram,name.c_str());
	mUniforms.insert(std::make_pair(name, uniformLocation));
}

void ShaderProgram::AddVertexAttribute(VertexAttribute attr)
{
	GLuint attributeLocation = glGetAttribLocation(shaderProgram, attr.name.c_str());
	mAttributes.insert(std::make_pair(attr.name, attributeLocation));
	glVertexAttribPointer(attributeLocation, attr.components, GL_FLOAT, GL_FALSE, attr.stride,(void*)attr.offset);
	glEnableVertexAttribArray(attributeLocation);
}


