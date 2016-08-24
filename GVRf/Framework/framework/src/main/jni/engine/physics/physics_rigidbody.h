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
#include "objects/components/transform.h"

namespace gvr {
// TODO: Make it abstract class!?
class PhysicsRigidBody : public Component {
public:
	PhysicsRigidBody(float mass, Collider *collider, Transform* startTransform) :
		Component(PhysicsRigidBody::getComponentType()),
		mMass(mass), mCollider(collider), mStartTransform(startTransform)  {
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

    Transform * getTransform() {
        return mStartTransform;
    }

	void setMass(float mass) {
    	mMass = mass;
    }

    virtual void setCenterOfMass(const Transform* t) = 0;
	virtual void getRotation(float &w, float &x, float &y, float &z) = 0;
    virtual void getTranslation(float &x, float &y, float &z) = 0;

private:
	Collider *mCollider;
	float mMass;
	Transform *mStartTransform;
};
}

#endif /* PHYSICS_RIGIDBODY_H_ */
