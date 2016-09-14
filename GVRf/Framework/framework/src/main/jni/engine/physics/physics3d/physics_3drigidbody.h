/*
 * physics_3drigidbody.h
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#ifndef PHYSICS_3DRIGIDBODY_H_
#define PHYSICS_3DRIGIDBODY_H_

#include "../physics_rigidbody.h"

namespace gvr {
class Physics3DRigidBody : public PhysicsRigidBody {
public:
    Physics3DRigidBody() : PhysicsRigidBody() {}
    ~Physics3DRigidBody(){}
};
}

#endif /* PHYSICS_3DRIGIDBODY_H_ */
