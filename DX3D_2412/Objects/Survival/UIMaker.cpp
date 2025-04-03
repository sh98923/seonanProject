#include "Framework.h"

UIMaker::UIMaker()
{
	CreateUI();
}

UIMaker::~UIMaker()
{
	delete heartCount;
	delete zombieCount;
	delete creditCount;
}

void UIMaker::Update()
{
}

void UIMaker::Render()
{
	Environment::Get()->SetAlphaBlend(true);
	heartCount->Render();
	//zombieCount->Render();
	creditCount->Render();
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
	//heartCount->GetMaterial()->GetData()->diffuse = { 1, 1, 1, 0 };
	heartCount->SetLocalScale(0.06f, 0.06f, 0.06f);
	heartCount->SetLocalPosition(25, 680, 0);
	heartCount->UpdateWorld();
	
	creditCount = new Quad(L"Resources/Textures/UI/credit.png");
	creditCount->SetLocalScale(0.14f, 0.14f, 0.14f);
	creditCount->SetLocalPosition(25, 650, 0);
	creditCount->UpdateWorld();

	//zombieCount = new Quad(L"Resources/Textures/UI/zombie.png");
	//zombieCount->SetLocalScale(0.035f, 0.035f, 0.035f);
	//zombieCount->SetLocalPosition(25, 617, 0);
	//zombieCount->UpdateWorld();
}