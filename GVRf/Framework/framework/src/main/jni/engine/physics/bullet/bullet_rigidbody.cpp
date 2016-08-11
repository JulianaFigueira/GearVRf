/*
 * bullet_rigidbody.cpp
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#include "bullet_rigidbody.h"
#include "objects/components/sphere_collider.h"

#include <BulletCollision/CollisionShapes/btSphereShape.h>
#include <LinearMath/btDefaultMotionState.h>

namespace gvr {

btCollisionShape *convertCollider2CollisionShape(Collider *collider) {
	SphereCollider *sphereCollider = static_cast<SphereCollider*>(collider);

	btCollisionShape *collisionShape = new btSphereShape(btScalar(sphereCollider->get_radius()));

	return collisionShape;
}

BulletRigidBody::BulletRigidBody(float mass, Collider *collider)
	: Physics3DRigidBody(mass, collider) {

	initialize();
}

BulletRigidBody::~BulletRigidBody() {
	finalize();
}

void BulletRigidBody::initialize() {

	btDefaultMotionState* myMotionState = new btDefaultMotionState();
	btCollisionShape *collisionShape = convertCollider2CollisionShape(getCollider());

	mRigidBody = new btRigidBody(btScalar(getMass()), myMotionState, collisionShape);
}

void BulletRigidBody::finalize() {
	if (mRigidBody->getMotionState()) {
		delete mRigidBody->getMotionState();
	}

	delete mRigidBody;
}
}
