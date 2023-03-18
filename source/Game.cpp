#include "Game.h"
#include "Car.h"
#include "TextureManager.h"
#include "Situation.h"
#include "vector"
#include "Map.h"
#include <fstream>


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
	car1 = new Car("assets/blueCarOne.png", 400, 500);
	map = new Map();
	highscore = checkHighscore();
	windowTitle(score, highscore);
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

	if (car1->isAlive == true) {
		//creating new situations on the screen when there are none at all
		if (props.size() == 0) {
			Situation* prop = new Situation;
			props.push_back(prop);
		}
		else if (props.back()->getY() > 180) {
			//to prevent the props from clustering upon entering the game screen...
			Situation* prop = new Situation;
			props.push_back(prop);
		}


		//If the car is on the same position as a gold coin... or if the coin is simply within range
		if (props.front()->isCoin() == true && car1->getCarX() == props.front()->getX() && (props.front()->getY() > 440)) {
			this->score += 5;
			Situation::swallowProps(props); //get the coin of the screen
			std::cout << "Score: " << this->score << std::endl;
		}

		//if the approaching prop is not a coin...
		if (props.front()->isCoin() != true) {
			//If there is a collision, this means game over...
			if (car1->getCarX() == props.front()->getX() && (props.front()->getY() > 434)) {
				car1->isAlive = false;
				updateHighscore();
				std::cout << "------  GAME OVER  -------\n";
			}
		}

		Situation::Update_(props);
		car1->Update_();
		windowTitle(score, highscore);
	}
}

void Game::render() {
	SDL_RenderClear(renderer);
		//Using the painters algorithm, what is rendered first is drawn first to the screen
	map->DrawMap();
	Situation::Render_(props);
	car1->Render_();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}


void Game::updateHighscore()
{
	std::ofstream out_file;
	out_file.open("assets/highscore.txt", std::ios::out);

	if (score > highscore) {
		out_file << score;
		out_file.close();
		std::string title{ "New Highscore: " + std::to_string(score) };
		SDL_SetWindowTitle(window, title.c_str());
	}
	else {
		out_file << highscore;
	}
}

int Game::checkHighscore()
{
	int c_highscore{};
	std::ifstream in_file;
	in_file.open("assets/highscore.txt");

	if (!in_file) {
		in_file.close();

		//it means that the highscore does not exist and a new one is created
		std::ofstream out_file;
		out_file.open("assets/highscore.txt", std::ios::out);
		std::cout << "Current Highscore: 0\n";
		c_highscore = 0;
		out_file.close();
	}
	else {
		in_file >> c_highscore;
		std::cout << "Current Highscore: " << c_highscore << std::endl;
		in_file.close();
	}
	return c_highscore;
}

void Game::windowTitle(int score, int highscore)
{
	std::string title{ "Score: " + std::to_string(score) + "  Highscore: " + std::to_string(highscore) };
	SDL_SetWindowTitle(window, title.c_str());
}

