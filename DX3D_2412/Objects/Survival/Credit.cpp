#include "Framework.h"

Credit::Credit(Transform* transform)
	: SphereCollider(0.4f), transform(transform)
{
	SetTag(transform->GetTag() + "_Collider");
	transform->SetParent(this); 
	transform->SetLocalPosition(0, -1.0f, 0);
	transform->SetLocalRotation(XM_PIDIV2, 0, 0);
	transform->SetLocalScale(5, 5, 5);
	transform->SetTag("Credit");
	transform->Load();
}

Credit::~Credit()
{
}

void Credit::Update()
{
	if (!IsActive()) return;
	
	player->ObtainMoney(this);
	PickedUpToPlayer();
	UpdateWorld();
}

void Credit::Render()
{
	if (!isActive)
		return;
	Collider::Render();
}

void Credit::Edit()
{
	Transform::Edit();
}

void Credit::PickedUpToPlayer()
{
	Vector3 pos = (player->GetLocalPosition() - GetLocalPosition()).GetNormalized();
	float dir = Vector3::Distance(GetLocalPosition() , player->GetLocalPosition());
	
	//if (absorbRange > dir.x)
	if (dir < pickUpRange)
	{
		//Translate(pos * pickUpSpeed * DELTA);
		Vector3 newPos = GameMath::Lerp(GetLocalPosition(), player->GetLocalPosition(), 0.3f * pickUpSpeed * DELTA);

		SetLocalPosition(newPos);
	}
}
