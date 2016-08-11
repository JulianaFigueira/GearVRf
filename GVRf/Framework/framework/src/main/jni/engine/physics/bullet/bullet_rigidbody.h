/*
 * bullet_rigidbody.h
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#ifndef BULLET_RIGIDBODY_H_
#define BULLET_RIGIDBODY_H_

#include <BulletDynamics/Dynamics/btRigidBody.h>

#include "../physics3d/physics_3drigidbody.h"

namespace gvr {
class BulletRigidBody : public Physics3DRigidBody {
public:
	BulletRigidBody(float mass, Collider *collider);
	virtual ~BulletRigidBody();

	btRigidBody* getRigidBody () const {
		return mRigidBody;
	}

private:
	void initialize();
	void finalize();

private:
	btRigidBody *mRigidBody;
};
}

#endif /* BULLET_RIGIDBODY_H_ */
