#include "Framework.h"
#include "SurvivalPlayer.h"

SurvivalPlayer::SurvivalPlayer()
{
	Load();

	playerModel = new ModelAnimator("myPlayer");
	playerModel->Load();
	playerModel->SetParent(this);
	playerModel->SetLocalPosition(0, -1, 0);

	ReadClips();
	
	curHp = maxHp;
	CAM->SetTarget(this);
	CAM->TargetOptionLoad("ShootingView");

	CreateBullet();
}

SurvivalPlayer::~SurvivalPlayer()
{
	delete playerModel;
	BulletManager::Delete();
}

void SurvivalPlayer::Update()
{
	Control();
	Move();
	Fire();
	Rotate();
	SetAction();
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
	//if (curState == MOVEFIRE) return;
	
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
	//if (curState == MOVEFIRE) return;
	Translate(velocity * moveSpeed * DELTA);
}

void SurvivalPlayer::Fire()
{
	if (KEY->Down(VK_LBUTTON))
	{
		SetState(SURVIVALMOVE);
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

void SurvivalPlayer::ReturnToIdle()
{
	SetState(SURVIVALIDLE);
}

void SurvivalPlayer::ReadClips()
{
	playerModel->ReadClip("aimingidle");
	playerModel->ReadClip("walking");
	playerModel->ReadClip("rifleidle");
	playerModel->CreateTexture();

	playerModel->GetClip(SURVIVALMOVE)->SetEvent(bind(&SurvivalPlayer::Fire, this), 0.1f);
	playerModel->GetClip(SURVIVALMOVE)->SetEvent(bind(&SurvivalPlayer::ReturnToIdle, this), 0.3f);
}

void SurvivalPlayer::SetAction()
{
	if (curState == SURVIVALMOVE) return;

	else SetState(SURVIVALIDLE);
}

void SurvivalPlayer::SetState(PlayerState state)
{
	if (curState == state) return;

	curState = state;
	playerModel->PlayClip(state);
}

void SurvivalPlayer::GetInvincible()
{
	if (!isInvincible) return;

	hitTime += DELTA;

	if (hitTime >= HIT_INTERVAL)
		isInvincible = false;
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

