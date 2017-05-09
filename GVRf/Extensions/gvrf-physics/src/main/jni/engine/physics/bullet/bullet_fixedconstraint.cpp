//
// Created by Juliana Figueira on 5/9/17.
//

#include "bullet_fixedconstraint.h"

BulletFixedConstraint:BulletFixedConstraint() {
    this->mFixedConstraint = new btFixedConstraint(this->getOrnwe);
};

virtual BulletFixedConstraint:~BulletFixedConstraint() {

};