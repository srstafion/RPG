#include "Game.h"
#include "Map.h"
void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
		}
	}
}

void Game::update()
{
}

void Game::render()
{
	window.clear();
	map.draw(window);
	player.draw(window);
	window.display();
}

Game::Game()
	:window(sf::VideoMode(960, 640), "RPG"),
	player(),
	map(960, 640)
{
}

void Game::run()
{
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}
