#include "Framework.h"

Bullet::Bullet(Transform* transform)
	: SphereCollider(0.4f), transform(transform)
{
	SetTag(transform->GetTag() + "_Collider");
	transform->SetParent(this);
	transform->SetLocalScale(0.05f, 0.05f, 0.05f);
	transform->SetLocalRotation(XM_PIDIV2, 0, 0);
	transform->SetLocalPosition(0, 1.0f, 0);
	transform->SetTag("bullet_0");
	transform->Load();
}

Bullet::~Bullet()
{	
}

void Bullet::Update()
{
	if (!IsActive()) return;

	lifeTime += DELTA;

	if (lifeTime > LIFE_TIME)
		SetActive(false);

	Translate(velocity * speed * DELTA);
	//EnemyManager::Get()->GetDamagedFromBullet(this);
	UpdateWorld();	
}

void Bullet::Render()
{
	Collider::Render();	
}

void Bullet::Edit()
{
	transform->Edit();
	Transform::Edit();
}

void Bullet::Fire(Vector3 pos, Vector3 dir)
{
	localPosition = pos;
	velocity = dir;
	lifeTime = 0.0f;

	localRotation.y = atan2(dir.x, dir.z);

	SetActive(true);
}



