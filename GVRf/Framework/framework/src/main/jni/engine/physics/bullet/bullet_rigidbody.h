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
	BulletRigidBody(SceneObject* sceneObject);
	virtual ~BulletRigidBody();

	btRigidBody* getRigidBody () const {
		return mRigidBody;
	}

	void setMass(float mass)
	{
	    //TODO
	}

	float getMass()
	{
	    //TODO
	}

    Transform* getTransform()
    {
        //TODO
    }

    void setCenterOfMass(const Transform* t);
	void getRotation(float &w, float &x, float &y, float &z);
	void getTranslation(float &x, float &y, float &z);
    Transform* updateTransform();

private:
	void initialize();
	void finalize();

private:
	btRigidBody *mRigidBody;
};
}

#endif /* BULLET_RIGIDBODY_H_ */
