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
	
	weapon = new Model("rifle");
	weapon->Load();

	weaponSocket = new Transform();
	weapon->SetParent(weaponSocket);

	particle = new ParticleSystem("Resources/Textures/UI/FX/fire.fx");

	curHp = maxHp;
	CAM->SetTarget(this);
	CAM->TargetOptionLoad("ShootingView");

	CreateBullet();
}

SurvivalPlayer::~SurvivalPlayer()
{
	delete playerModel;
	delete weapon;
	BulletManager::Delete();
}

void SurvivalPlayer::Update()
{
	Control();
	Move();
	Fire();
	Rotate();
	LimitMove();
	SetAction();
	GetInvincible();
	ObtainMoney(credit);
	//GetDamagedFromEnemy(enemy);

	weaponSocket->SetWorld(playerModel->GetTransformByNode(31));
	particle->Update();

	UpdateWorld();
	weapon->UpdateWorld();
	playerModel->Update();
	BulletManager::Get()->Update();
}

void SurvivalPlayer::Render()
{
	playerModel->Render();
	weapon->Render();
	
	CapsuleCollider::Render();	
	BulletManager::Get()->Render();
	particle->Render();
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
	Vector3 weaponFrontPos = weapon->GetGlobalPosition();// +(weapon->GetGlobalPosition().GetNormalized() * Vector3::Forward()); 
	Vector3 dir = (weapon->GetGlobalPosition() - GetGlobalPosition()).GetNormalized();
	dir.y = 0;
	if (KEY->Down(VK_LBUTTON))
	{
		SetState(SURVIVALMOVE);
		particle->Play(weaponFrontPos + (dir * 2));
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

void SurvivalPlayer::LimitMove()
{
	Vector3 pos = GetLocalPosition();

	if (pos.x < -25)
		pos.x = -25;
	else if (pos.x > 25)
		pos.x = 25;

	if (pos.z > 25)
		pos.z = 25;
	else if (pos.z < -25)
		pos.z = -25;

	SetLocalPosition(pos);
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
	//playerModel->GetClip(SURVIVALMOVE)->SetEvent(bind(&SurvivalPlayer::ReturnToIdle, this), 0.3f);
}

void SurvivalPlayer::SetAction()
{
	//if (curState == SURVIVALMOVE) return;

	if (velocity.x != 0 || velocity.z != 0)
		SetState(SURVIVALMOVE);

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

