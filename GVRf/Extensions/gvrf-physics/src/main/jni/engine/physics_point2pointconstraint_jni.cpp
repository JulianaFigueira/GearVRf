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

#include "physics_point2pointconstraint.h"
#include "bullet/bullet_point2pointconstraint.h"

namespace gvr {
    extern "C" {
    JNIEXPORT jlong JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_ctor(JNIEnv * env, jobject obj,
        jlong rigidBodyB, jfloatArray pivotInA, jfloatArray pivotInB);

    JNIEXPORT jlong JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_getComponentType(JNIEnv * env, jobject obj);

    JNIEXPORT void JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_setPivotInA(JNIEnv * env, jobject obj,
        jfloat x, jfloat y, jfloat z);

    JNIEXPORT void JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_getPivotInA(JNIEnv * env, jobject obj,
        jfloatArray pivot);

    JNIEXPORT void JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_setPivotInB(JNIEnv * env, jobject obj,
        jfloat x, jfloat y, jfloat z);

    JNIEXPORT void JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_getPivotInB(JNIEnv * env, jobject obj,
        jfloatArray pivot);

    }

    JNIEXPORT jlong JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_ctor(JNIEnv * env, jobject obj, 
        jlong rigidBodyB, jfloatArray pivotInA, jfloatArray pivotInB) {
        jfloat *pA = env->GetFloatArrayElements(pivotInA, 0);
        jfloat *pB = env->GetFloatArrayElements(pivotInB, 0);
        return reinterpret_cast<jlong>(new BulletPoint2PointConstraint(
                    reinterpret_cast<BulletRigidBody*>(rigidBodyB), pA, pB));
    }

    JNIEXPORT jlong JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_getComponentType(JNIEnv * env,
        jobject obj) {
        return PhysicsConstraint::getComponentType();
    }

    JNIEXPORT void JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_setPivotInA(JNIEnv * env, jobject obj,
        jfloat x, jfloat y, jfloat z) {
    }

    JNIEXPORT void JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_getPivotInA(JNIEnv * env, jobject obj,
        jfloatArray pivot) {
    }

    JNIEXPORT void JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_setPivotInB(JNIEnv * env, jobject obj,
        jfloat x, jfloat y, jfloat z) {
    }

    JNIEXPORT void JNICALL
    Java_org_gearvrf_physics_Native3DPoint2PointConstraint_getPivotInB(JNIEnv * env, jobject obj,
        jfloatArray pivot) {
    }
}
