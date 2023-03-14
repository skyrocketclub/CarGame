#pragma once

#include "Game.h"
#include <vector>


class Situation {
private:

	int xpos;
	int ypos{ 0 }; //starts from the top
	int form{};// 1- coin, 2 - greenCar, 3 - blueCar
	int lane{};// 1- lane One, 2 - lane Two, 3 - lane three
    

	SDL_Texture* propTexture;
	SDL_Rect srcRect, destRect;

	void setConstants();

public:
	Situation();
	~Situation();

	//enum class Lane{kOne, kTwo, kThree};
	static void Update_(std::vector<Situation*>);
	static void Render_(std::vector<Situation*>);

	int getY() { return ypos; }

};