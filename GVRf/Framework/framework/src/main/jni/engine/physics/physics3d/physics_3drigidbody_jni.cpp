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
    Java_org_gearvrf_physics_Native3DRigidBody_ctor(JNIEnv * env, jobject obj, jfloat jmass, jlong jcollider, jlong jtransform);

    JNIEXPORT jlong JNICALL
    Java_org_gearvrf_physics_Native3DRigidBody_getComponentType(JNIEnv * env, jobject obj);

    JNIEXPORT jfloat JNICALL
        Java_org_gearvrf_physics_Native3DRigidBody_getMass(JNIEnv * env, jobject obj,
        		jlong jrigid_body);

    JNIEXPORT void JNICALL
        Java_org_gearvrf_physics_Native3DRigidBody_setMass(JNIEnv * env, jobject obj,
        		jlong jrigid_body, jfloat mass);

    JNIEXPORT jfloatArray JNICALL
        Java_org_gearvrf_physics_Native3DRigidBody_getCollisionTransform(JNIEnv * env, jobject obj,
        		jlong jrigid_body);
}

JNIEXPORT jlong JNICALL
Java_org_gearvrf_physics_Native3DRigidBody_ctor(JNIEnv * env, jobject obj, jfloat jmass, jlong jcollider
                                                , jlong jtransform)
{
	Collider* collider = reinterpret_cast<Collider*>(jcollider);
    Transform* transform = reinterpret_cast<Transform*>(jtransform);
    return reinterpret_cast<jlong>(new BulletRigidBody(jmass, collider, transform));
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

JNIEXPORT jfloatArray JNICALL
        Java_org_gearvrf_physics_Native3DRigidBody_getCollisionTransform(JNIEnv * env, jobject obj,
        		jlong jrigid_body){

    BulletRigidBody* rigid_body = reinterpret_cast<BulletRigidBody*>(jrigid_body);

    jfloatArray result;
     result = env->NewFloatArray(7);
     if (result == NULL) {
         return NULL; /* out of memory error thrown */
     }

    jfloat t[7];
    rigid_body->getRotation(t[0], t[1], t[2], t[3]);
    rigid_body->getTranslation(t[4], t[5], t[6]);

    env->SetFloatArrayRegion(result, 0, 7, t);
    return result;
}


}
