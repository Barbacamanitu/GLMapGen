#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>
#include <memory>
#include "Camera.h"
#include "../Terrain/Terrain.h"
#include "../Experiments/Wireframe.h"
#include <chrono>
#include "Input/Input.h"
#include "Text/FontLoader.h"
#include "AssetManagers/AssetManager.h"
#include "World.h"
typedef std::chrono::time_point<std::chrono::steady_clock> TimePoint;
typedef std::chrono::steady_clock SClock;
struct TimeInfo {
	double timestep;
	double accumulator;
	TimePoint newTime;
	TimePoint currentTime;
	double frameTime;
	double alpha;
	double time;
};

class Game
{
public:
	Game();
	~Game();
	void Initialize();
	void Start();
	void End();
	Input* getInput();
private:
	void MainLoop();
	void Update(double time, double delta);
	void Render(double alpha);
	void HandleEvents();
	void SetupInput();
	GLFWwindow* mWindow;
	TimeInfo mTime;
	Camera* cam;
	Wireframe* wireframe;
	Terrain* terrain;
	std::unique_ptr<Input> mInput;
	std::unique_ptr<FontLoader> mFontLoader;
	AssetManager<ShaderProgram> shaderManager;
	World* world;
};

