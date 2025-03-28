#pragma once

class CreditManager : public Singleton<CreditManager>
{
private:
	const int POOL_SIZE = 1000;

private:
	friend class Singleton;

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
