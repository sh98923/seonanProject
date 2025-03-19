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

	void AbsorbedToPlayer();

private:
	Transform* transform;
	SurvivalPlayer* player = nullptr;

	float absorbedSpeed = 10.0f;
	float absorbRange = 10.0f;
};