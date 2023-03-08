#pragma once

#include "SDL.h"
#include <iostream>

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

	static SDL_Renderer* renderer;

private:
	bool isRunning = false;
	SDL_Window* window;
};
