#include "stdafx.h"
#include "Camera.h"
#include "Game.h"
Camera::Camera(Game* game)
{
	mGame = game;
	glm::vec3 cameraPos = glm::vec3(0.0f, 75.0f, 100.0f);
	
	view = glm::lookAt(
		cameraPos,
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(0.0f, 1.0f, 0.0f)
		);
	//view = glm::translate(view,cameraPos);
	proj = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 1000.0f);
}


Camera::~Camera()
{
}

void Camera::Update(double delta)
{
	float speed = delta * 50;	
	glm::vec3 movement;
	if (mGame->getInput()->getKeyboard()->isKeyPressed(GLFW_KEY_A)) {
		movement.x = -speed;
	}

	if (mGame->getInput()->getKeyboard()->isKeyPressed(GLFW_KEY_D)) {
		movement.x = speed;
	}

	if (mGame->getInput()->getKeyboard()->isKeyPressed(GLFW_KEY_W)) {
		movement.z = speed;
	}

	if (mGame->getInput()->getKeyboard()->isKeyPressed(GLFW_KEY_S)) {
		movement.z = -speed;
	}

	if (movement.length() > 0) {
		view = glm::translate(view, movement);
	}

	//Mouse
	glm::vec2 mPos = mGame->getInput()->getMouse()->getMouseDelta();
	if (mPos.length() > 1) {
		float lookSpeed = .25;
		view = glm::rotate(view, glm::radians(mPos.x*(float)delta*lookSpeed), glm::vec3(0, 1, 0));
	}
}
