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


public:
	float curHp = 5;

private:
	Transform* transform;
	SurvivalPlayer* player = nullptr;
	Bullet* bullet;

	float moveSpeed = 5.0f;
	Vector3 velocity;
	
	float maxHp;
	
};
