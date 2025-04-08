#pragma once

class ItemManager
{
private:
	const UINT itemSize = 50;
public:
	ItemManager();
	~ItemManager();

	void Update();
	void Render();

private:
	ModelInstancing* heartUp;
	ModelInstancing* speedUp;
	ModelInstancing* powerUp;

	vector<Item*> items;
};
