#include "Potion.h"

Potion::Potion(sf::Vector2f startPosition) :
	Item(startPosition)
{
	texture.loadFromFile("./Image/potion.png");
	item.setTexture(&texture);
	cout << "yes" << endl;
}

sf::Texture Potion::texture;