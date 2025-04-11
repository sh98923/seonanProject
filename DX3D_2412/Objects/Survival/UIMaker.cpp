#include "Framework.h"

UIMaker::UIMaker()
{
	CreateUI();
	CreateUIFont();
}

UIMaker::~UIMaker()
{
	delete heartCount;
	delete creditCount;

	delete heartFont;
	delete creditFont;
}

void UIMaker::Update()
{
	if (player->curHp == -1)
	{
		int d = 2;
	}
	heartFont->SetValue(player->curHp);
	
	creditFont->SetValue(player->ownedMoney);
}

void UIMaker::Render()
{
	Environment::Get()->SetAlphaBlend(true);
	heartCount->Render();
	creditCount->Render();
	
	heartFont->Render();
	creditFont->Render(); 
	Environment::Get()->SetAlphaBlend(false);
}

void UIMaker::Edit()
{
}

void UIMaker::PostRender()
{
}

void UIMaker::CreateUI()
{
	heartCount = new Quad(L"Resources/Textures/UI/heart.png");
	heartCount->SetLocalScale(0.06f, 0.06f, 0.06f);
	heartCount->SetLocalPosition(25, 680, 0);
	heartCount->UpdateWorld();
	
	creditCount = new Quad(L"Resources/Textures/UI/credit.png");
	creditCount->SetLocalScale(0.14f, 0.14f, 0.14f);
	creditCount->SetLocalPosition(25, 650, 0);
	creditCount->UpdateWorld();
}

void UIMaker::CreateUIFont()
{
	heartFont = new ImageFont(L"Resources/Textures/UI/Font/");
	heartFont->SetLocalPosition(80, SCREEN_HEIGHT - 40, 0);
	heartFont->SetAligned(ImageFont::R);
	heartFont->UpdateWorld();

	creditFont = new ImageFont(L"Resources/Textures/UI/Font/");
	creditFont->SetLocalPosition(80, SCREEN_HEIGHT - 70, 0);
	creditFont->SetAligned(ImageFont::R);
	creditFont->UpdateWorld();
}
