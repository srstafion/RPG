#pragma once
#include <SFML/Graphics.hpp>
class Player
{
private:
	sf::CircleShape player;
	sf::Texture pTexture;
public:
	Player();
	void draw(sf::RenderWindow& window);
};

