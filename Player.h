#pragma once
#include <SFML/Graphics.hpp>
class Player
{
	sf::RectangleShape player;
	sf::Texture texture;
public:
	Player(sf::Vector2f startPosition);
	void draw(sf::RenderWindow&);
	void move(int direction);
	sf::Vector2f getPosition();

};