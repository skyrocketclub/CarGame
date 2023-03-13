#pragma once

#include "Game.h"
#include <queue>


class Situation {
public:
	enum class Lane{kOne, kTwo, kThree};
	void Update_();
	void Render_();

private:
	int xpos;
	int ypos;

	std::queue<Situation> queue{};
	SDL_Texture* propTexture;
	SDL_Rect srcRect, destRect;
};