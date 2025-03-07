#include "Framework.h"

EnemyManager::EnemyManager()
{
	enemyModel = new ModelInstancing("MyPlayer", enemyCount);

	enemies.reserve(enemyCount);

	FOR(enemyCount)
	{
		Enemy* enemy = new Enemy(enemyModel->Add());
		enemy->SetActive(false);

		enemies.push_back(enemy);
	}
}

EnemyManager::~EnemyManager()
{
	delete enemyModel;
}

void EnemyManager::Update()
{
	for (Enemy* enemy : enemies)
		enemy->Update();

	enemyModel->Update();

	spawnInterval += DELTA;

	if (spawnInterval > SPAWN_TIMER)
	{
		Spawning();
		spawnInterval -= SPAWN_TIMER;
	}
}

void EnemyManager::Render()
{
	for (Enemy* enemy : enemies)
		enemy->Render();

	enemyModel->Render();
}

void EnemyManager::Edit()
{
	//for (Enemy* enemy : enemies)
	//	enemy->Edit();

	enemyModel->Edit();
}

void EnemyManager::GetPlayer(SurvivalPlayer* player)
{
	for (Enemy* enemy : enemies)
		enemy->SetPlayer(player);
}

void EnemyManager::Spawning()
{
	for (Enemy* enemy : enemies)
	{
		if (!enemy->IsActive())
		{
			enemy->Spawn();
			return;
		}
	}
}


