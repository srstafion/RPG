#include "PlayerStats.h"

PlayerStats::PlayerStats()
{
	healthBar.setSize(Vector2f(320, 32));
	healthBar.setFillColor(Color(175,29,73));
	healthBar.setPosition(Vector2f(0, 0));
	bghealthBar.setSize(Vector2f(320, 32));
	bghealthBar.setFillColor(Color(81, 30, 45));
	bghealthBar.setPosition(Vector2f(0, 0));
	hpFont.loadFromFile("./Fonts/arial.ttf");
	hpText.setFont(hpFont);
	hpText.setPosition(Vector2f(96, 4));
	hpText.setFillColor(Color(237,235,222));
	hpText.setString("HP: "+std::to_string(hp) + "/100");
	hpText.setCharacterSize(20);
	hpText.setOutlineThickness(1);
	hpText.setOutlineColor(Color(237, 235, 222));
}

void PlayerStats::showStats(RenderWindow& window)
{
	window.draw(bghealthBar);
	window.draw(healthBar);
	window.draw(hpText);
}

int PlayerStats::getHealth()
{
	return hp;
}

void PlayerStats::setHealth(int hp)
{
	if (hp > 100) hp == 100;
	if (hp < 0) hp == 0;
	this->hp = hp;
	hpText.setString("HP: " + std::to_string(hp) + "/100");
	healthBar.setSize(Vector2f(3.2 * hp, 32));
}
