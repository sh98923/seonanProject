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
	Spawn();
	Trace();
	UpdateWorld();
}

void Enemy::Render()
{
	if(IsActive())
	{
		Collider::Render();
	}
		
	//Render();
}

void Enemy::Spawn()
{
	isActive = true;
	SetLocalPosition(GameMath::Random(Vector3(-25.0f, 1.0f, -25.0f), Vector3(25.0f, 1.0f, 25.0f)));
}

void Enemy::Trace()
{
	if (IsActive())
	{
		Vector3 dir = player->GetLocalPosition() - GetLocalPosition();
		Translate(dir * moveSpeed * DELTA);
	}
}

