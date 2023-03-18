#pragma once

#include "Game.h"
#include <vector>
#include <random>
#include <time.h>
#include <cstdlib>


class Situation {

public:
	Situation();
	~Situation();

	//checks if the top element is a coin
	bool isCoin();
	static void Update_(std::vector<Situation*>&);
	static void Render_(std::vector<Situation*>);
	static void swallowProps(std::vector<Situation*>&);

	int getY() { return ypos; }
	int getX() { return xpos; }


private:

	int xpos;
	int ypos{ 0 }; //starts from the top
	int form{};// 1- coin, 2 - greenCar, 3 - blueCar
	int lane{};// 1- lane One, 2 - lane Two, 3 - lane three
    
	//srand(time(nullptr));
	SDL_Texture* propTexture;
	SDL_Rect srcRect, destRect;

	void setConstants();
};