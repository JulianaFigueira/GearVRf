/*
 * PhysicsRigidBoy.h
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#ifndef PHYSICS_RIGIDBODY_H_
#define PHYSICS_RIGIDBODY_H_

#include "objects/scene_object.h"
#include "objects/components/component.h"
#include "objects/components/transform.h"

namespace gvr {
// TODO: Make it abstract class!?
class PhysicsRigidBody : public Component {
public:
    PhysicsRigidBody() : Component(PhysicsRigidBody::getComponentType()) {}

	static long long getComponentType() {
	        return COMPONENT_TYPE_PHYSICS_RIGID_BODY;
	}

	virtual Transform* getTransform() = 0;
	virtual float getMass() = 0;
	virtual void setMass(float mass) = 0;
    virtual void setCenterOfMass(const Transform* t) = 0;
	virtual void getRotation(float &w, float &x, float &y, float &z) = 0;
    virtual void getTranslation(float &x, float &y, float &z) = 0;
    virtual void onAttach() = 0;
    virtual void onDetach() = 0;
};
}

#endif /* PHYSICS_RIGIDBODY_H_ */
