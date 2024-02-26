#pragma once
#include "Item.h";
#include <iostream>
using namespace sf;
using namespace std;

class Potion : public Item
{
private:
	static sf::Texture texture;

public:
	Potion(sf::Vector2f startPosition);
};

