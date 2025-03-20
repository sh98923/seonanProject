#include "Framework.h"
#include "Tree.h"

Tree::Tree(Transform* transform)
	: BoxCollider(Vector3(3,10,3)), transform(transform)
{
	SetTag(transform->GetTag() + "_Collider");
	transform->SetParent(this);
	transform->SetLocalPosition(0, 5, 0);
	transform->SetLocalRotation(XM_PI, 0, 0);
	transform->SetLocalScale(3,3,3);
	transform->SetTag("tree");
	transform->Load();
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

void Tree::CollidedWithPlayer()
{
	if (IsCollision(player))
	{

	}
}
