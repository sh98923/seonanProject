#include "Framework.h"

TreeManager::TreeManager()
{
	treeModel = new ModelInstancing("pinetree", treeSize);

	trees.reserve(treeSize);

	FOR(treeSize)
	{
		Tree* tree = new Tree(treeModel->Add());
		tree->SetActive(false);

		trees.push_back(tree);
	}
}

TreeManager::~TreeManager()
{
	delete treeModel;
}

void TreeManager::Update()
{
	for (Tree* tree : trees)
		tree->Update();

	treeModel->Update();
}

void TreeManager::Render()
{
	for (Tree* tree : trees)
		tree->Render();

	treeModel->Render();
}

void TreeManager::Edit()
{
	for (Tree* tree : trees)
		tree->Edit();
}

void TreeManager::MakeSpace()
{
	for (Tree* tree : trees)
		tree->SetActive(true);
}

void TreeManager::GetPlayer(SurvivalPlayer* player)
{
	for (Tree* tree : trees)
		tree->SetPlayer(player);
}
