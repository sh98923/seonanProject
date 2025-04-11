#pragma once

class SurvivalScene : public Scene
{
public:
	SurvivalScene();
	~SurvivalScene();

	virtual void Update() override;
	virtual void PreRender() override;
	virtual void Render() override;
	virtual void PostRender() override;
	virtual void GUIRender() override;

private:
	Enemy* enemy;
	Bullet* bullet;
	SurvivalPlayer* player;
	Tree* tree;

	Plane* plane;

	FloatValueBuffer* valueBuffer;
};