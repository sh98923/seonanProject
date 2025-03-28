#include "Framework.h"
#include "ModelEquipScene.h"

ModelEquipScene::ModelEquipScene()
{
	modelAnimator = new ModelAnimator("myplayer");
	modelAnimator->Load();
	modelAnimator->ReadClip("aimingidle");
	modelAnimator->ReadClip("walking");
	modelAnimator->ReadClip("rifleidle");
	modelAnimator->CreateTexture();

	weapon = new Model("rifle");
	weapon->Load();
	
	weaponSocket = new Transform();
	weapon->SetParent(weaponSocket);
	//
	//arrow = new Model("Arrow");
	//arrow->Load();
	//
	//arrowSocket = new Transform();
	//arrow->SetParent(arrowSocket);
}

ModelEquipScene::~ModelEquipScene()
{
	delete modelAnimator;
	delete weapon;
	delete weaponSocket;
}

void ModelEquipScene::Update()
{
	weaponSocket->SetWorld(modelAnimator->GetTransformByNode(31));
	//arrowSocket->SetWorld(modelAnimator->GetTransformByNode(36));

	modelAnimator->UpdateWorld();
	weapon->UpdateWorld();
	//arrow->UpdateWorld();
}

void ModelEquipScene::PreRender()
{
}

void ModelEquipScene::Render()
{
	modelAnimator->Render();
	weapon->Render();
	//arrow->Render();
}

void ModelEquipScene::PostRender()
{
}

void ModelEquipScene::GUIRender()
{
	modelAnimator->Edit();
	weapon->Edit();
	//arrow->Edit();
}
