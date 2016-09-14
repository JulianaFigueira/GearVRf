//
// Created by juliana.f on 9/13/2016.
//

#include <BulletDynamics/Dynamics/btRigidBody.h>
#include "objects/components/sphere_collider.h"
#include <BulletCollision/CollisionShapes/btSphereShape.h>

#ifndef FRAMEWORK_BULLET_GVR_UTILS_H
#define FRAMEWORK_BULLET_GVR_UTILS_H

namespace gvr
{
    btCollisionShape *convertCollider2CollisionShape(Collider *collider);
    btTransform convertTransform2btTransform(const Transform* t);
    void convertBtTransform2Transform(btTransform &bulletTransform, Transform* transform);
}

#endif //FRAMEWORK_BULLET_GVR_UTILS_H
