#pragma once

class ParticleManager : public Singleton<ParticleManager>
{
private:
	const UINT particleSize = 50;

private:
	friend class Singleton;

	ParticleManager();
	~ParticleManager();

public:
	void Update();
	void Render();
	void PlayDieParticle(Vector3 pos, Vector3 rot = Vector3());

private:
	ParticleSystem* dieParticle;
	vector<ParticleSystem*> particles;
};