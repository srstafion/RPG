#include "Map.h"
#include <iostream>

Map::Map(int width, int height)
	:backgroundTile(sf::Vector2f(width, height))
{
	sf::Texture* texture = new sf::Texture;
	if (!texture->loadFromFile("./Image/map.png")) std::cout << "a";
	backgroundTile.setTexture(texture);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			maskTiles[i][j].setSize(sf::Vector2f(32, 32));
			maskTiles[i][j].setFillColor((mask[i][j] == 1) ? sf::Color(0,255,0,100) : sf::Color(0,0,255,100));
			maskTiles[i][j].setPosition(sf::Vector2f(j * 32, i * 32));
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
