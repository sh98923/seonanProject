#include "Framework.h"
#include "CreditManager.h"

CreditManager::CreditManager()
{
	creditModel = new ModelInstancing("money", POOL_SIZE);

	credits.reserve(POOL_SIZE);

	FOR(POOL_SIZE)
	{
		Credit* credit = new Credit(creditModel->Add());
		credit->SetActive(false);

		credits.push_back(credit);
	}
}

CreditManager::~CreditManager()
{
	delete creditModel;
}

void CreditManager::Update()
{
	for (Credit* credit : credits)
		credit->Update();

	creditModel->Update();
}

void CreditManager::Render()
{
	creditModel->Render();

	for (Credit* credit : credits)
		credit->Render();
}

void CreditManager::Edit()
{
	creditModel->Edit();
}

void CreditManager::GetPlayer(SurvivalPlayer* player)
{
	for (Credit* credit : credits)
		credit->SetPlayer(player);
}

void CreditManager::SpawnCredit(Vector3 pos)
{
	for (Credit* credit : credits)
	{
		if (!credit->IsActive())
		{
			credit->SetActive(true);
			credit->SetLocalPosition(pos);
			return;
		}
	}
}
