#include "Framework.h"

ParticleManager::ParticleManager()
{
	particles.reserve(particleSize);

	FOR(particleSize)
	{
		dieParticle = new ParticleSystem("Resources/Textures/UI/FX/zombiedie.fx");
		dieParticle->SetActive(false);

		particles.push_back(dieParticle);
	}
}

ParticleManager::~ParticleManager()
{
}

void ParticleManager::Update()
{
	for (ParticleSystem* particle : particles)
		particle->Update();
}

void ParticleManager::Render()
{
	for (ParticleSystem* particle : particles)
		particle->Render();
}

void ParticleManager::PlayDieParticle(Vector3 pos, Vector3 rot)
{
	dieParticle->SetActive(true);
	dieParticle->Play(pos,rot);
}


