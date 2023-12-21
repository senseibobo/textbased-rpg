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

void Inventory::displayItems() {
	for (auto item : getItems()) {
		item->displayInlineInfo();
	}
}

void Inventory::setOwner(Entity* entity) {
	owner = entity;
}

void Inventory::itemSelection() {
	int page = 1;
	int selectSize = std::min((int)items.size()-(page-1)*5, 5);
	int input = -1;

	auto canGoToNextPage = [](int currentPage, int totalItems) -> bool {
		return currentPage < (std::max(totalItems - 1, 1) / 5 + 1);
	};

	while (true) {
		selectSize = std::min((int)items.size()-(page-1)*5, 5);
		displayItemsPage(page);
		bool nextPage = canGoToNextPage(page, items.size());
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
		else if (input == backInput) break;
		else {
			for (int i = 1; i <= selectSize; i++) {
				if (input == i) {
					Item* item = items[(page - 1)* 5 + i - 1];
					std::cout << "YOU HAVE SELECTED " << item->getName() << ". WELL DONE.\n";
					break;
				}
			}
		}
	}
}

void Inventory::displayItemsPage(int page) {
	int currentPage = 1;
	int currentItem = 0;
	for (auto item : getItems()) {
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

std::vector<Item*> Inventory::getItems() const {
	return items;
}
