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
	BulletRigidBody(float mass, Collider *collider, Transform* startTransform);
	virtual ~BulletRigidBody();

	btRigidBody* getRigidBody () const {
		return mRigidBody;
	}

    void setCenterOfMass(const Transform* t);
	void getRotation(float &w, float &x, float &y, float &z);
	void getTranslation(float &x, float &y, float &z);

private:
	void initialize();
	void finalize();

private:
	btRigidBody *mRigidBody;
};
}

#endif /* BULLET_RIGIDBODY_H_ */
