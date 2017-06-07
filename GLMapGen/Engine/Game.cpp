#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <chrono>
#include "Commands\CloseGameCommand.h"
#include <memory>
#include <sstream>
Game::Game()
{
	mTime.timestep = 1.0 / 60.0;
}


Game::~Game()
{
}

void Game::Start()
{
	mTime.newTime = SClock::now();
	mTime.currentTime = mTime.newTime;
	mTime.time = 0;
	shaderManager.add("phong", ShaderProgram::createShader("Shaders/phong.fs", "Shaders/phong.vs"));

	MainLoop();
	
}

void Game::End()
{
	glfwSetWindowShouldClose(mWindow, GLFW_TRUE);
}

Input* Game::getInput()
{
	return mInput.get();
}

void Game::MainLoop()
{
	double t = 0.0;
	double dt = 1.0/60.0;

	TimePoint currentTime = SClock::now();
	double accumulator = 0.0;

	while (!glfwWindowShouldClose(mWindow)) {
		HandleEvents();


		TimePoint newTime = SClock::now();
		double frameTime = std::chrono::duration_cast<std::chrono::microseconds>(newTime - currentTime).count() * 0.000001;
		if (frameTime > 0.25)
			frameTime = 0.25;
		currentTime = newTime;

		accumulator += frameTime;

		while (accumulator >= dt)
		{
			Update(t,dt);
			t += dt;
			accumulator -= dt;
		}
		const double alpha = accumulator / dt;
		Render(alpha);
	}

}

void Game::Update(double time, double delta)
{
	cam->Update(delta);
	mInput->update(delta);
}

void Game::Render(double alpha)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//tri->draw(mTime.time);
	wireframe->Render();
	glm::vec2 mousePos = getInput()->getMouse()->getMouseDelta();
	std::stringstream pos;
	pos << mousePos.x << "," << mousePos.y;
	mFontLoader->drawText("consola", pos.str(), 25.0f, 25.0f, 1.0f, glm::vec3(1.0, 0.0f, 0.0f));
	

	//mWindow->display();
	glfwSwapBuffers(mWindow);
}

void Game::HandleEvents()
{
	glfwPollEvents();
}


void Game::SetupInput()
{
	mInput.reset(new Input(mWindow));
	mInput->getMouse()->lockCursor();
	CloseGameCommand comm;
	comm.setGame(this);
	mInput->getKeyboard()->addCommand(256, std::make_unique<CloseGameCommand>(comm));
}

void Game::Initialize() {
	//Create window
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	mWindow = glfwCreateWindow(1280, 720, "OpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(mWindow);
	//Setup opengl context
	glewExperimental = GL_TRUE;
	glewInit();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	SetupInput();
	mFontLoader.reset(new FontLoader());
	mFontLoader->Load("Fonts/consola.ttf","consola");

	glViewport(0, 0, 1280, 720);
	wireframe = new Wireframe();
	wireframe->cam = cam;
	wireframe->Initialize();
	world = new World();
}
