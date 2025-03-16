#pragma once
class Enemy;
class SurvivalPlayer : public CapsuleCollider
{
private:
	const float HIT_INTERVAL = 1.0f;

public:
	SurvivalPlayer();
	~SurvivalPlayer();

	int curHp = 10;

public:
	void Update();
	void Render();
	void PostRender();
	void GetDamagedFromEnemy(Collider* collider);

private:
	void Control();
	void Move();
	void Fire();
	void Rotate();

	void CreateBullet();

private:
	Transform* transform;
	float moveSpeed = 7.0f;
	float rotSpeed = 1.0f;
	float hitTime = 0.0f;

	Enemy* enemy;

	int maxHp;
	Vector3 velocity;
};
