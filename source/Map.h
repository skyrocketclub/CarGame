#pragma once
#include "Game.h"

class Map {
public:
	Map();
	~Map();

	void LoadMap(int arr[20][25]);
	void DrawMap();

private:
	SDL_Rect src, dest;
	SDL_Texture* brick;
	int map[20][25];
};