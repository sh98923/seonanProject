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

	spawnInterval += DELTA;

	if (spawnInterval > SPAWN_TIMER)
	{
		Spawning();
		spawnInterval -= SPAWN_TIMER;
	}

	enemyModel->Update();
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

//void EnemyManager::GetDamagedFromBullet(Collider* collider)
//{
//	for (Enemy* enemy : enemies)
//	{
//		if (enemy->IsCollision(collider))
//		{
//			//enemy->SetColor(1, 0, 0);
//			enemy->curHp--;
//			//DropCredit();
//			if (enemy->curHp == 4)
//			{
//				enemy->SetColor(1, 0, 0);
//			}
//			else if (enemy->curHp == 3)
//			{
//				enemy->SetColor(0, 0, 1);
//			}
//			else if (enemy->curHp == 2)
//			{
//				enemy->SetColor(0, 0, 0);
//			}
//			else if (enemy->curHp == 1)
//			{
//				enemy->SetColor(1, 1, 1);
//			}
//			else if (enemy->curHp == 0)
//			{
//				enemy->SetActive(false);
//				CreditManager::Get()->SpawnCredit(enemy->GetGlobalPosition());
//			}
//			return;
//		}
//	}
//}

void EnemyManager::DropCredit()
{
	for (Enemy* enemy : enemies)
	{
		if (enemy->IsActive() && enemy->curHp <= 0)
		{
			
		}
	}
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


