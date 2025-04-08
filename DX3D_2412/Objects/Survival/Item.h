#pragma once

class Item : public SphereCollider
{
public:
	Item(Transform* transform);
	~Item();

	void Update();
	void Render();

private:
	Transform* transform;
};
