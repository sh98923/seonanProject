#pragma once
class Enemy;
class Credit;

class SurvivalPlayer : public CapsuleCollider
{
	enum PlayerState
	{
		DEFAULTIDLE, SURVIVEIDLE, MOVEFIRE, NONE
	};

private:
	const float HIT_INTERVAL = 1.0f;

public:
	int curHp;
	int ownedMoney = 0;

public:
	SurvivalPlayer();
	~SurvivalPlayer();

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

	void ReadClips();

	void GetInvincible();

	void SetAction();
	void SetState(PlayerState state);

	void CreateBullet();

private:
	Transform* transform;
	ModelAnimator* playerModel;
	Enemy* enemy;
	Credit* credit;

	PlayerState curState = DEFAULTIDLE;

	Vector3 velocity;

	int maxHp = 10;
	float moveSpeed = 7.0f;
	float rotSpeed = 1.0f;
	float hitTime = 0.0f;

	bool isInvincible = false;
};
