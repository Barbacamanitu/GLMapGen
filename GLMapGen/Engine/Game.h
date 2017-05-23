#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <SFML\Graphics.hpp>
#include <memory>
#include "..\Experiments\Triangle.h"


struct TimeInfo {
	double timestep;
	double accumulator;
	double newTime;
	double currentTime;
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
private:
	void MainLoop();
	void Update();
	void Render(double alpha);
	void HandleEvents();

	sf::Event mEvent;
	std::unique_ptr<sf::Window> mWindow;
	sf::RenderStates rStates;
	sf::Clock mClock;
	TimeInfo mTime;
	Triangle* tri;
};

