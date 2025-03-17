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

private:
	Transform* transform;
	SurvivalPlayer* player = nullptr;

	float pullingRange = 100.0f;
};