#include "Framework.h"
#include "Item.h"

Item::Item(Transform* transform)
	: SphereCollider(0.4f), transform(transform)
{
	SetTag(transform->GetTag() + "_Collider");
	transform->SetParent(this);

	transform->SetLocalPosition(0, -1.0f, 0);
	Rotate(Vector3::Up(), XM_PI / 2);

	size_t pos = transform->GetTag().find("heart");
	if (pos != transform->GetTag().npos)
	{
		string sub = tag.substr(pos, 5);

		if (sub == "heart")
		{
			transform->SetLocalScale(0.2f, 0.2f, 0.2f);
		}
	}

	transform->SetTag("item");
	Load();
}

Item::~Item()
{
}

void Item::Update()
{
	if (!IsActive()) return;

	ItemFloating();
	player->ObtainMoney(this);
	PickedUpItemToPlayer();
	UpdateWorld();
}

void Item::Render()
{
	if (!isActive)
		return;
	Collider::Render();
}

void Item::PickedUpItemToPlayer()
{
	Vector3 pos = (player->GetLocalPosition() - GetLocalPosition()).GetNormalized();
	float dir = Vector3::Distance(GetLocalPosition(), player->GetLocalPosition());

	if (dir < pickUpRange)
	{
		Vector3 newPos = GameMath::Lerp(GetLocalPosition(), player->GetLocalPosition(), 0.3f * pickUpSpeed * DELTA);

		SetLocalPosition(newPos);
	}
}

void Item::ItemFloating()
{
	Rotate(Vector3::Up(), DELTA);

	floatingTime += DELTA;
	float floatOffset = sinf(floatingTime * 2.5f) * DELTA * 0.2f;
	Translate(Vector3::Up() * floatOffset);
}
