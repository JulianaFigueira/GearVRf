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
 * Represents a physics 2D or 3D world
 ***************************************************************************/

#ifndef PHYSICS_WORLD_H_
#define PHYSICS_WORLD_H_

#include "physics_rigidbody.h"

namespace gvr {
class PhysicsWorld {
public:
	virtual ~PhysicsWorld() = 0;

	virtual void addRigidBody (PhysicsRigidBody *body) = 0;

	virtual void removeRigidBody (PhysicsRigidBody *body) = 0;
};
}

#endif /* PHYSICS_WORLD_H_ */
