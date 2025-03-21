#pragma once
class Enemy;
class Credit;

class SurvivalPlayer : public CapsuleCollider
{
private:
	const float HIT_INTERVAL = 1.0f;

public:
	SurvivalPlayer();
	~SurvivalPlayer();

	int curHp;
	int ownedMoney = 0;

public:
	void Update();
	void Render();
	void PostRender();
	void GetDamagedFromEnemy(Collider* collider);
	void ObtainMoney(Collider* collider);

private:
	void Control();
	void Move();
	void Fire();
	void Rotate();
	void GetInvincible();

	void CreateBullet();

private:
	Transform* transform;
	float moveSpeed = 7.0f;
	float rotSpeed = 1.0f;
	float hitTime = 0.0f;
	int maxHp = 10;

	Enemy* enemy;
	Credit* credit;

	Vector3 velocity;

	bool isInvincible = false;
};
