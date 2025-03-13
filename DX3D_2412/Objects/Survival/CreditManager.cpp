#include "Framework.h"
#include "CreditManager.h"

CreditManager::CreditManager()
{
	//creditModel = new ModelInstancing("Arrow", POOL_SIZE);

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
	for (Credit* credit : credits)
		credit->Render();

	//creditModel->Render();
}

void CreditManager::Edit()
{
	creditModel->Edit();
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
