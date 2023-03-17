#include "Game.h"

Game* game = nullptr;

int main(int argc, char *argv[]) {

    int FPS = 60;
    int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Asfalt", 800, 640, false);

	while (game->running()) {
		frameDelay = 1000 / FPS;
		FPS += 0.5;
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->updateHighscore();
	game->clean();
	return 0;
}