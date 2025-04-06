#pragma once

class Enemy : public CapsuleCollider
{
public:
	enum EnemyState
	{
		RUNNING, DYING, NONE
	};
public:
	//UINT curEnemyCount = 0;

private:
	const float SPAWN_INTERVAL = 1.0f;

public:
	Enemy(Transform* transform);
	~Enemy();

	void Update();
	void Render();

	void ReadClips();
	void SetState(EnemyState state);
	void EnemyDead();
	//void PlayDying();

	void SetPlayer(SurvivalPlayer* player) { this->player = player; }

	//void GetHp() { return this->curHp; }

	void Spawn();
	void Trace();
	void GetDamaged();

	bool CheckParticleTrue() { return isParticlePlay; }
	ParticleSystem* GetEnemyDieParticle() { return dieParticle; }

public:
	int curHp;

private:
	Transform* transform;
	//ModelAnimatorInstancing* model;
	SurvivalPlayer* player = nullptr;
	ParticleSystem* dieParticle;

	//UINT index;

	EnemyState curState = RUNNING;

	Bullet* bullet;
	Credit* credit;

	float moveSpeed = 4.0f;
	Vector3 velocity;
	
	int maxHp = 3;

	bool isParticlePlay = false;
};
