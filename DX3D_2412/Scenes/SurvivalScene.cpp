#include "Framework.h"
#include "SurvivalScene.h"

SurvivalScene::SurvivalScene()
{
	EnemyManager::Get();
	CreditManager::Get();
	player = new SurvivalPlayer();
	player->SetLocalPosition(0, 2, 0);
	EnemyManager::Get()->GetPlayer(player);

	plane = new Plane(Vector2(50, 50), 2, 2);
	plane->SetLocalPosition(-25, 0, -25);
	plane->UpdateWorld();
	plane->GetMaterial()->SetDiffuseMap(L"Resources/Textures/Landscape/Box.png");
}

SurvivalScene::~SurvivalScene()
{
	EnemyManager::Delete();
	delete player;
	delete plane;
}

void SurvivalScene::Update()
{
	EnemyManager::Get()->Update();
	CreditManager::Get()->Update();
	player->Update();
}

void SurvivalScene::PreRender()
{
}

void SurvivalScene::Render()
{
	EnemyManager::Get()->Render();
	CreditManager::Get()->Render();
	player->Render();
	plane->Render();
}

void SurvivalScene::PostRender()
{
	player->PostRender();
	string Hp = "HP : " + to_string(player->curHp);
	Font::Get()->RenderText(Hp, { 80, SCREEN_HEIGHT - 40 });
}

void SurvivalScene::GUIRender()
{
	player->Edit();
	EnemyManager::Get()->Edit();
	BulletManager::Get()->Edit();
}
