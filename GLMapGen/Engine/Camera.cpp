#include "stdafx.h"
#include "Camera.h"
#include <SFML/Graphics.hpp>

Camera::Camera()
{
	view = glm::lookAt(
		glm::vec3(1.2f, 1.2f, 1.2f),
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 0.0f, 1.0f)
		);
	proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 1.0f, 10.0f);
}


Camera::~Camera()
{
}

void Camera::Update(double delta)
{
	float speed = delta * 5;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{

		/*view = glm::rotate(
			view,
			-speed * glm::radians(180.0f),
			glm::vec3(0.0f, 0.0f, 1.0f)
			);*/
		view= glm::translate(view, glm::vec3(-speed, 0.f, 0.f));
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{

		/*view = glm::rotate(
			view,
			speed * glm::radians(180.0f),
			glm::vec3(0.0f, 0.0f, 1.0f)
			);*/
		view = glm::translate(view, glm::vec3(speed, 0.f, 0.f));
	}
	
}
