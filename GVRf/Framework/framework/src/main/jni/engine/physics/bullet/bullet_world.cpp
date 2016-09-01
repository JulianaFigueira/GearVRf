/* Copyright 2015 Samsung Electronics Co., LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "bullet_world.h"
#include "bullet_rigidbody.h"
#include "../../util/gvr_log.h"
namespace gvr {

BulletWorld::BulletWorld() {
	initialize();
}

BulletWorld::~BulletWorld() {
	finalize();
}

void BulletWorld::initialize() {
		// Default setup for memory, collision setup.
		mCollisionConfiguration = new btDefaultCollisionConfiguration();

		/// Default collision dispatcher.
		mDispatcher = new btCollisionDispatcher(mCollisionConfiguration);

		///btDbvtBroadphase is a good general purpose broadphase. You can also try out btAxis3Sweep.
		mOverlappingPairCache = new btDbvtBroadphase();

		///the default constraint solver. For parallel processing you can use a different solver (see Extras/BulletMultiThreaded)
		mSolver = new btSequentialImpulseConstraintSolver;

		mDynamicsWorld = new btDiscreteDynamicsWorld(mDispatcher, mOverlappingPairCache, mSolver, mCollisionConfiguration);

		mDynamicsWorld->setGravity(btVector3(0, -10, 0));

}

void BulletWorld::finalize() {

    //remove the rigidbodies from the dynamics world and delete them
        for (int i=mDynamicsWorld->getNumCollisionObjects()-1; i>=0 ;i--)
        {
            btCollisionObject* obj = mDynamicsWorld->getCollisionObjectArray()[i];
            if (obj)
            {
                mDynamicsWorld->removeCollisionObject( obj );
                delete obj;
            }
        }

		//delete dynamics world
		delete mDynamicsWorld;

		//delete solver
		delete mSolver;

		//delete broadphase
		delete mOverlappingPairCache;

		//delete dispatcher
		delete mDispatcher;

		delete mCollisionConfiguration;
}

BulletWorld* BulletWorld::getInstance() {
    static BulletWorld bulletWorld;
    return &bulletWorld;
}

void BulletWorld::addRigidBody (PhysicsRigidBody *body) {
	BulletWorld::getInstance()->mDynamicsWorld->addRigidBody((static_cast<BulletRigidBody*>(body))->getRigidBody());
}

void BulletWorld::removeRigidBody (PhysicsRigidBody *body) {
	BulletWorld::getInstance()->mDynamicsWorld->removeRigidBody((static_cast<BulletRigidBody*>(body))->getRigidBody());
}

void BulletWorld::step(float timeStep){
    BulletWorld::getInstance()->mDynamicsWorld->stepSimulation(timeStep);
}

}

