#include "Map.h"
#include "TextureManager.h"

int lvl1[20][25] = {
	    {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,2,0,0,0,0,0,0,0,1}
};

Map::Map() {
	brick = TextureManager::LoadTexture("assets/brick.png");
	boundary = TextureManager::LoadTexture("assets/boundary.png");
	road = TextureManager::LoadTexture("assets/roadmark.png");

	LoadMap(lvl1);
	src.w = dest.w = 32;
	src.h = dest.h = 32;
	dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[20][25]) {
	for (int row{ 0 }; row < 20; row++) {
		for (int column = 0; column < 25; column++) {
			map[row][column] = arr[row][column];
		}
	}
}

void Map::DrawMap() {
	int type{ 0 };

	for (int row{ 0 }; row < 20; row++) {
		for (int column{ 0 }; column < 25; column++) {
			type = map[row][column];

			//We define the exact postion we want to be painted
			dest.x = column * 32;
			dest.y = row * 32;

			switch (type) {
			case 0:
				break;
			case 1:
				TextureManager::Draw(brick, src, dest);
				break;
			case 2:
				TextureManager::Draw(boundary, src, dest);
				break;
			case 3:
				TextureManager::Draw(road, src, dest);
				break;
			default:
				break;
			}
		}
	}
}