/*
 * PhysicsRigidBoy.h
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#ifndef PHYSICS_RIGIDBODY_H_
#define PHYSICS_RIGIDBODY_H_

#include "objects/components/collider.h"
#include "objects/components/component.h"

namespace gvr {
// TODO: Make it abstract class!?
class PhysicsRigidBody : public Component {
public:
	PhysicsRigidBody(float mass, Collider *collider) :
		Component(PhysicsRigidBody::getComponentType()),
		mMass(mass), mCollider(collider) {
	}

	static long long getComponentType() {
	        return (long long) &getComponentType;
	}

	Collider *getCollider() {
			return mCollider;
	}

	float getMass() {
		return mMass;
	}

private:
	Collider *mCollider;
	float mMass;
};
}

#endif /* PHYSICS_RIGIDBODY_H_ */
