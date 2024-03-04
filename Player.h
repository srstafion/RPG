#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerStats.h"
using namespace sf;
class Player
{
	sf::RectangleShape player;
	sf::Texture texture;
	PlayerStats stats;
public:
	Player(sf::Vector2f startPosition);
	void draw(sf::RenderWindow&);
	void move(int direction);
	sf::Vector2f getPosition();
	void addHp(int hp);
	void removeHp(int hp);
	int getHp();
};