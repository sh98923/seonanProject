#include "Framework.h"

EnemyManager::EnemyManager()
{
	enemyModel = new ModelAnimatorInstancing("Zombie");
	
	enemyModel->ReadClip("running");
	enemyModel->ReadClip("dying");
	enemyModel->CreateTexture();

	//enemyModel->GetClip(DIE)->SetEvent(bind(&Enemy::EnemyDead, this), 0.9f);

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

	for (Enemy* enemy : enemies)
		delete enemy;
}

void EnemyManager::Update()
{
	spawnInterval += DELTA;

	if (spawnInterval > SPAWN_TIMER)
	{
		Spawning();
		spawnInterval -= SPAWN_TIMER;
	}

	
	enemyModel->Update();

	for (Enemy* enemy : enemies)
		enemy->Update();
}

void EnemyManager::Render()
{
	enemyModel->Render();

	for (Enemy* enemy : enemies)
		enemy->Render();
}

void EnemyManager::Edit()
{
	for (Enemy* enemy : enemies)
		enemy->Edit();

	enemyModel->Edit();
}

void EnemyManager::PlayDying()
{
	for( int i = 0; i < enemyCount; i++)
	{
		if(enemies[i]->IsActive() && enemies[i]->curHp <= 0)
		{
			if (enemyModel->IsSameClip(i, DIE))
				continue;

			enemyModel->PlayClip(i, DIE);			
		}
	}
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

//void EnemyManager::DropCredit()
//{
//	for (Enemy* enemy : enemies)
//	{
//		if (enemy->IsActive() && enemy->curHp <= 0)
//		{
//			
//		}
//	}
//}

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


