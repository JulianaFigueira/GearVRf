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


#ifndef BULLET_FIXEDCONSTRAINT_H
#define BULLET_FIXEDCONSTRAINT_H

#include "../physics3d/constraints/physics_3dfixedconstraint.h"
#include <BulletDynamics/ConstraintSolver/btFixedConstraint.h>
#include "bullet_rigidbody.h"
#include "bullet_world.h"

namespace gvr {


    class BulletFixedConstraint : public Physics3DFixedConstraint {
    public:
        BulletFixedConstraint(BulletRigidBody* rigidBodyB);

        ~BulletFixedConstraint();

        virtual void set_owner_object(SceneObject* obj);

        virtual void* getConstraint() {
            return this->mFixedConstraint;
        }

    private:
        void onAttach(SceneObject* owner);

    private:
        btFixedConstraint *mFixedConstraint;
        BulletRigidBody *mRigidBodyB; //this is A
    };

}
#endif //BULLET_FIXEDCONSTRAINT_H
