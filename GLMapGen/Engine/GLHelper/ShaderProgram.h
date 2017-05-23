#pragma once
#include <string>
#include "GL\glew.h"
#include <map>
#include <vector>
#include "ShaderOptions.h"



class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();
	static ShaderProgram createShader(std::string fragment, std::string vertex);
	void Use();
	GLuint getProgram();
	GLuint getUniformLocation(std::string uniformName);
	GLuint getAttributeLocation(std::string attributeName);

	void AddUniform(std::string name);
	void AddVertexAttribute(VertexAttribute attr);

private:

	GLuint shaderProgram;
	std::map<std::string, GLuint> mUniforms;
	std::map<std::string, GLuint> mAttributes;
	void setupUniforms(std::vector<std::string> uniformNames);
	void setupAttributes(std::vector<std::string> uniformNames);


};

