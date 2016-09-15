#include "bullet_gvr_utils.h"

namespace gvr{
btCollisionShape *convertCollider2CollisionShape(Collider *collider) {
    btCollisionShape *shape = NULL;

    shape = convertSphereCollider2CollisionShape(static_cast<SphereCollider *>(collider));
    if (shape != NULL) {
       return shape;
    }

    shape = convertBoxCollider2CollisionShape(static_cast<BoxCollider *>(collider));
    if (shape != NULL) {
       return shape;
    }

    return NULL;
}

btCollisionShape *convertSphereCollider2CollisionShape(SphereCollider *collider) {
    btCollisionShape *shape = NULL;

    if (collider != NULL) {
        shape = new btSphereShape(btScalar(collider->get_radius()));
    }

    return shape;
}

btCollisionShape *convertBoxCollider2CollisionShape(BoxCollider *collider) {
    btCollisionShape *shape = NULL;

    if (collider != NULL) {
        shape = new btBoxShape(btVector3(collider->get_half_extents().x,
                                         collider->get_half_extents().y,
                                         collider->get_half_extents().z));
    }

    return shape;
}

btTransform convertTransform2btTransform(const Transform* t){
    btQuaternion rotation(t->rotation_x(),t->rotation_y(),t->rotation_z(), t->rotation_w());

    btVector3 position(t->position_x(), t->position_y(), t->position_z());

    btTransform transform(rotation, position);

    return transform;
}

void convertBtTransform2Transform(btTransform &bulletTransform, Transform* transform){
    btVector3 pos = bulletTransform.getOrigin();
    btQuaternion rot = bulletTransform.getRotation();

    transform->set_position(pos.getX(),pos.getY(), pos.getZ());
    transform->set_rotation(rot.getW(),rot.getX(), rot.getY(), rot.getZ());
}

}
