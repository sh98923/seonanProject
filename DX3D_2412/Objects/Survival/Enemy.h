#pragma once

class Enemy : public CapsuleCollider
{
private:
	const float SPAWN_INTERVAL = 1.0f;

public:
	Enemy(Transform* transform);
	~Enemy();

	void Update();
	void Render();

	void SetPlayer(SurvivalPlayer* player) { this->player = player; }

	void Spawn();
	void Trace();
	void GetDamaged();

public:
	int curHp;

private:
	Transform* transform;
	ModelAnimator* model;
	SurvivalPlayer* player = nullptr;
	Bullet* bullet;
	Credit* credit;

	float moveSpeed = 5.0f;
	Vector3 velocity;
	
	int maxHp = 5;
	
};
