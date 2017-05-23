#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	mTime.timestep = 1.0 / 60.0;
}


Game::~Game()
{
}

void Game::Start()
{
	mClock.restart();
	mTime.newTime = mClock.getElapsedTime().asMicroseconds() / (1000.0 * 1000.0);
	mTime.currentTime = mTime.newTime;
	mTime.time = 0;

	while (mWindow->isOpen()) {
		HandleEvents();
		MainLoop();
	}
}

void Game::End()
{
	mWindow->close();
}

void Game::MainLoop()
{
	//Handle timing and calls to update/render
	mTime.newTime = mClock.getElapsedTime().asMicroseconds() / (1000.0 * 1000.0);
	mTime.frameTime = mTime.newTime - mTime.currentTime;
	if (mTime.frameTime > 0.25)
		mTime.frameTime = 0.25;
	mTime.currentTime = mTime.newTime;

	mTime.accumulator += mTime.frameTime;

	while (mTime.accumulator >= mTime.timestep)
	{
		Update();
		mTime.time += mTime.timestep;
		mTime.accumulator -= mTime.timestep;
	}

	mTime.alpha = mTime.accumulator / mTime.timestep;
	Render(mTime.alpha);
}

void Game::Update()
{
	cam->Update(mTime.timestep);
}

void Game::Render(double alpha)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	tri->draw(mTime.time);
	mWindow->display();
}

void Game::HandleEvents()
{
	while (mWindow->pollEvent(mEvent)) {
		if (mEvent.type == sf::Event::EventType::KeyPressed) {
			if (mEvent.key.code == sf::Keyboard::Escape) {
				//Close game when escape is pressed.
				End();
			}
		}
	}
}

void Game::Initialize() {
	//Create window
	mWindow.reset(new sf::Window());
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 4;
	settings.majorVersion = 3;
	settings.minorVersion = 0;

	mWindow->create(sf::VideoMode(800, 600), "OpenGL", sf::Style::Default, settings);
	//Setup opengl context
	glewExperimental = GL_TRUE;
	glewInit();
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);
	printf("Testing OpenGL...\n");
	printf("%u\n", vertexBuffer);
	glViewport(0, 0, 800, 600);
	cam = new Camera();
	tri = new Triangle();
	tri->cam = cam;
}
