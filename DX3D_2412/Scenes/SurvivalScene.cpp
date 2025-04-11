#include "Framework.h"
#include "SurvivalScene.h"

SurvivalScene::SurvivalScene()
{
	player = new SurvivalPlayer();
	player->SetLocalPosition(0, 2, 0);

	EnemyManager::Get()->GetPlayer(player);
	ItemManager::Get()->GetPlayer(player);
	UIMaker::Get()->SetPlayer(player);
	TreeManager::Get()->Make();

	plane = new Plane(Vector2(150, 150), 2, 2);
	plane->SetLocalPosition(-75, 0, -75);
	plane->GetMaterial()->SetDiffuseMap(L"Resources/Textures/Landscape/survivalground3.png");
	plane->GetMaterial()->SetNormalMap(L"Resources/Textures/Landscape/SurvivalNormal3.png");
	plane->UpdateWorld();

	valueBuffer = new FloatValueBuffer();
	valueBuffer->Get()[1] = SCREEN_WIDTH;
	valueBuffer->Get()[2] = SCREEN_HEIGHT;

	Audio::Get()->Add("Shot", "Resources/Sounds/shotsound.wav");
	//Audio::Get()->Add("BGM", "Resources/Sounds/survivalBGM2.wav",true);
	Audio::Get()->Add("BGM", "Resources/Sounds/survivalBGM.mp3",true);
	Audio::Get()->Add("HeartUp", "Resources/Sounds/heartupsound.wav");
	Audio::Get()->Add("PowerUp", "Resources/Sounds/powerupsound.wav");
	Audio::Get()->Add("CreditUp", "Resources/Sounds/creditupsound.wav");
	Audio::Get()->Add("PlayerHit", "Resources/Sounds/playerhitsound.mp3");

	Audio::Get()->Play("BGM",0.1f);
}

SurvivalScene::~SurvivalScene()
{
	TreeManager::Delete();
	EnemyManager::Delete();
	ItemManager::Delete();
	UIMaker::Delete();
	
	delete player;
	delete plane;
	delete valueBuffer;
}

void SurvivalScene::Update()
{
	TreeManager::Get()->Update();
	EnemyManager::Get()->Update();
	ItemManager::Get()->Update();
	UIMaker::Get()->Update();
	
	player->Update();
}

void SurvivalScene::PreRender()
{
}

void SurvivalScene::Render()
{
	plane->Render();

	TreeManager::Get()->Render();
	EnemyManager::Get()->Render();
	ItemManager::Get()->Render();
	
	player->Render();
}

void SurvivalScene::PostRender()
{
	player->PostRender();
	//string hp = "   : " + to_string(player->curHp);
	//Font::Get()->RenderText(hp, { 80, SCREEN_HEIGHT - 40 });
	//string money = " : " + to_string(player->ownedMoney);
	//Font::Get()->RenderText(money, { 80, SCREEN_HEIGHT - 70 });
	UIMaker::Get()->Render();
}

void SurvivalScene::GUIRender()
{
	player->Edit();
	//EnemyManager::Get()->Edit();
	//BulletManager::Get()->Edit();
	TreeManager::Get()->Edit();
}
