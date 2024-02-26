#pragma once
#include "Item.h";
#include <iostream>
using namespace sf;
using namespace std;
class Chest : public Item
{
private:
	static sf::Texture texture;

public:
	Chest(sf::Vector2f startPosition);
};