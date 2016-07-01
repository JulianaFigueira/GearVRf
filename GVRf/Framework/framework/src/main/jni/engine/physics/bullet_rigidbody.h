/*
 * bullet_rigidbody.h
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#ifndef BULLET_RIGIDBODY_H_
#define BULLET_RIGIDBODY_H_

#include <BulletDynamics/Dynamics/btRigidBody.h>

#include "physics_3drigidbody.h"

class BulletRigidBody : public Physics3DRigidBody {
public:
	class BulletRigidBodyDef : public Physics3DRigidBody::Physics3DRigidBodyDef {
	public:
		const btRigidBody::btRigidBodyConstructionInfo &getBodyDef() {
			return mBodyDef;
		}

	private:
		btRigidBody::btRigidBodyConstructionInfo mBodyDef;
/*
	private:
		btCollisionShape *mCollisionShape;
		btMotionState *mMotionState;
		btScalar mMass;
		btVector3 mLocalInertia;*/
	};

public:
	BulletRigidBody(const BulletRigidBodyDef &bodyDef);
	virtual ~BulletRigidBody();

	btRigidBody* getRigidBody () const {
		return mRigidBody;
	}

private:
	void initialize();
	void finalize();

private:
	btRigidBody *mRigidBody;

private:
	BulletRigidBodyDef mBodyDef;
};

#endif /* BULLET_RIGIDBODY_H_ */
