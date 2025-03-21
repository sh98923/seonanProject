#include "Framework.h"

Enemy::Enemy(Transform* transform)
	
{
	SetTag(transform->GetTag() + "_Collider");
	transform->SetParent(this);
	transform->SetTag("Enemy");
	transform->Load();

	//model = new ModelAnimator("zombie");
	//model->ReadClip("running");
	//model->CreateTexture();
	//model->PlayClip(0);
	//model->Load();
	//model->SetParent(this);
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (!IsActive()) return;
	Trace();
	GetDamaged();
	//BulletManager::Get()->IsCollisionWithEnemy(this);
	player->GetDamagedFromEnemy(this);
	UpdateWorld();
	//model->Update();
}

void Enemy::Render()
{
	if (IsActive())
	{
		Collider::Render();
	}
	//model->Render();
}

void Enemy::Spawn()
{
	curHp = maxHp;
	SetColor(0, 1, 0);
	SetActive(true);
	SetLocalPosition(GameMath::Random(Vector3(-30.0f, 2.0f, -30.0f), Vector3(30.0f, 2.0f, 30.0f)));
}

void Enemy::Trace()
{
	if (IsActive())
	{
		Vector3 dir = (player->GetLocalPosition() - GetLocalPosition()).GetNormalized();
		Translate(dir * moveSpeed * DELTA);
		localRotation.y = atan2(dir.x, dir.z);
	}
}

void Enemy::GetDamaged()
{
	if (BulletManager::Get()->IsCollisionWithEnemy(this))
	{
		curHp--;
		if (curHp == 4)
		{
			SetColor(1, 0, 0);
		}
		else if (curHp == 3)
		{
			SetColor(0, 0, 1);
		}
		else if (curHp == 2)
		{
			SetColor(0, 0, 0);
		}
		else if (curHp == 1)
		{
			SetColor(1, 1, 1);
		}
		else if (curHp == 0)
		{
			CreditManager::Get()->SpawnCredit(GetGlobalPosition());
			SetActive(false);
			curHp = maxHp;
		}
	}
}

