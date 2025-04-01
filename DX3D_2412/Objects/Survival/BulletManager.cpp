#include "Framework.h"

BulletManager::BulletManager()
{
	bulletModel = new ModelInstancing("smgbullet", SIZE);

	bullets.reserve(SIZE);

	FOR(SIZE)
	{
		Bullet* bullet = new Bullet(bulletModel->Add());
		
		bullet->SetActive(false);

		bullets.push_back(bullet);
	}
}

BulletManager::~BulletManager()
{
	delete bulletModel;
}

void BulletManager::Update()
{
	for (Bullet* bullet : bullets)
		bullet->Update();

	bulletModel->Update();
}

void BulletManager::Render()
{
	bulletModel->Render();

	for (Bullet* bullet : bullets)
		bullet->Render();
}

void BulletManager::Edit()
{
	//for (Bullet* bullet : bullets)
	//	bullet->Edit();

	bulletModel->Edit();
}

void BulletManager::Fire(Vector3 pos, Vector3 direction)
{
	for (Bullet* bullet : bullets)
	{
		if (!bullet->IsActive())
		{
			bullet->Fire(pos, direction);
			return;
		}
	}
}

bool BulletManager::IsCollisionWithEnemy(Collider* collider)
{
	for (Bullet* bullet : bullets)
	{
		if (bullet->IsCollision(collider))
		{
			bullet->SetActive(false);
			return true;
		}
	}
	return false;
}
