#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
//#include "Controller.h"
#include "Car.h"
#include <string>



class Game
{
public:
	Game();
	~Game();

	void handleEvents();
	void init(const char* title, int width, int height, bool fullscreen);
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

	void updateHighscore();
	int checkHighscore();
	void windowTitle(int, int);


	int highscore{};
	int count{ 0 };
	int score{0};

	static SDL_Renderer* renderer;

private:

	bool isRunning = false;
	SDL_Window* window;
};
