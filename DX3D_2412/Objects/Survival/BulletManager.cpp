#include "Framework.h"

BulletManager::BulletManager()
{
	bulletModel = new ModelInstancing("Arrow", SIZE);

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
	for (Bullet* bullet : bullets)
		bullet->Render();

	bulletModel->Render();
}

void BulletManager::Edit()
{
	bulletModel->Edit();

	for (Bullet* bullet : bullets)
		bullet->Edit();
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

void BulletManager::IsCollisionWithEnemy(Collider* collider)
{
	for (Bullet* bullet : bullets)
	{
		if (bullet->IsCollision(collider))
		{
			bullet->SetActive(false);
			return;
		}
	}
}
