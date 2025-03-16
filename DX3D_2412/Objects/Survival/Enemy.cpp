#include "Framework.h"

Enemy::Enemy(Transform* transform)
	: CapsuleCollider(), transform(transform)
{
	SetTag(transform->GetTag() + "_Collider");
	transform->SetParent(this);
	transform->SetTag("Enemy");
	transform->Load();
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (!IsActive()) return;
	Trace();
	BulletManager::Get()->IsCollisionWithEnemy(this);
	player->GetDamagedFromEnemy(this);
	UpdateWorld();
}

void Enemy::Render()
{
	if (IsActive())
	{
		Collider::Render();
	}
			
	//Render();
}

void Enemy::Spawn()
{
	curHp = maxHp;
	SetColor(0, 1, 0);
	SetActive(true);
	SetLocalPosition(GameMath::Random(Vector3(-30.0f, 1.0f, -30.0f), Vector3(30.0f, 1.0f, 30.0f)));
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

