#pragma once
#include <string>
#include "GL\glew.h"
#include <map>
#include <vector>
#include <glm\vec3.hpp>
#include <glm\vec2.hpp>
#include <glm\mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

struct VertexAttribute {
	std::string Name;
	int Stride;
	int Offset;
	int Components;
	int Type;
	GLuint Location;


	VertexAttribute(const std::string& name, int components, int type, int stride, int offset) {
		Name = name;
		Stride = stride;
		Offset = offset;
		Components = components;
		Type = type;
	}
	VertexAttribute() {

	}
};

class ShaderProgram
{
public:
	ShaderProgram();
	~ShaderProgram();
	static ShaderProgram createShader(std::string fragment, std::string vertex);
	void Use();
	GLuint getProgram();
	GLuint getUniformLocation(std::string uniformName);

	void addUniform(std::string name);

	void enableVertexAttribute(VertexAttribute attr);

	//Generic Set Uniform function.
	//Gets uniform position, then delegates to specialized
	//uniform functions based on type.
	template <class T>
	void setUniform(const std::string& name, T& val) {
		GLuint pos = getUniformLocation(name);
		setUniformVal(pos, val);
	};
	

private:
	template <class T>
	void setUniformVal(GLuint uniformPos, T& val) {};

	template <>
	void setUniformVal<glm::vec2>(GLuint uniformPos, glm::vec2& val) {
		glUniform2f(uniformPos, val.x, val.y);
	};

	template <>
	void setUniformVal<glm::vec3>(GLuint uniformPos, glm::vec3& val) {
		glUniform3f(uniformPos, val.x, val.y, val.y);
	};

	template <>
	void setUniformVal<glm::mat4>(GLuint uniformPos, glm::mat4& val) {
		glUniformMatrix4fv(uniformPos, 1, GL_FALSE, glm::value_ptr(val));
	};

	GLuint shaderProgram;
	std::map<std::string, GLuint> mUniforms;
	std::map<std::string, GLuint> mAttributes;


};

