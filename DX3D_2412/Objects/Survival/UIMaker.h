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

private:
	void CreateUI();

private:
	Quad* heartCount;
	Quad* zombieCount;
	Quad* creditCount;
};
