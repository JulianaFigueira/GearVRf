/*
 * bullet_rigidbody.cpp
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#include "bullet_rigidbody.h"
#include "bullet_gvr_utils.h"
#include "objects/components/sphere_collider.h"
#include "util/gvr_log.h"
#include <BulletCollision/CollisionShapes/btSphereShape.h>
#include <LinearMath/btDefaultMotionState.h>
#include <LinearMath/btTransform.h>

namespace gvr {


BulletRigidBody::BulletRigidBody()
	: Physics3DRigidBody(), mMass(0.0f), m_centerOfMassOffset(btTransform::getIdentity()) {
}

BulletRigidBody::~BulletRigidBody() {
	finalize();
}

void BulletRigidBody::onAttach()
{
	initialize();
}

void BulletRigidBody::onDetach()
{
	finalize();
}

void BulletRigidBody::initialize() {
    btTransform startTransform = convertTransform2btTransform(getTransform());
    bool isDynamic = (getMass() != 0.f);
	btVector3 localInertia(0,0,0);
	btCollisionShape *collisionShape = convertCollider2CollisionShape(owner_object()->collider());
	btDefaultMotionState* myMotionState = new btDefaultMotionState(startTransform);

	if (isDynamic)
		collisionShape->calculateLocalInertia(getMass(),localInertia);


	mRigidBody = new btRigidBody(btScalar(getMass()), myMotionState, collisionShape, localInertia);

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
     //LOGD("GET POS x: %f y: %f z: %f mass: %f", getTransform()->position_x(), getTransform()->position_y(), getTransform()->position_z(), getMass());
 }

void BulletRigidBody::setCenterOfMass(const Transform* t){
    mRigidBody->setCenterOfMassTransform(convertTransform2btTransform(t));
}

Transform* BulletRigidBody::updateTransform(){
     btTransform trans;
     if (mRigidBody && mRigidBody->getMotionState())
     {
         mRigidBody->getMotionState()->getWorldTransform(trans);
     } else
     {
         trans = mRigidBody->getCenterOfMassTransform();
     }
     convertBtTransform2Transform(trans, getTransform());
     return getTransform();
 }

void BulletRigidBody::getWorldTransform(btTransform &centerOfMassWorldTrans) const {
    centerOfMassWorldTrans = m_centerOfMassOffset.inverse()
            * convertTransform2btTransform(owner_object()->transform());
}

void BulletRigidBody::setWorldTransform(const btTransform& centerOfMassWorldTrans) {
    btTransform m_graphicsWorldTrans = centerOfMassWorldTrans * m_centerOfMassOffset;
    convertBtTransform2Transform(m_graphicsWorldTrans, owner_object()->transform());
}

}
