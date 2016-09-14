#include "bullet_gvr_utils.h"

namespace gvr{
btCollisionShape *convertCollider2CollisionShape(Collider *collider) {
	SphereCollider *sphereCollider = static_cast<SphereCollider*>(collider);

	btCollisionShape *collisionShape = new btSphereShape(btScalar(sphereCollider->get_radius()));

	return collisionShape;
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

