#include "Car.h"
#include "TextureManager.h"

Car::Car(const char* texturesheet, int x, int y) {
	carTexture = TextureManager::LoadTexture(texturesheet);
	xpos = x;
	ypos = y;
}

void Car::Update_() {
	ypos--;
	//xpos++;

	//The size of the image...
	srcRect.h = 32;
	srcRect.w = 32;

	//determines the position of the game object at every point in time
	destRect.x = xpos;
	destRect.y = ypos;

	//Controls the size of the game object
	destRect.w = srcRect.w *2;
	destRect.h = srcRect.h * 2;
}

void Car::Render_() {
	SDL_RenderCopy(Game::renderer, carTexture, &srcRect, &destRect);
}