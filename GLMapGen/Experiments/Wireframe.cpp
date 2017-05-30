#include "stdafx.h"
#include "Wireframe.h"


Wireframe::Wireframe()
{
}


Wireframe::~Wireframe()
{
}

void Wireframe::Initialize()
{
	float vertices[] = {
		-100.f,0.f,100.f,	//Top Left
		 100.f,0.f,100.f,	//Top Right
		-100.f,0.f,-100.f,	//Bottom Left
		 100.f,0.f,-100.f	//bottom Right
	};

	GLuint elements[] = {
		0,1,2,
		3,2,1
	};

	GLuint vbo;
	GLuint ebo;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo); // Generate 1 buffer
	glGenBuffers(1, &ebo);

	glBindVertexArray(vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(elements), elements, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	CreateShader();

}

void Wireframe::CreateShader()
{
	shaderProgram.reset(new ShaderProgram());
	*shaderProgram = ShaderProgram::createShader("Shaders/terrain.fragment", "Shaders/terrain.vertex");
	shaderProgram->Use();
	shaderProgram->AddUniform("viewProj");
	shaderProgram->AddVertexAttribute(VertexAttribute("position", AttributeType::Float, 3, 3 * (sizeof(float)), 0));
}

void Wireframe::Render()
{
	

	glBindVertexArray(vao);
	shaderProgram->Use();
	glm::mat4 mat = cam->proj * cam->view;
	GLuint viewProj = shaderProgram->getUniformLocation("viewProj");
	glUniformMatrix4fv(viewProj , 1, GL_FALSE, glm::value_ptr(mat));
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindTexture(GL_TEXTURE0, 0);
	glBindVertexArray(0);
	glUseProgram(0);
}
