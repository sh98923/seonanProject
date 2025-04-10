#pragma once

class Item : public SphereCollider
{
public:
	Item(Transform* transform);
	~Item();

	void Update();
	void Render();

	void SetPlayer(SurvivalPlayer* player) { this->player = player; }

	void PickedUpItemToPlayer();

	void ItemFloating();

private:
	Transform* transform;
	SurvivalPlayer* player = nullptr;

	float pickUpSpeed = 13.0f;
	float pickUpRange = 10.0f;
	float floatingTime;
};
