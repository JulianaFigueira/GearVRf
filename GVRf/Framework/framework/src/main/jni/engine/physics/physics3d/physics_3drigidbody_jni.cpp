/*
 * physics_3drigidbody.h
 *
 *  Created on: Jun 30, 2016
 *      Author: ragner
 */

#include "../bullet/bullet_rigidbody.h"

#include "glm/gtc/type_ptr.hpp"
#include "util/gvr_jni.h"

namespace gvr {
extern "C" {
	JNIEXPORT jlong JNICALL
    Java_org_gearvrf_physics_Native3DRigidBody_ctor(JNIEnv * env, jobject obj, jfloat jmass, jlong jcollider);

    JNIEXPORT jlong JNICALL
    Java_org_gearvrf_physics_Native3DRigidBody_getComponentType(JNIEnv * env, jobject obj);

    JNIEXPORT jfloat JNICALL
        Java_org_gearvrf_physics_Native3DRigidBody_getMass(JNIEnv * env, jobject obj,
        		jlong rigid_body);

    JNIEXPORT void JNICALL
        Java_org_gearvrf_physics_Native3DRigidBody_setMass(JNIEnv * env, jobject obj,
        		jlong rigid_body, jfloat mass);
}

JNIEXPORT jlong JNICALL
Java_org_gearvrf_physics_Native3DRigidBody_ctor(JNIEnv * env, jobject obj, jfloat jmass, jlong jcollider)
{
	Collider* collider = reinterpret_cast<Collider*>(jcollider);

    return reinterpret_cast<jlong>(new BulletRigidBody(jmass, collider));
}

JNIEXPORT jlong JNICALL
Java_org_gearvrf_physics_Native3DRigidBody_getComponentType(JNIEnv * env, jobject obj) {
    return BulletRigidBody::getComponentType();
}

JNIEXPORT jfloat JNICALL
    Java_org_gearvrf_physics_Native3DRigidBody_getMass(JNIEnv * env, jobject obj,
    		jlong jrigid_body)
{
	BulletRigidBody* rigid_body = reinterpret_cast<BulletRigidBody*>(jrigid_body);

	return rigid_body->getMass();
}

}
