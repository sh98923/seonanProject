#include "Framework.h"

ItemManager::ItemManager()
{
	heartUp = new ModelInstancing("heart", itemSize / 3);
	powerUp = new ModelInstancing("power", itemSize / 3);

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
	for (Item* item : items)
		item->Update();

	heartUp->Update();
	powerUp->Update();
}

void ItemManager::Render()
{
	for (Item* item : items)
		item->Render();

	heartUp->Render();
	powerUp->Render();
}

void ItemManager::GetPlayer(SurvivalPlayer* player)
{
	for (Item* item : items)
		item->SetPlayer(player);
}

void ItemManager::SpawnItem(Vector3 pos)
{
	for (Item* item : items)
	{
		if (!item->IsActive())
		{
			item->SetActive(true);
			item->SetLocalPosition(pos);
			item->UpdateWorld();
			return;
		}
	}
}
