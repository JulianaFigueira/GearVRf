/*
 * bullet_rigidbody.cpp
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#include "bullet_rigidbody.h"
#include "objects/components/sphere_collider.h"
#include "util/gvr_log.h"
#include <BulletCollision/CollisionShapes/btSphereShape.h>
#include <LinearMath/btDefaultMotionState.h>
#include <LinearMath/btTransform.h>

namespace gvr {

btCollisionShape *convertCollider2CollisionShape(Collider *collider) {
	SphereCollider *sphereCollider = static_cast<SphereCollider*>(collider);

	btCollisionShape *collisionShape = new btSphereShape(btScalar(sphereCollider->get_radius()));

	return collisionShape;
}

btTransform convertTransform2btTransform(const Transform* t){
    btQuaternion rotation(t->rotation_x(),t->rotation_y(),t->rotation_z(), t->rotation_w());

    btVector3 position(t->position_x(), t->position_y(), t->position_z());

    btTransform transform(rotation, position);

    return transform;
}

BulletRigidBody::BulletRigidBody(float mass, Collider *collider, Transform* startTransform)
	: Physics3DRigidBody(mass, collider, startTransform) {

	initialize();
}

BulletRigidBody::~BulletRigidBody() {
	finalize();
}

void BulletRigidBody::initialize() {

    btTransform startTransform = convertTransform2btTransform(getTransform());
    bool isDynamic = (getMass() != 0.f);
	btVector3 localInertia(0,0,0);
	btCollisionShape *collisionShape = convertCollider2CollisionShape(getCollider());
	btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);

	if (isDynamic)
		collisionShape->calculateLocalInertia(getMass(),localInertia);


	mRigidBody = new btRigidBody(btScalar(getMass()), myMotionState, collisionShape, localInertia);

	LOGD("INITIALIZE x: %f y: %f z: %f mass: %f", getTransform()->position_x(), getTransform()->position_y(), getTransform()->position_z(), getMass());
}

void BulletRigidBody::finalize() {
	if (mRigidBody->getMotionState()) {
		delete mRigidBody->getMotionState();
	}

	if (mRigidBody->getCollisionShape()){
	    delete mRigidBody->getCollisionShape();
	}
}

void BulletRigidBody::getRotation(float &w, float &x, float &y, float &z){
    btTransform trans;
    if (mRigidBody && mRigidBody->getMotionState())
    {
        mRigidBody->getMotionState()->getWorldTransform(trans);
    } else
    {
        trans = mRigidBody->getCenterOfMassTransform();
    }

    btQuaternion rotation = trans.getRotation();

    w = rotation.getW();
    z = rotation.getZ();
    y = rotation.getY();
    x = rotation.getX();


}

void BulletRigidBody::getTranslation(float &x, float &y, float &z){
      btTransform trans;
     if (mRigidBody && mRigidBody->getMotionState())
     {
         mRigidBody->getMotionState()->getWorldTransform(trans);
     } else
     {
         trans = mRigidBody->getCenterOfMassTransform();
     }

     btVector3 pos = trans.getOrigin();

     z = pos.getZ();
     y = pos.getY();
     x = pos.getX();
     LOGD("GET POS x: %f y: %f z: %f mass: %f", getTransform()->position_x(), getTransform()->position_y(), getTransform()->position_z(), getMass());
 }

void BulletRigidBody::setCenterOfMass(const Transform* t){
    mRigidBody->setCenterOfMassTransform(convertTransform2btTransform(t));
}
}
