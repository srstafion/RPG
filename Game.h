#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
#include "Inventory.h"
#include "Item.h"
#include "Chest.h"
#include "Potion.h"
#include "SystemWindow.h"

class Game
{
private:
	sf::RenderWindow window;
	Player player;
	Map map;
	Inventory inventory;
	SystemWindow systemWindow;
	int playerMoveDirection = 0;
	const sf::Time TimePerFrame = sf::seconds(1.f / 10.f);
	vector<Item> items;
	int lastFaced = 0;//1-up 2-right 3-down 4-left


	void processEvents();
	void update(sf::Time deltaTime);
	void render();

	bool static flag;
	int static value;
	thread th;

	void static incrementer();

public:
	Game();
	~Game();
	void run();

};
