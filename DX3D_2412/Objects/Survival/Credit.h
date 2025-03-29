#pragma once

class Credit : public SphereCollider
{
public:
	Credit(Transform* transform);
	~Credit();

	void Update();
	void Render();
	void Edit();

	void SetPlayer(SurvivalPlayer* player) { this->player = player; }

	void PickedUpToPlayer();

private:
	Transform* transform;
	SurvivalPlayer* player = nullptr;

	float pickUpSpeed = 13.0f;
	float pickUpRange = 10.0f;
};