#pragma once

class UIMaker : public Singleton<UIMaker>
{
private:
	friend class Singleton;

private:
	UIMaker();
	~UIMaker();

public:
	void Update();
	void Render();
	void Edit();
	void PostRender();

	void SetPlayer(SurvivalPlayer* player) { this->player = player; }

private:
	void CreateUI();
	void CreateUIFont();

private:
	SurvivalPlayer* player = nullptr;
	Quad* heartCount;
	Quad* creditCount;

	ImageFont* heartFont;
	ImageFont* creditFont;
	ImageFont* timerFont;
};
