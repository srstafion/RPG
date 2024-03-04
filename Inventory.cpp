#include "Inventory.h"
/*
sf::RectangleShape inventoryWindow;
	vector <sf::RectangleShape> slots;
	int slotCount;

*/
Inventory::Inventory(sf::Vector2f startPosition)
{
	int x = slotCount * (sizeSlot.x + distanceBetweenSlots * 2);
	int y = sizeSlot.x + distanceBetweenSlots * 2;
	inventoryWindow.setSize(sf::Vector2f(x, y));
	inventoryWindow.setPosition(startPosition);
	inventoryWindow.setFillColor(sf::Color(0, 0, 0, 50));
	for (int i = 0; i < slotCount; i++) {
		sf::RectangleShape slot(sizeSlot);
		slot.setFillColor(sf::Color(0, 0, 0, 50));
		int slotX = startPosition.x + distanceBetweenSlots +
			(distanceBetweenSlots * 2 + sizeSlot.x) * i;
		int slotY = startPosition.y + distanceBetweenSlots;
		slot.setPosition(sf::Vector2f(slotX, slotY));
		slots.push_back(slot);
	}
}

void Inventory::draw(sf::RenderWindow& window)
{
	if (visible) {
		window.draw(inventoryWindow);
		for (int i = 0; i < slotCount; i++) {
			window.draw(slots[i]);
		}

		for (auto item : items) {
			item.draw(window);
		}
	}



}

void Inventory::changeVisible()
{
	visible = !visible;
}

void Inventory::addItem(Item item)
{
	items.push_back(item);
	for (int i = 0; i < items.size(); i++) {
		items[i].setPosition(sf::Vector2f(slots[i].getPosition().x + 8,
			slots[i].getPosition().y + 8));
	}

}

void Inventory::removeItem(int index)
{
}

int Inventory::getCountItems()
{
	return items.size();
}

int Inventory::getSlotCount()
{
	return slotCount;
}

vector<Item> Inventory::getItems()
{
	return items;
}
