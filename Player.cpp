#include "Player.h"
#include <iostream>

Player::Player()
{
	player.setRadius(40.f);
	player.setPosition(440.f, 280.f);
	sf::Texture* texture = new sf::Texture;
	if (!texture->loadFromFile("./Image/andiwasjustdrinking.png")) std::cout << "a";
	player.setTexture(texture);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(player);
}
