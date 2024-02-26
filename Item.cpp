#include "Item.h"

Item::Item(sf::Vector2f startPosition)
{
	item.setSize(sf::Vector2f(32, 32));
	item.setPosition(startPosition);
}

void Item::draw(sf::RenderWindow& window)
{
	window.draw(item);
}

sf::Vector2f Item::getPosition()
{
	return item.getPosition();
}

void Item::setPosition(sf::Vector2f pos)
{
	item.setPosition(pos);
}
