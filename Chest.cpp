#include "Chest.h"

Chest::Chest(sf::Vector2f startPosition) :
	Item(startPosition)
{
	texture.loadFromFile("./Image/Chest.png");
	item.setTexture(&texture);
	cout << "yes" << endl;
}

sf::Texture Chest::texture;