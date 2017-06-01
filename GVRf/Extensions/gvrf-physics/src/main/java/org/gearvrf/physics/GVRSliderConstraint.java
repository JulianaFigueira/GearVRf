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

package org.gearvrf.physics;

import org.gearvrf.GVRContext;

/**
 * Created by c.bozzetto on 31/05/2017.
 */

public class GVRSliderConstraint extends GVRConstraint {
    public GVRSliderConstraint(GVRContext gvrContext, GVRRigidBody rigidBody) {
        super(gvrContext, Native3DSliderConstraint.ctor(rigidBody.getNative()));
    }

    public void setAngularLowerLimit(float limit) {
        Native3DSliderConstraint.setAngularLowerLimit(getNative(), limit);
    }

    public float getAngularLowerLimit() {
        return Native3DSliderConstraint.getAngularLowerLimit(getNative());
    }

    public void setAngularUpperLimit(float limit) {
        Native3DSliderConstraint.setAngularUpperLimit(getNative(), limit);
    }

    public float getAngularUpperLimit() {
        return Native3DSliderConstraint.getAngularUpperLimit(getNative());
    }

    public void setLinearLowerLimit(float limit) {
        Native3DSliderConstraint.setLinearLowerLimit(getNative(), limit);
    }

    public float getLinearLowerLimit() {
        return Native3DSliderConstraint.getLinearLowerLimit(getNative());
    }

    public void setLinearUpperLimit(float limit) {
        Native3DSliderConstraint.setLinearUpperLimit(getNative(), limit);
    }

    public float getLinearUpperLimit() {
        return Native3DSliderConstraint.getLinearUpperLimit(getNative());
    }
}


class Native3DSliderConstraint {
    static native long ctor(long rbB);

    static native long getComponentType();

    static native void setAngularLowerLimit(long nativeConstraint, float limit);

    static native float getAngularLowerLimit(long nativeConstraint);

    static native void setAngularUpperLimit(long nativeConstraint, float limit);

    static native float getAngularUpperLimit(long nativeConstraint);

    static native void setLinearLowerLimit(long nativeConstraint, float limit);

    static native float getLinearLowerLimit(long nativeConstraint);

    static native void setLinearUpperLimit(long nativeConstraint, float limit);

    static native float getLinearUpperLimit(long nativeConstraint);
}
