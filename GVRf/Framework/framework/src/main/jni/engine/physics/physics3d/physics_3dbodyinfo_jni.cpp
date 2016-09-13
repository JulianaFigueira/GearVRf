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

/***************************************************************************
 * Keep the info about a physics body
 ***************************************************************************/

#include "../bullet/bullet_bodyinfo.h"

namespace gvr {
extern "C" {

    JNIEXPORT jlong JNICALL
        Java_org_gearvrf_physics_NativePhysics3DBodyInfo_ctor(JNIEnv * env, jobject obj, jfloat jmass);

    JNIEXPORT jfloat JNICALL
        Java_org_gearvrf_physics_NativePhysics3DBodyInfo_getMass(JNIEnv * env, jobject obj, jlong jbody_info);

    JNIEXPORT void JNICALL
        Java_org_gearvrf_physics_NativePhysics3DBodyInfo_setMass(JNIEnv * env, jobject obj, jlong jbody_info,
            jfloat jmass);
}

JNIEXPORT jlong JNICALL
        Java_org_gearvrf_physics_NativePhysics3DBodyInfo_ctor(JNIEnv * env, jobject obj, jfloat jmass){
    return reinterpret_cast<jlong>(new BulletBodyInfo((float)jmass));
}

JNIEXPORT void JNICALL
        Java_org_gearvrf_physics_NativePhysics3DBodyInfo_setMass(JNIEnv * env, jobject obj, jlong jbody_info,
        		jlong jmass) {
	BulletBodyInfo* body_info = reinterpret_cast<BulletBodyInfo*>(jbody_info);
	body_info->setMass((float)jmass);
}

JNIEXPORT jfloat JNICALL
        Java_org_gearvrf_physics_NativePhysics3DBodyInfo_getMass(JNIEnv * env, jobject obj,
        		jlong jbody_info) {
	BulletBodyInfo* body_info = reinterpret_cast<BulletBodyInfo*>(jbody_info);
    return body_info->getMass();
}

}
