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
    Java_org_gearvrf_physics_Native3DRigidBody_ctor(JNIEnv * env, jobject obj);

    JNIEXPORT jlong JNICALL
    Java_org_gearvrf_physics_Native3DRigidBody_getComponentType(JNIEnv * env, jobject obj);

    JNIEXPORT jfloat JNICALL
    Java_org_gearvrf_physics_Native3DRigidBody_getMass(JNIEnv * env, jobject obj,
        		jlong jrigid_body);

    JNIEXPORT void JNICALL
    Java_org_gearvrf_physics_Native3DRigidBody_setMass(JNIEnv * env, jobject obj,
        		jlong jrigid_body, jfloat mass);

    JNIEXPORT void JNICALL
    Java_org_gearvrf_physics_Native3DRigidBody_updateTransform(JNIEnv * env, jobject obj,
        		jlong jrigid_body, jlong jtransform);
}

JNIEXPORT jlong JNICALL
Java_org_gearvrf_physics_Native3DRigidBody_ctor(JNIEnv * env, jobject obj)
{
    return reinterpret_cast<jlong>(new BulletRigidBody());
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

JNIEXPORT void JNICALL
        Java_org_gearvrf_physics_Native3DRigidBody_setMass(JNIEnv * env, jobject obj,
        		jlong jrigid_body, jfloat mass)
{
	BulletRigidBody* rigid_body = reinterpret_cast<BulletRigidBody*>(jrigid_body);

	rigid_body->setMass(mass);
}

JNIEXPORT void JNICALL
        Java_org_gearvrf_physics_Native3DRigidBody_updateTransform(JNIEnv * env, jobject obj,
        		jlong jrigid_body, jlong jtransform){

    BulletRigidBody* rigid_body = reinterpret_cast<BulletRigidBody*>(jrigid_body);
    Transform* outTransform = reinterpret_cast<Transform*>(jtransform);

    Transform* transform = rigid_body->updateTransform();

    outTransform->set_position(transform->position_x(), transform->position_y(), transform->position_z());
    outTransform->set_rotation(transform->rotation_w(), transform->rotation_x(), transform->rotation_y(),
                                                                             transform->rotation_z());
}
}
