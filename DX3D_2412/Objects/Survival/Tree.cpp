#include "Framework.h"
#include "Tree.h"

Tree::Tree(Transform* transform)
	: BoxCollider(), transform(transform)
{
	SetTag(transform->GetTag() + "_Collider");
	transform->SetParent(this);
	transform->SetLocalPosition(0, 0, 0);
	transform->SetLocalRotation(XM_PIDIV2, 0, 0);
	transform->SetLocalScale(15, 15, 15);
	transform->SetTag("pinetreegroup");
	Load();
}

Tree::~Tree()
{
}

void Tree::Update()
{
	
	UpdateWorld();
}

void Tree::Render()
{
	Collider::Render();
}
