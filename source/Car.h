#pragma once

#include "Game.h"

class Car {
public:
	enum class Lane { kOne, kTwo, kThree };
	Car(const char* texturesheet, int x, int y);
	~Car();

	
	//The car is in the middle lane by default...
	Lane lane = Lane::kTwo;
	void ChangeDirection(Car::Lane);
	

	void Update_();
	void Render_();

private:
	int xpos;
	int ypos;

	SDL_Texture* carTexture;
	SDL_Rect srcRect, destRect;
};