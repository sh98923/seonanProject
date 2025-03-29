#pragma once

class EnemyManager : public Singleton<EnemyManager>
{
public:
	enum EnemyAnimation
	{
		RUN, DIE, NONE
	};

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
	
	void PlayDying();

	void GetPlayer(SurvivalPlayer* player);
	void GetDamagedFromBullet(Collider* collider);

	void DropCredit();

	ModelAnimatorInstancing* GetEnemyModel() { return enemyModel; }

private:
	void Spawning();

private:
	ModelAnimatorInstancing* enemyModel;
	Enemy* enemy;
	vector<Enemy*> enemies;

	float spawnInterval = 0.0f;
};
