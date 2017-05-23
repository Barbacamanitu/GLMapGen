#include "stdafx.h"
#include "Triangle.h"
#include "../Utility/FileIO.h"


Triangle::Triangle()
{
	float vertices[] = {
		-0.5f,  0.5f, 1.0f, 0.0f, 0.0f, // Top-left
		0.5f,  0.5f, 0.0f, 1.0f, 0.0f, // Top-right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // Bottom-right
		-0.5f, -0.5f, 1.0f, 1.0f, 1.0f  // Bottom-left
	};
	GLuint elements[] = {
		0, 1, 2,
		2, 3, 0
	};
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo); // Generate 1 buffer

	GLuint ebo;
	glGenBuffers(1, &ebo);


	
	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	

	prog = ShaderProgram::createShader("Shaders/shader.fragment", "Shaders/shader.vertex");
	prog.Use();
	prog.AddUniform("trans");
	prog.AddVertexAttribute(VertexAttribute("position",AttributeType::Float,2,5*(sizeof(float)),0));
	prog.AddVertexAttribute(VertexAttribute("color", AttributeType::Float, 3, 5 * (sizeof(float)), 2 * (sizeof(float))));

	
}


Triangle::~Triangle()
{
}

void Triangle::draw(double time)
{
	//glUniform3f(prog.getUniformLocation("triangleColor"), (sin(time * 4.0f) + 1.0f) / 2.0f, 0.0f, 0.0f);
	//glDrawArrays(GL_TRIANGLES, 0, 3);
	trans = glm::rotate(
		glm::mat4(),
		(float)(glm::radians(180.0f) * time),
		glm::vec3(0.0f, 0.0f, 1.0f)
		);
	glm::mat4 mat = cam->proj * cam->view * trans;
	glUniformMatrix4fv(prog.getUniformLocation("trans"), 1, GL_FALSE, glm::value_ptr(mat));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
