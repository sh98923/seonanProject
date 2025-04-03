#pragma once
class Enemy;
class Credit;

class SurvivalPlayer : public CapsuleCollider
{
	enum PlayerState
	{
		SURVIVALIDLE, SURVIVALMOVE, GEARCHECKIDLE, GEARCHECKMOVE, NONE
		//aimingidle, walking, rifleidle
		// 전투씬 기본 , 움직이면서 사격 , 상점 기본 , 기본 이동
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
	void LimitMove();

	void ReturnToIdle();

	void ReadClips();

	void SetAction();
	void SetState(PlayerState state);

	void GetInvincible();

	void CreateBullet();

private:
	Transform* transform;
	ModelAnimator* playerModel;
	Model* weapon;
	Transform* weaponSocket;
	Enemy* enemy;
	Credit* credit;

	PlayerState curState = SURVIVALIDLE;

	Vector3 velocity;

	int maxHp = 10;
	float moveSpeed = 5.3f;
	float rotSpeed = 1.0f;
	float hitTime = 0.0f;

	bool isInvincible = false;
};
