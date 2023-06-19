#ifndef __PHYSENTITY_H
#define __PHYSENTITY_H
#include <vector>
#include <string>
#include "Collider.h"

class PhysEntity : public GameEntity {
protected:
	unsigned long mId;

	std::vector<Collider *> mColliders;

	Collider * mBroadPhaseCollider;

	void AddCollider(Collider * collider, Vector2 localPos = Vec2_Zero);

	virtual bool IgnoreCollisions();

	std::string mTag;

public:
	PhysEntity();
	virtual ~PhysEntity();

	unsigned long GetId();
	std::string GetTag();
	void SetTag(std::string tag);

	bool CheckCollision(PhysEntity * other);
	void ChangeCollider(Collider* collider, Vector2 localPos = Vec2_Zero);

	virtual void Hit(PhysEntity * other) { }

	virtual void Render() override;
};
#endif