#pragma once

class Credit : public SphereCollider
{
public:
	Credit(Transform* transform);
	~Credit();

	void Update();
	void Render();
	void Edit();

	void SetTarget(SurvivalPlayer* target) { this->target = target; }

private:
	Transform* transform;
	SurvivalPlayer* target;

	float pullingForce = 100.0f;
};