#pragma once

class ItemManager : public Singleton<ItemManager>
{
private:
	const int POOL_SIZE = 200;

private:
	friend class Singleton;

	ItemManager();
	~ItemManager();

public:
	void Update();
	void Render();
	void Edit();

	void GetPlayer(SurvivalPlayer* player);

	void SpawnCredit(Vector3 pos);
	void SpawnItem(Vector3 pos);

private:
	ModelInstancing* creditModel;
	ModelInstancing* heartUpModel;
	ModelInstancing* powerUpModel;

	vector<Credit*> credits;
	vector<Item*> items;
};
