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

private:
	void CreateUI();

private:
	Quad* heartCount;
	Quad* zombieCount;
	Quad* creditCount;
};
