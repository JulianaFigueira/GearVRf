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

package org.gearvrf;

public class GVRBoxCollider extends GVRCollider {

    public GVRBoxCollider(GVRContext context)
    {
        super(context, NativeBoxCollider.ctor());
    }

    public void setHalfExtents(float x, float y, float z)
    {
        NativeBoxCollider.setHalfExtents(getNative(), x, y, z);
    }

//    public float getHalfExtents()
//    {
//        return NativeBoxCollider.getHalfExtents(getNative());
//    }
}

class NativeBoxCollider
{
    static native long ctor();

    static native void setHalfExtents(long collider, float x, float y, float z);

//    static native float getHalfExtents(long jcollider);
}
