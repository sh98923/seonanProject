#pragma once

class Credit : public SphereCollider
{
public:
	Credit();
	~Credit();

	void Update();
	void Render();

private:
	float radius;
};