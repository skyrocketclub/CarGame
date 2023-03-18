#include "Car.h"
#include "TextureManager.h"

Car::Car(const char* texturesheet, int x, int y) {
	carTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

void Car::Update_() {
	
	//updating the lane...
	switch (lane) {
	case Lane::kOne:
		xpos = 348;
		//xpos = 368;
		break;
	case Lane::kTwo:
		xpos = 400;
		break;
	case Lane::kThree:
		//xpos = 432;
		xpos = 452;
		break;
	}

	//ypos--;
	//xpos++;

	//The size of the image...
	srcRect.h = 32;
	srcRect.w = 20;

	//determines the position of the game object at every point in time
	destRect.x = xpos;
	destRect.y = ypos;

	//Controls the size of the game object
	destRect.w = srcRect.w *2;
	destRect.h = srcRect.h *2;
}
void Car::ChangeDirection(Car::Lane input) {
	lane = input;
}

void Car::Render_() {
	SDL_RenderCopy(Game::renderer, carTexture, &srcRect, &destRect);
}