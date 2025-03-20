#pragma once

class TreeManager : public Singleton<TreeManager>
{
private:
	UINT treeSize = 10;

public:
	TreeManager();
	~TreeManager();

	void Update();
	void Render();
	void Edit();

	void MakeSpace();

	void GetPlayer(SurvivalPlayer* player);

private:
	ModelInstancing* treeModel;
	vector<Tree*> trees;

};
