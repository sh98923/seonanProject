#include "Framework.h"
#include "SurvivalScene.h"

SurvivalScene::SurvivalScene()
{
	player = new SurvivalPlayer();
	player->SetLocalPosition(0, 2, 0);

	EnemyManager::Get()->GetPlayer(player);
	CreditManager::Get()->GetPlayer(player);
	TreeManager::Get()->Make();

	Font::Get()->AddStyle("HP", L"배달의민족 을지로체 TTF", 40);
	Font::Get()->AddColor("Yellow", 0, 1, 1);

	//skybox = new Skybox(L"Resources/Textures/Landscape/Snow_ENV.dds");

	plane = new Plane(Vector2(150, 150), 2, 2);
	plane->SetLocalPosition(-75, 0, -75);
	plane->UpdateWorld();
	plane->GetMaterial()->SetDiffuseMap(L"Resources/Textures/Landscape/survivalground3.png");
	plane->GetMaterial()->SetNormalMap(L"Resources/Textures/Landscape/SurvivalNormal3.png");
}

SurvivalScene::~SurvivalScene()
{
	TreeManager::Delete();
	EnemyManager::Delete();
	CreditManager::Delete();
	
	delete player;
	delete plane;
}

void SurvivalScene::Update()
{
	TreeManager::Get()->Update();
	EnemyManager::Get()->Update();
	CreditManager::Get()->Update();
	player->Update();
	//enemy->Update();
}

void SurvivalScene::PreRender()
{
}

void SurvivalScene::Render()
{
	//skybox->Render();
	TreeManager::Get()->Render();
	EnemyManager::Get()->Render();
	CreditManager::Get()->Render();
	player->Render();
	//enemy->Render();
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
	//EnemyManager::Get()->Edit();
	//BulletManager::Get()->Edit();
	TreeManager::Get()->Edit();
}
