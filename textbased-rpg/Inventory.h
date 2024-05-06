#pragma once
class Entity;
class Item;
#include "Stuff.h"
#include "Item.h"
#include "Input.h"
//#define INVENTORY_SIZE 20


class Inventory
{
public:
    Inventory();
    ~Inventory();
    void addItem(Item* item);
    void removeItem(Item* item);
    void moveItem(Item* item, Inventory* newInventory);
    void useItem(Item* item);
    void equipItem(Item* item);
    void displayItemsPage(int page, std::vector<Item*> items);
    void displayItemsPage(int page);
    void displayItems();
    void setOwner(Entity* entity);
    bool selectEquipItem();
    bool selectUseItem();
    Item* itemSelection(const std::function<bool(Item*)>& filter);

    template<typename T>
    T* findItem()
    {
        for (auto& item : items) {
            if (typeid(*item) == typeid(T)) {
                return dynamic_cast<T*>(item);
            }
        }
        return nullptr;
    }

    std::vector<Item*> getItems() const;
private:
    std::vector<Item*> items;
    Entity* owner;
};
