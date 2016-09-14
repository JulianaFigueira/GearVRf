/*
 * bullet_rigidbody.h
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#ifndef BULLET_RIGIDBODY_H_
#define BULLET_RIGIDBODY_H_

#include <BulletDynamics/Dynamics/btRigidBody.h>
#include <LinearMath/btMotionState.h>
#include "../physics3d/physics_3drigidbody.h"

namespace gvr {
class BulletRigidBody : public Physics3DRigidBody, btMotionState {
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

    void getWorldTransform(btTransform& worldTrans) const;
    void setWorldTransform(const btTransform& worldTrans);

private:
	void initialize();
	void finalize();

private:
	btRigidBody *mRigidBody;
	btTransform m_centerOfMassOffset;
};
}

#endif /* BULLET_RIGIDBODY_H_ */
