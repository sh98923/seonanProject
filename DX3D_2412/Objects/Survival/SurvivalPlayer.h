#pragma once

class SurvivalPlayer : public CapsuleCollider
{
public:
	SurvivalPlayer();
	~SurvivalPlayer();

	int curHp = 10;

public:
	void Update();
	void Render();
	void PostRender();

private:
	void Control();
	void Move();
	void Fire();
	void Rotate();

	void CreateBullet();

private:
	float moveSpeed = 7.0f;
	float rotSpeed = 1.0f;

	int maxHp;
	Vector3 velocity;
};
