#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "Inventory.h"
#include "Item.h"
#include "Chest.h"
#include "Potion.h"

class Game
{
private:
	sf::RenderWindow window;
	Player player;
	Map map;
	Inventory inventory;
	int playerMoveDirection = 0;
	int lastFaced = 0;
	const sf::Time TimePerFrame = sf::seconds(1.f / 10.f);
	vector<Item> items;


	void processEvents();
	void update(sf::Time deltaTime);
	void render();

public:
	Game();
	void run();
};