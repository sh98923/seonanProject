#pragma once

class EnemyManager : public Singleton<EnemyManager>
{
private:
	UINT enemyCount = 50;
	const float SPAWN_TIMER = 3.0f;

private:
	friend class Singleton;

	EnemyManager();
	~EnemyManager();

public:
	void Update();
	void Render();
	void Edit();

	void GetPlayer(SurvivalPlayer* player);
	void GetDamagedFromBullet(Collider* collider);

private:
	void Spawning();

private:
	ModelInstancing* enemyModel;
	vector<Enemy*> enemies;

	float spawnInterval = 0.0f;
};
