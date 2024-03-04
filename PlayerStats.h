#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class PlayerStats
{
private:
	RectangleShape healthBar;
	RectangleShape bghealthBar;
	int hp = 100;
	Text hpText;
	Font hpFont;
public:
	PlayerStats();
	void showStats(RenderWindow &window);
	int getHealth();
	void setHealth(int hp);
};

