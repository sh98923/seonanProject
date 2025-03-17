#pragma once

class CreditManager : public Singleton<CreditManager>
{
private:
	friend class Singleton;

	const int POOL_SIZE = 1000;

	CreditManager();
	~CreditManager();

public:
	void Update();
	void Render();
	void Edit();

	void GetPlayer(SurvivalPlayer* player);

	void SpawnCredit(Vector3 pos);

private:
	ModelInstancing* creditModel;
	vector<Credit*> credits;
};
