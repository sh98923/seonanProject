#include "Framework.h"
#include "Item.h"

Item::Item(Transform* transform) 
	: SphereCollider(), transform(transform)
{
}

Item::~Item()
{
}

void Item::Update()
{
}

void Item::Render()
{
}
