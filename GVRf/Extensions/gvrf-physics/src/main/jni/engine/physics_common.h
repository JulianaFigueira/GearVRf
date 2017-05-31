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

#ifndef PHYSICS_COMMON_H_
#define PHYSICS_COMMON_H_

namespace gvr {

    union PhysicsVec3 {
        float vec[3];
        struct {
            float x, y, z;
        };

        void set(float const v[]) {
            x = v[0];
            y = v[1];
            z = v[2];
        }

        void set(float x, float y, float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        PhysicsVec3() : x(0), y(0), z(0) {}
        PhysicsVec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    };

}

#endif /* PHYSICS_COMMON_H_ */
