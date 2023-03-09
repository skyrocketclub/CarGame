#pragma once

#include "Game.h"

class Car {
public:
	Car(const char* texturesheet, int x, int y);
	~Car();

	void Update_();
	void Render_();

private:
	int xpos;
	int ypos;

	SDL_Texture* carTexture;
	SDL_Rect srcRect, destRect;
};