#pragma once
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp>
class Game;
class Camera
{
public:
	Camera(Game* game);
	~Camera();
	void Update(double delta);
	glm::mat4 proj;
	glm::mat4 view;
	Game* mGame;
};

