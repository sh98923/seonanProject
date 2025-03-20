#pragma once

class Tree : public BoxCollider
{
public:
	Tree(Transform* transform);
	~Tree();

	void Update();
	void Render();
	void CollidedWithPlayer();

	void SetPlayer(SurvivalPlayer* player) { this->player = player; }

private:
	Transform* transform;
	SurvivalPlayer* player;
};
