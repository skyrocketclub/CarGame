#include "Situation.h"
#include "TextureManager.h"

Situation::Situation() {
	setConstants();
	ypos = 0;
}

Situation::~Situation() {

}

void Situation::setConstants() {
	int form_{ 0 }, lane_{ 0 };
	form_ = rand() % 3 +1;//generates numbers between 0 - 3
	lane_ = rand() % 3 + 1;

	//The lane of the prop does not change
	switch (lane_) {
	case 1:
		xpos = 368;
		break;
	case 2:
		xpos = 400;
		break;
	case 3:
		xpos = 432;
		break;
	default:
		break;
	}

	switch (form_) {
	case 1: {
		propTexture = TextureManager::LoadTexture("assets/coin.png");
	/*	std::cout << "Coin Created\n";*/
	}
		break;
	case 2: {
		propTexture = TextureManager::LoadTexture("assets/greenCar.png");
		//std::cout << "Green Car Created\n";
	}
		break;
	case 3: 
	{
		propTexture = TextureManager::LoadTexture("assets/redCar.png");
		//std::cout << "Red Car Created\n";
	}
		break;
	default:
		break;
	}
}

void Situation::Update_(std::vector<Situation*> props) {
	
	for (size_t i{ 0 }; i < props.size(); i++) {
		//std::cout << "Updating................................\n";

		props.at(i)->srcRect.h = 32;
		props.at(i)->srcRect.w = 32;

		props.at(i)->destRect.x = props.at(i)->xpos;

		//causing the prop to move down...
		props.at(i)->ypos++;
		props.at(i)->destRect.y = props.at(i)->ypos;

		props.at(i)->destRect.w = props.at(i)->srcRect.w *2;
		props.at(i)->destRect.h = props.at(i)->srcRect.h *2;
	}
}

void Situation::Render_(std::vector<Situation*> props) {
	for (size_t i{ 0 }; i < props.size(); i++) {
		SDL_RenderCopy(Game::renderer, props.at(i)->propTexture, &props.at(i)->srcRect, &props.at(i)->destRect);
	}
}