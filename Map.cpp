#include "Map.h"
#include <iostream>

Map::Map(int width, int height)
	: backgroundTile(sf::Vector2f(width, height))
{
	sf::Texture* texture = new sf::Texture;
	if (!texture->loadFromFile("./Image/map.png")) std::cout << "texture not load";

	backgroundTile.setTexture(texture);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			if(mask[i][j]==4) {
				maskTiles[i][j].setSize(sf::Vector2f(32, 32));
				maskTiles[i][j].setFillColor(sf::Color(100, 100, 75));
				maskTiles[i][j].setPosition(sf::Vector2f(j * 32, i * 32));
			}
			else {
				maskTiles[i][j].setSize(sf::Vector2f(32, 32));
				maskTiles[i][j].setFillColor((mask[i][j] == 1) ? sf::Color(0, 255, 0, 0) : sf::Color(0, 0, 255, 0));
				maskTiles[i][j].setPosition(sf::Vector2f(j * 32, i * 32));
			}
		}
	}


}

void Map::draw(sf::RenderWindow& window)
{
	window.draw(backgroundTile);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			window.draw(maskTiles[i][j]);
		}
	}
}

int Map::getElementByPosition(int x, int y)
{
	return mask[y][x];
}

vector<vector<int>> Map::getArrayCoordinatesByNum(int num)
{
	vector<vector<int>> coordinates;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			if (mask[i][j] == num) {
				vector<int> coord;
				coord.push_back(i);
				coord.push_back(j);
				coordinates.push_back(coord);
			}

		}
	}
	return coordinates;
}

void Map::changeMask(int x, int y, int value)
{
	cout << mask[y][x] << endl;
	mask[y][x] = value;
	cout << mask[y][x] << endl;
}