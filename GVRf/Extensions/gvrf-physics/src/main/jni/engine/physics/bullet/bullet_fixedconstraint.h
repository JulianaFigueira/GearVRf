//
// Created by Juliana Figueira on 5/9/17.
//

#ifndef EXTENSIONS_BULLET_FIXEDCONSTRAINT_H
#define EXTENSIONS_BULLET_FIXEDCONSTRAINT_H

#include "../physics3d/constraints/physics_3dfixedconstraint.h"
#include <BulletDynamics/ConstraintSolver/btFixedConstraint.h">


class BulletFixedConstraint : Physics3DFixedConstraint {

    BulletFixedConstraint();

    virtual ~BulletFixedConstraint();

    btFixedConstraint *getFixedConstraint() const {
        return mFixedConstraint;
    }

private:
    btFixedConstraint mFixedConstraint;
};


#endif //EXTENSIONS_BULLET_FIXEDCONSTRAINT_H
