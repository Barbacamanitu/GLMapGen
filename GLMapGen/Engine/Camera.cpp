#include "stdafx.h"
#include "Camera.h"
#include "Game.h"
Camera::Camera(Game* game)
{

	mGame = game;
	
	
	//view = glm::translate(view,cameraPos);
	proj = glm::perspective(glm::radians(45.0f), 1280.0f / 720.0f, 0.1f, 1000.0f);
	sensitivity = .05f;
	
	cameraPos = glm::vec3(0.0f, 75.0f, 100.0f);
	cameraUp = glm::vec3(0.f, 1.f, 0.f);
	direction = glm::normalize(cameraPos * -1.0f);
	view = glm::lookAt(
		cameraPos,
		cameraPos + direction,
		cameraUp);
	cameraSpeed = 1.5f;
}


Camera::~Camera()
{
}

void Camera::Update(double delta)
{
	float speed = cameraSpeed * (float)delta;
	glm::vec3 movement;
	if (mGame->getInput()->getKeyboard()->isKeyPressed(GLFW_KEY_W)) {
		cameraPos += cameraSpeed * direction;
	}

	if (mGame->getInput()->getKeyboard()->isKeyPressed(GLFW_KEY_S)) {
		cameraPos -= cameraSpeed * direction;
	}

	if (mGame->getInput()->getKeyboard()->isKeyPressed(GLFW_KEY_A)) {
		cameraPos -= glm::normalize(glm::cross(direction, cameraUp)) * cameraSpeed;

	}

	if (mGame->getInput()->getKeyboard()->isKeyPressed(GLFW_KEY_D)) {
		cameraPos += glm::normalize(glm::cross(direction, cameraUp)) * cameraSpeed;
	}

	float moveLen = glm::length(movement);
	if (moveLen > 0) {
		cameraPos += movement;
	}

	//Mouse
	glm::vec2 mPos = mGame->getInput()->getMouse()->getMouseDelta();
	if (mPos.length() > 0) {
		yaw += mPos.x * sensitivity * (float)delta;
		pitch += -mPos.y * sensitivity * (float)delta;
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
		glm::vec3 front;
		front.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
		front.y = sin(glm::radians(pitch));
		front.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
		direction = glm::normalize(front);
		view = glm::lookAt(cameraPos, cameraPos + direction, cameraUp);
	}
}

void Camera::setSensitivity(float sens)
{
	sensitivity = sens;
}
