#include "Inventory.h"

Inventory::Inventory() {
	items = std::vector<Item*>();
}

void Inventory::addItem(Item* item) {
	items.push_back(item);
}

void Inventory::removeItem(Item* item) {
    auto it = std::find_if(items.begin(), items.end(),
        [item](const Item* i) { return *item == i; });

    if (it != items.end()) {
		delete *it;
        items.erase(it);
	}
	else {
		std::cout << "COULDN'T REMOVE ITEM: NOT FOUND!!!\n";
	}

}

void Inventory::useItem(Item* item)
{
	if (item == nullptr) std::cout << "Item not found.\n";
	else if (!item->isConsumable()) std::cout << "Item is not consumable.\n";
	else {
		item->onUse(owner);
		removeItem(item);
	}
}

void Inventory::equipItem(Item* item)
{
	if (!item) {
		std::cout << "No item to equip.\n";
		return;
	}
	if (item->isEquipped())
		item->onUnequip(owner);
	else
		item->onEquip(owner);
}

void Inventory::displayItems() {
	for (auto item : getItems()) {
		item->displayInlineInfo();
	}
}

void Inventory::setOwner(Entity* entity) {
	owner = entity;
}

bool Inventory::selectEquipItem()
{
	Item* item;
	item = itemSelection([](Item* it) {
		return it->getType() == Item::ItemType::Equippable;
		});
	if (item) {
		equipItem(item);
		return true;
	}
	return false;
}

bool Inventory::selectUseItem()
{
	Item* item = itemSelection([](Item* it) {
		return it->getType() == Item::ItemType::Useable;
		});
	if (item) {
		useItem(item);
		return true;
	}
	return false;
}

Item* Inventory::itemSelection(const std::function<bool(Item*)>& filter) {
	int page = 1;
	std::vector<Item*> filteredItems = std::vector<Item*>();
	for (Item* item : items) {
		if (filter(item)) filteredItems.push_back(item);
	}
	int selectSize = std::min((int)filteredItems.size()-(page-1)*5, 5);
	int input = -1;

	auto canGoToNextPage = [](int currentPage, int totalItems) -> bool {
		return currentPage < (std::max(totalItems - 1, 1) / 5 + 1);
	};

	while (true) {
		selectSize = std::min((int)filteredItems.size()-(page-1)*5, 5);
		displayItemsPage(page, filteredItems);
		bool nextPage = canGoToNextPage(page, filteredItems.size());
		int nextPageInput = -1;
		int previousPageInput = -1;
		int si = selectSize;
		if (page > 1) {
			std::cout << ++si << ". Previous Page\n";
			previousPageInput = si;
		}
		if (nextPage) {
			std::cout << ++si << ". Next Page\n";
			nextPageInput = si;
		}
		std::cout << ++si << ". Back\n";
		int backInput = si;
		int input = Input::getIntInput(1,si);
		if (input == nextPageInput) page++;
		else if (input == previousPageInput) page--;
		else if (input == backInput) return nullptr;
		else {
			for (int i = 1; i <= selectSize; i++) {
				if (input == i) {
					Item* item = filteredItems[(page - 1)* 5 + i - 1];
					return item;
					// std::cout << "YOU HAVE SELECTED " << item->getName() << ". WELL DONE.\n";
					// break;
				}
			}
		}
	}
}

void Inventory::displayItemsPage(int page, std::vector<Item*> items)
{
	int currentPage = 1;
	int currentItem = 0;
	for (auto item : items) {
		currentItem++;
		if (currentItem > 5) {
			currentPage++;
			currentItem = 1;
		}
		if (currentPage == page) {
			std::cout << currentItem << ". ";
			item->displayInlineInfo();
		}
	}
}

void Inventory::displayItemsPage(int page) {
	displayItemsPage(page, getItems());
}

std::vector<Item*> Inventory::getItems() const {
	return items;
}
