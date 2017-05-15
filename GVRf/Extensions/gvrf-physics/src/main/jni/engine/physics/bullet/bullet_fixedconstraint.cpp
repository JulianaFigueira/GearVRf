//
// Created by Juliana Figueira on 5/9/17.
//

#include "bullet_fixedconstraint.h"
namespace gvr {

    BulletFixedConstraint::BulletFixedConstraint(BulletRigidBody* rigidBodyB) {
        this->mFixedConstraint = 0;
        this->mRigidBodyB = rigidBodyB;
    };

    BulletFixedConstraint::~BulletFixedConstraint() {
        delete mFixedConstraint;
    };

    void BulletFixedConstraint::set_owner_object(SceneObject* obj) {
        if (obj == owner_object())
        {
            return;
        }
        Component::set_owner_object(obj);
        if (obj)
        {
            onAttach(obj);
        }
    }

    void BulletFixedConstraint::onAttach(SceneObject* owner) {
        btRigidBody* rbA = ((BulletRigidBody*)this->owner_object()->getComponent(COMPONENT_TYPE_PHYSICS_RIGID_BODY))->getRigidBody();

        this->mFixedConstraint = new btFixedConstraint(*rbA, *mRigidBodyB->getRigidBody(), mRigidBodyB->getRigidBody()->getWorldTransform(), rbA->getWorldTransform());
    }

}