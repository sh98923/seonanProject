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

	ParticleManager::Get();
	//dieParticle = new ParticleSystem("resources/textures/UI/FX/zombiedie.fx");
	//EnemyManager::Get()->GetEnemyModel()->GetClip(1)->SetEvent(bind(&Enemy::EnemyDead,this),0.9f);
} 

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (!IsActive()) return;

	//if (!dieParticle->IsActive()) isParticlePlay = false;

	Trace();
	GetDamaged();
	//BulletManager::Get()->IsCollisionWithEnemy(this);
	ParticleManager::Get()->Update();
	player->GetDamagedFromEnemy(this);
	UpdateWorld();
}

void Enemy::Render()
{
	if (IsActive())
	{
		Collider::Render();
	}

	ParticleManager::Get()->Render();
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
	int spawnProbability = GameMath::Random(1, 100);
	
	if (BulletManager::Get()->IsCollisionWithEnemy(this))
	{
		curHp--;
		if (curHp == 0)
		{
			ParticleManager::Get()->PlayDieParticle(localPosition);

			if (spawnProbability > 80)
				CreditManager::Get()->SpawnItem(GetGlobalPosition());
			else 
				CreditManager::Get()->SpawnCredit(GetGlobalPosition());
			
			SetActive(false);
		}
	}
}

