#include "Game.h"
#include <Windows.h>

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			playerMoveDirection = 1;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			playerMoveDirection = 2;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			playerMoveDirection = 3;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			playerMoveDirection = 4;
		else
			playerMoveDirection = 0;

		switch (event.type) {
		case sf::Event::KeyReleased: // need to figure out a way of knowing which key it was so I don't stop both paddles
			if (event.key.scancode == sf::Keyboard::Scan::I)
				inventory.changeVisible();
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
			vector<Item> items = inventory.getItems();
			for (auto i : items) {
				if (i) {
					items.erase(items.begin() + i);
				}
			}
			/*if (event.key.scancode == sf::Keyboard::Scan::P) {
				systemWindow.setText("full inventory");
				value = 0;
			}*/

			if (event.key.scancode == sf::Keyboard::Scan::F) {

				if (inventory.getCountItems() >= inventory.getSlotCount()) {
					systemWindow.setText("full inventory");
					value = 0;
					break;
				}

				sf::Vector2f pPos = player.getPosition();
				cout << "lasFaced: " << lastFaced << " : " << pPos.x / 32 << " : " << pPos.y / 32 << endl;
				switch (lastFaced) {

				case 1:
					if (map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) > 1) {
						for (int i = 0; i < items.size(); i++) {
							if (items[i].getPosition().x == pPos.x &&
								items[i].getPosition().y == pPos.y - 32) {
								inventory.addItem(items[i]);
								map.changeMask(pPos.x / 32, (pPos.y - 32) / 32, 1);
								items.erase(items.begin() + i);
							}
						}
					}
					break;
				case 2:
					if (map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) > 1) {
						for (int i = 0; i < items.size(); i++) {
							if (items[i].getPosition().x == pPos.x + 32 &&
								items[i].getPosition().y == pPos.y) {
								inventory.addItem(items[i]);
								map.changeMask((pPos.x + 32) / 32, pPos.y / 32, 1);
								items.erase(items.begin() + i);
							}
						}
					}
					break;
				case 3:
					if (map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) > 1) {
						for (int i = 0; i < items.size(); i++) {
							if (items[i].getPosition().x == pPos.x &&
								items[i].getPosition().y == pPos.y + 32) {
								inventory.addItem(items[i]);
								map.changeMask(pPos.x / 32, (pPos.y + 32) / 32, 1);
								items.erase(items.begin() + i);
							}
						}
					}
					break;
				case 4:
					if (map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) > 1) {
						for (int i = 0; i < items.size(); i++) {
							if (items[i].getPosition().x == pPos.x - 32 &&
								items[i].getPosition().y == pPos.y) {
								inventory.addItem(items[i]);
								map.changeMask((pPos.x - 32) / 32, pPos.y / 32, 1);
								items.erase(items.begin() + i);
							}
						}
					}
					break;
				}
			}
			break;
		}

	}

}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f pPos = player.getPosition();
	switch (playerMoveDirection) { 
	case 1:
		if (map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) == 1 || map.getElementByPosition(pPos.x / 32, (pPos.y - 32) / 32) == 4)
			player.move(1);
		break;
	case 2:
		if (map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) == 1 || map.getElementByPosition((pPos.x + 32) / 32, pPos.y / 32) == 4)
			player.move(2);
		break;
	case 3:
		if (map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) == 1 || map.getElementByPosition(pPos.x / 32, (pPos.y + 32) / 32) == 4)
			player.move(3);
		break;
	case 4:
		if (map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) == 1 || map.getElementByPosition((pPos.x - 32) / 32, pPos.y / 32) == 4)
			player.move(4);
		break;
	}
	if (playerMoveDirection != 0) lastFaced = playerMoveDirection;

	if (map.getElementByPosition(pPos.x / 32, pPos.y / 32) == 4 && player.getHp() > 0) {
		if(value%10==0)player.removeHp(5);
	}

	Sleep(deltaTime.asSeconds());

}

void Game::render()
{
	window.clear();

	map.draw(window);
	player.draw(window);

	for (auto el : items) {
		el.draw(window);
	}

	inventory.draw(window);
	if (value < 30) {
		systemWindow.setVisible(true);
	}
	else systemWindow.setVisible(false);
	systemWindow.draw(window);
	window.display();
}

Game::Game()
	:window(sf::VideoMode(960, 640), "RPG game"),
	player(sf::Vector2f(6 * 32, 6 * 32)),
	map(960, 640),
	inventory(sf::Vector2f(10 * 32, 10 * 32)),
	systemWindow(sf::Vector2f(8 * 32, 15 * 32)),
	th(incrementer)
{
	vector<vector<int>> coords = map.getArrayCoordinatesByNum(2);
	for (auto el : coords) {
		items.push_back(Chest(sf::Vector2f(el[1] * 32, el[0] * 32)));

	}

	vector<vector<int>> coords2 = map.getArrayCoordinatesByNum(3);
	for (auto el : coords2) {
		items.push_back(Potion(sf::Vector2f(el[1] * 32, el[0] * 32)));

	}
}

Game::~Game()
{
	th.join();
}

void Game::run()
{

	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}

		render();
	}

}


void Game::incrementer()
{
	while (flag == true) {
		this_thread::sleep_for(chrono::milliseconds(100));
		value++;
		cout << value;
	}

}


int Game::value = 1000;
bool Game::flag = true;