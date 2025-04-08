#include "Framework.h"

ItemManager::ItemManager()
{
	heartUp = new ModelInstancing("heart", itemSize);
	powerUp = new ModelInstancing("power", itemSize);

	items.reserve(itemSize);

	FOR(itemSize)
	{
		Item* heart = new Item(heartUp->Add());
		Item* power = new Item(powerUp->Add());

		heart->SetActive(false);
		power->SetActive(false);

		items.push_back(heart);
		items.push_back(power);
	}
}

ItemManager::~ItemManager()
{
}

void ItemManager::Update()
{
}

void ItemManager::Render()
{
}
