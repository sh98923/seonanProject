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

	void CreateBullet();

private:
	Transform* transform;
	float moveSpeed = 7.0f;
	float rotSpeed = 1.0f;
	float hitTime = 0.0f;
	unordered_map<Collider*, float> enemyHitTimes;
	unordered_map<Collider*, bool> isDamaged;

	Enemy* enemy;
	Credit* credit;

	int maxHp = 10;
	Vector3 velocity;
};
