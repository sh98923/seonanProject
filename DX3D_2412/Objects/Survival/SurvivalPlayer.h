#pragma once

class SurvivalPlayer : public CapsuleCollider
{
public:
	SurvivalPlayer();
	~SurvivalPlayer();

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

	Vector3 velocity;
};
