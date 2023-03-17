#include "Game.h"
#include "Car.h"
#include "TextureManager.h"
#include "Situation.h"
#include "vector"
#include "Map.h"


Car* car1;
Map* map;

//static variable...
SDL_Renderer* Game::renderer = nullptr;
std::vector<Situation*>props{};

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int width, int height, bool fullscreen) {
	int flag = 0;
	if (fullscreen == true) {
		flag = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flag);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer != nullptr) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		}
		isRunning = true;
	}
	car1 = new Car("assets/blueCar.png", 400, 500);
	map = new Map();
}

void Game::handleEvents() {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			isRunning = false;
		}
		else if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
			case SDLK_LEFT:
			{
				if (car1->lane == Car::Lane::kOne) {
					//DO NOTHING
				}
				else if (car1->lane == Car::Lane::kTwo) {
					//shift car from lane 2 to lane 1
					car1->ChangeDirection(Car::Lane::kOne);
				}
				else {
					//shift car from lane three to lane two
					car1->ChangeDirection(Car::Lane::kTwo);
				}
			}break;
			case SDLK_RIGHT: {
				if (car1->lane == Car::Lane::kThree) {
					//DO NOTHING
				}
				else if (car1->lane == Car::Lane::kTwo) {
					//shift car from lane 2 to lane 3
					car1->ChangeDirection(Car::Lane::kThree);
				}
				else {
					//shift car from lane One to lane two
					car1->ChangeDirection(Car::Lane::kTwo);
				}
			}break;
			default:
				break;
			}
		}
	}
}

void Game::update() {
	//creating new situations on the screen when there are none at all
	if (props.size() == 0) {
		Situation* prop = new Situation;
		props.push_back(prop);
	}
	else if (props.back()->getY() > 120) {
		//to prevent the props from clustering upon entering the game screen...
		Situation* prop = new Situation;
		props.push_back(prop);
	}


	//If the car is on the same position as a gold coin...
	if (props.front()->isCoin() == true && car1->getCarX() == props.front()->getX() && car1->getCarY()-50 == props.front()->getY()) {
		this->score++;
		Situation::swallowProps(props); //get the coin of the screen
		std::cout << "Score: " << this->score << std::endl;
	}

	
	Situation::Update_(props);
	car1->Update_();
}

void Game::render() {
	SDL_RenderClear(renderer);

	//Using the painters algorithm, what is rendered first is drawn first to the screen
	map->DrawMap();
	car1->Render_();
	Situation::Render_(props);
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::checkScore()
{

}

void Game::checkHighscore()
{
}

