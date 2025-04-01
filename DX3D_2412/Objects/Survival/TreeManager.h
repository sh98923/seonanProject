#pragma once

class TreeManager : public Singleton<TreeManager>
{
private:
	UINT treeSize = 13;

public:
	TreeManager();
	~TreeManager();

	void Update();
	void Render();
	void Edit();

	void Make();

	void GetPlayer(SurvivalPlayer* player);

private:
	ModelInstancing* treeModel;
	vector<Tree*> trees;

};
