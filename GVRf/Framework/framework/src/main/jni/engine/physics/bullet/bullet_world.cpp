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
#include <BulletCollision/CollisionDispatch/btDefaultCollisionConfiguration.h>
#include <BulletCollision/BroadphaseCollision/btDbvtBroadphase.h>
#include <BulletDynamics/Dynamics/btDiscreteDynamicsWorld.h>

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

		mPhysicsWorld = new btDiscreteDynamicsWorld(mDispatcher, mOverlappingPairCache, mSolver, mCollisionConfiguration);

		mPhysicsWorld->setGravity(btVector3(0, -10, 0));
}

void BulletWorld::finalize() {

    //remove the rigidbodies from the dynamics world and delete them
        for (int i=mPhysicsWorld->getNumCollisionObjects()-1; i>=0 ;i--)
        {
            btCollisionObject* obj = mPhysicsWorld->getCollisionObjectArray()[i];
            if (obj)
            {
                mPhysicsWorld->removeCollisionObject( obj );
                delete obj;
            }
        }

		//delete dynamics world
		delete mPhysicsWorld;

		//delete solver
		delete mSolver;

		//delete broadphase
		delete mOverlappingPairCache;

		//delete dispatcher
		delete mDispatcher;

		delete mCollisionConfiguration;

}

void BulletWorld::addRigidBody (PhysicsRigidBody *body) {
	getInstance()->mPhysicsWorld->addRigidBody((static_cast<BulletRigidBody*>(body))->getRigidBody());
}

void BulletWorld::removeRigidBody (PhysicsRigidBody *body) {
	getInstance()->mPhysicsWorld->removeRigidBody((static_cast<BulletRigidBody*>(body))->getRigidBody());
}

void BulletWorld::step(float timeStep){
    getInstance()->mPhysicsWorld->stepSimulation(timeStep);
}

BulletWorld* BulletWorld::getInstance()
{
    static BulletWorld instance;
    return &instance;
}
 /*
//FROM BULLET
void Bullet2NearCallback(btBroadphasePair& collisionPair, btCollisionDispatcher& dispatcher,
                                                               const btDispatcherInfo& dispatchInfo)
{
    btCollisionObject* colObj0 = (btCollisionObject*)collisionPair.m_pProxy0->m_clientObject;
    btCollisionObject* colObj1 = (btCollisionObject*)collisionPair.m_pProxy1->m_clientObject;
    if(gTmpFilter)
    {
        gTmpFilter(BulletWorld::getInstance()->mPhysicsWorld, gUserData,colObj0,colObj1);
        gNearCallbackCount++;
    }
}

void BulletWorld::collideWorld(void* filter, void* userData)
//void BulletWorld::collideWorld(PhysicsNearCallback* filter, void* userData)
{
    gTmpFilter = filter;
    gNearCallbackCount = 0;
    gUserData = userData;
    getInstance()->mDispatcher->setNearCallback(Bullet2NearCallback);
    getInstance()->mPhysicsWorld->performDiscreteCollisionDetection();
    gTmpFilter = 0;
}

struct   Bullet2ContactResultCallback : public btWorld::ContactResultCallback
{
    int m_numContacts;
    lwContactPoint* m_pointsOut;
    int m_pointCapacity;

    Bullet2ContactResultCallback(lwContactPoint* pointsOut, int pointCapacity) :
	m_numContacts(0),
		m_pointsOut(pointsOut),
		m_pointCapacity(pointCapacity)
    {
    }
    virtual   btScalar   addSingleResult(btManifoldPoint& cp,   const btCollisionObjectWrapper* colObj0Wrap,int partId0,int index0,const btCollisionObjectWrapper* colObj1Wrap,int partId1,int index1)
    {
        if (m_numContacts<m_pointCapacity)
        {
            lwContactPoint& ptOut = m_pointsOut[m_numContacts];
            ptOut.m_distance = cp.m_distance1;
            ptOut.m_normalOnB[0] = cp.m_normalWorldOnB.getX();
            ptOut.m_normalOnB[1] = cp.m_normalWorldOnB.getY();
            ptOut.m_normalOnB[2] = cp.m_normalWorldOnB.getZ();
            ptOut.m_ptOnAWorld[0] = cp.m_positionWorldOnA[0];
            ptOut.m_ptOnAWorld[1] = cp.m_positionWorldOnA[1];
            ptOut.m_ptOnAWorld[2] = cp.m_positionWorldOnA[2];
            ptOut.m_ptOnBWorld[0] = cp.m_positionWorldOnB[0];
            ptOut.m_ptOnBWorld[1] = cp.m_positionWorldOnB[1];
            ptOut.m_ptOnBWorld[2] = cp.m_positionWorldOnB[2];
            m_numContacts++;
        }

        return 1.f;
    }
};

int BulletWorld::collide(PhysicsRigidBody* colObjA, PhysicsRigidBody* colObjB,
                                                  lwContactPoint* pointsOut, int pointCapacity
{
    btWorld* World = BulletWorld::getInstance()->mPhysicsWorld;
    if (World && colObjA && colObjB)
    {
        Bullet2ContactResultCallback cb(pointsOut,pointCapacity);
        getInstance()->mPhysicsWorld->contactPairTest((btCollisionObject*)colObjA->getRigidBody(),
                                                      (btCollisionObject*)colObjB->getRigidBody(),cb);
        return cb.m_numContacts;
    }
    return 0;
}
*/
}

