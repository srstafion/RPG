#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"
class Game {
private:
	sf::RenderWindow window;
	sf::CircleShape mPlayer;
	Map map;
	Player player;
	void processEvents();
	void update();
	void render();
public:
	Game();
	void run();
	void handleMovement();
};