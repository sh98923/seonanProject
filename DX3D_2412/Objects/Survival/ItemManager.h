#pragma once

class ItemManager : public Singleton<ItemManager>
{
private:
	const UINT itemSize = 120;

private:
	friend class Singleton;

	ItemManager();
	~ItemManager();

public:
	void Update();
	void Render();

	void GetPlayer(SurvivalPlayer* player);

	void SpawnItem(Vector3 pos);
private:
	ModelInstancing* heartUp;
	ModelInstancing* speedUp;
	ModelInstancing* powerUp;

	vector<Item*> items;
};
