#pragma once

class Enemy : public CapsuleCollider
{
public:
	enum EnemyState
	{
		RUNNING, DYING, NONE
	};

private:
	const float SPAWN_INTERVAL = 1.0f;

public:
	Enemy(Transform* transform);
	~Enemy();

	void Update();
	void Render();

	void ReadClips();

	void SetPlayer(SurvivalPlayer* player) { this->player = player; }

	void Spawn();
	void Trace();
	void GetDamaged();

	bool isDead() { return curHp <= 0;}

public:
	int curHp;

private:
	Transform* transform;
	ModelAnimatorInstancing* model;
	SurvivalPlayer* player = nullptr;

	//UINT index;

	EnemyState curState = RUNNING;

	Bullet* bullet;
	Credit* credit;

	float moveSpeed = 3.0f;
	Vector3 velocity;
	
	int maxHp = 5;
	
};
