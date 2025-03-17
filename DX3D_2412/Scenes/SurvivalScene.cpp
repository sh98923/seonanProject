#include "Framework.h"
#include "SurvivalScene.h"

SurvivalScene::SurvivalScene()
{
	EnemyManager::Get();
	CreditManager::Get();
	player = new SurvivalPlayer();
	player->SetLocalPosition(0, 2, 0);
	EnemyManager::Get()->GetPlayer(player);
	CreditManager::Get()->GetPlayer(player);

	plane = new Plane(Vector2(70, 70), 2, 2);
	plane->SetLocalPosition(-35, 0, -35);
	plane->UpdateWorld();
	plane->GetMaterial()->SetDiffuseMap(L"Resources/Textures/Landscape/SurvivalGround3.png");
	plane->GetMaterial()->SetNormalMap(L"Resources/Textures/Landscape/SurvivalNormal3.png");
}

SurvivalScene::~SurvivalScene()
{
	EnemyManager::Delete();
	CreditManager::Delete();
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
	string hp = "HP : " + to_string(player->curHp);
	Font::Get()->RenderText(hp, { 80, SCREEN_HEIGHT - 40 });
	string money = "MONEY : " + to_string(player->ownedMoney);
	Font::Get()->RenderText(money, { 100, SCREEN_HEIGHT - 70 });
}

void SurvivalScene::GUIRender()
{
	player->Edit();
	EnemyManager::Get()->Edit();
	BulletManager::Get()->Edit();
}
