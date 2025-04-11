#include "Framework.h"
#include "ItemManager.h"

ItemManager::ItemManager()
{
	creditModel = new ModelInstancing("money", POOL_SIZE);
	heartUpModel = new ModelInstancing("heart", POOL_SIZE);
	powerUpModel = new ModelInstancing("power", POOL_SIZE);

	creditModel->SetShader(L"Instancing/UnlitInstancing.hlsl");
	heartUpModel->SetShader(L"Instancing/UnlitInstancing.hlsl");
	powerUpModel->SetShader(L"Instancing/UnlitInstancing.hlsl");

	credits.reserve(POOL_SIZE);
	items.reserve(POOL_SIZE * 2);

	FOR(POOL_SIZE)
	{
		Credit* credit = new Credit(creditModel->Add());
		Item* heart = new Item(heartUpModel->Add());
		Item* power = new Item(powerUpModel->Add());

		credit->SetActive(false);
		heart->SetActive(false);
		power->SetActive(false);

		credits.push_back(credit);
		items.push_back(heart);
		items.push_back(power);
	}
}

ItemManager::~ItemManager()
{
	delete creditModel;
	delete heartUpModel;
	delete powerUpModel;
}

void ItemManager::Update()
{
	for (Credit* credit : credits)
		credit->Update();

	for (Item* item : items)
		item->Update();

	//for (Item* power : items)
	//	power->Update();
	
	creditModel->Update();
	heartUpModel->Update();
	powerUpModel->Update();
}

void ItemManager::Render()
{
	creditModel->Render();
	heartUpModel->Render();
	powerUpModel->Render();

	for (Credit* credit : credits)
		credit->Render();

	for (Item* item : items)
		item->Render();

	//for (Item* power : items)
	//	power->Render();
}

void ItemManager::Edit()
{
	creditModel->Edit();
}

void ItemManager::GetPlayer(SurvivalPlayer* player)
{
	for (Credit* credit : credits)
		credit->SetPlayer(player);

	for (Item* item : items)
		item->SetPlayer(player);

	//for (Item* power : items)
	//	power->SetPlayer(player);
}

void ItemManager::SpawnCredit(Vector3 pos)
{
	for (Credit* credit : credits)
	{
		if (!credit->IsActive())
		{
			credit->SetActive(true);
			credit->SetLocalPosition(pos);
			credit->UpdateWorld();
			return;
		}
	}
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
