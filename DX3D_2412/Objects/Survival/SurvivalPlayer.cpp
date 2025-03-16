#include "Framework.h"
#include "SurvivalPlayer.h"

SurvivalPlayer::SurvivalPlayer() : CapsuleCollider()
{

	CAM->SetTarget(this);
	CAM->TargetOptionLoad("ShootingView");

	CreateBullet();
}

SurvivalPlayer::~SurvivalPlayer()
{
	BulletManager::Delete();
}

void SurvivalPlayer::Update()
{
	Control();
	Move();
	Fire();
	Rotate();
	GetDamagedFromEnemy(enemy);

	UpdateWorld();

	BulletManager::Get()->Update();
}

void SurvivalPlayer::Render()
{
	CapsuleCollider::Render();

	BulletManager::Get()->Render();
}

void SurvivalPlayer::PostRender()
{
}

void SurvivalPlayer::Control()
{
	Vector3 dir;

	if (KEY->Press('W'))
		dir += Vector3::Forward();
	if (KEY->Press('S'))
		dir += Vector3::Back();
	if (KEY->Press('A'))
		dir += Vector3::Left();
	if (KEY->Press('D'))
		dir += Vector3::Right();

	dir.Normalize();

	velocity.x = dir.x;
	velocity.z = dir.z;
}

void SurvivalPlayer::Move()
{
	Translate(velocity * moveSpeed * DELTA);
}

void SurvivalPlayer::Fire()
{
	if (KEY->Down(VK_LBUTTON))
	{
		BulletManager::Get()->Fire(localPosition, GetForward());
	}
}

void SurvivalPlayer::Rotate()
{
	Vector3 screenPos = CAM->WorldToScreenPoint(localPosition);

	Vector3 direction = (mousePos - screenPos).GetNormalized();

	float angle = atan2(direction.x, direction.y);

	localRotation.y = angle;
}

void SurvivalPlayer::CreateBullet()
{
	BulletManager::Get();
}

void SurvivalPlayer::GetDamagedFromEnemy(Collider* collider)
{
	if (collider == nullptr) return;

	if (this->IsCollision(collider))
	{
		hitTime += DELTA;

		if (hitTime >= HIT_INTERVAL)
		{
			this->curHp--;
			hitTime -= HIT_INTERVAL;
			return;
		}
	}
}

