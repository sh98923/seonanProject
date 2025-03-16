#include "Framework.h"

Credit::Credit(Transform* transform)
	: SphereCollider(0.5f), transform(transform)
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
