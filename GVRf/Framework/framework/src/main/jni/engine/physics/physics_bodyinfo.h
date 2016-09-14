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

#ifndef PHYSICS_BODYINFO_H_
#define PHYSICS_BODYINFO_H_

#include "objects/scene_object.h"

namespace gvr {

class PhysicsBodyInfo : public Component{
public:

    PhysicsBodyInfo() : Component(PhysicsBodyInfo::getComponentType())
    {
    }

    static long long getComponentType()
    {
	    return COMPONENT_TYPE_PHYSICS_RIGID_BODY;
	}

    virtual float getMass() = 0;
    virtual void setMass(float mass) = 0;
};
}

#endif /* PHYSICS_BODYINFO_H_ */
