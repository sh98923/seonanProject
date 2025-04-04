#include "Framework.h"

Enemy::Enemy(Transform* transform)
{
	SetTag(transform->GetTag() + "_Collider");

	transform->SetParent(this);
	transform->SetLocalPosition(0, -1, 0);
	transform->SetLocalScale(0.01f, 0.01f, 0.01f);
	transform->SetLocalRotation(0, XM_PI, 0);

	transform->SetTag("Enemy");
	Load();

	dieParticle = new ParticleSystem("resources/textures/UI/FX/zombiedie.fx");
	//EnemyManager::Get()->GetEnemyModel()->GetClip(1)->SetEvent(bind(&Enemy::EnemyDead,this),0.9f);
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
	dieParticle->Update();
	UpdateWorld();
	//model->Update();
}

void Enemy::Render()
{
	dieParticle->Render();
	if (IsActive())
	{
		Collider::Render();
	}
	//model->Render();
}

void Enemy::EnemyDead()
{
	SetActive(false);
}

//void Enemy::ReadClips()
//{
//	model->ReadClip("running");
//	model->ReadClip("dying");
//	model->CreateTexture();
//
//	model->GetClip(RUNNING)->SetEvent(bind(&Enemy::isDead, this), 0.1f);
//}

//void Enemy::SetState(EnemyState state)
//{
//	curState == state;
//	model->PlayClip(state);
//}
//
//void Enemy::IsDead()
//{
//	SetState(DYING);
//}
//
//void Enemy::PlayDying()
//{
//	model->GetClip(DYING)->SetEvent(bind(&Enemy::isDead, this), 0.1f);
//}

void Enemy::Spawn()
{
	//curEnemyCount++;
	curHp = maxHp;
	SetColor(0, 1, 0);
	SetLocalPosition(GameMath::Random(Vector3(-24.0f, 2.0f, -24.0f), Vector3(24.0f, 2.0f, 24.0f)));
	SetActive(true);
}

void Enemy::Trace()
{
	if(IsActive())
	{
		Vector3 dir = (player->GetLocalPosition() - GetLocalPosition()).GetNormalized();
		Translate(dir * moveSpeed * DELTA);
		localRotation.y = atan2(dir.x, dir.z);

		//if (IsCollision(player))
		//	moveSpeed = 0;
		//if (!IsCollision(player))
		//{
		//	Vector3 dir = (player->GetLocalPosition() - GetLocalPosition()).GetNormalized();
		//	Translate(dir * moveSpeed * DELTA);
		//	localRotation.y = atan2(dir.x, dir.z);
		//}
	}
	
}

void Enemy::GetDamaged()
{
	if (BulletManager::Get()->IsCollisionWithEnemy(this))
	{
		curHp--;
		if (curHp == 2)
		{
			SetColor(0, 0, 0);
		}
		else if (curHp == 1)
		{
			SetColor(1, 1, 1);
		}
		else if (curHp == 0)
		{
			dieParticle->Play(localPosition);
			CreditManager::Get()->SpawnCredit(GetGlobalPosition());
			SetActive(false);
			//curHp = maxHp;
		}
	}
}

