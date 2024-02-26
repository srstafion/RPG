#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "Item.h"
using namespace std;

class Inventory
{
	sf::RectangleShape inventoryWindow;
	vector <sf::RectangleShape> slots;
	vector <Item> items;
	int slotCount = 5;
	const sf::Vector2f sizeSlot = sf::Vector2f(50, 50);
	int distanceBetweenSlots = 5;
	bool visible = false;
public:
	Inventory(sf::Vector2f startPosition);
	void draw(sf::RenderWindow&);
	void changeVisible();
	void addItem(Item item);
};
