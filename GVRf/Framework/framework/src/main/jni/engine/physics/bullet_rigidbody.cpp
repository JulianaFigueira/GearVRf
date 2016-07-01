/*
 * bullet_rigidbody.cpp
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#include "bullet_rigidbody.h"

BulletRigidBody::BulletRigidBody(const BulletRigidBodyDef &bodyDef)
	: mBodyDef(bodyDef) {

	initialize();
}

BulletRigidBody::~BulletRigidBody() {
	finalize();
}

void BulletRigidBody::initialize() {
	mRigidBody =  new btRigidBody(mBodyDef.getBodyDef());
}

void BulletRigidBody::finalize() {
	if (mRigidBody->getMotionState()) {
		delete mRigidBody->getMotionState();
	}

	delete mRigidBody;
}
