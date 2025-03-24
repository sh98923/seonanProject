#include "Framework.h"
#include "SurvivalPlayer.h"

SurvivalPlayer::SurvivalPlayer() : CapsuleCollider()
{
	playerModel = new ModelAnimator("myPlayer");
	playerModel->ReadClip("rifleidle");
	playerModel->CreateTexture();
	playerModel->PlayClip(0);
	playerModel->Load();
	playerModel->SetParent(this);

	//curState = PlayerState::DEFAULTIDLE;
	curHp = maxHp;
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
	SetState();
	Control();
	Move();
	Fire();
	Rotate();
	GetInvincible();
	ObtainMoney(credit);
	//GetDamagedFromEnemy(enemy);

	UpdateWorld();
	playerModel->Update();
	BulletManager::Get()->Update();
}

void SurvivalPlayer::Render()
{
	playerModel->Render();
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

void SurvivalPlayer::GetInvincible()
{
	if (!isInvincible) return;

	hitTime += DELTA;
	
	if (hitTime >= HIT_INTERVAL)
		isInvincible = false;
}

void SurvivalPlayer::SetState()
{
	//switch (curState)
	//{
	//case PlayerState::DEFAULTIDLE :
	//	//playerModel->ReadClip("rifleidle");
	//	playerModel->PlayClip(0);
	//	break;
	//case PlayerState::SURVIVEIDLE :
	//	break;
	//}
}

void SurvivalPlayer::CreateBullet()
{
	BulletManager::Get();
}

void SurvivalPlayer::GetDamagedFromEnemy(Collider* collider)
{
	if (collider == nullptr) return;
	if (isInvincible) return;

	if (this->IsCollision(collider))
	{
		isInvincible = true;
		curHp--;
		hitTime = 0.0f;
	}
}

void SurvivalPlayer::ObtainMoney(Collider* collider)
{
	if (collider == nullptr) return;

	if (this->IsCollision(collider))
	{
		collider->SetActive(false);
		ownedMoney++;
	}
}

