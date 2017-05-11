package org.gearvrf.physics;

import org.gearvrf.GVRContext;

public class GVRFixedConstraint extends GVRConstraint {

    public GVRFixedConstraint(GVRContext gvrContext, GVRRigidBody rigidBodyB) {
        super(gvrContext, Native3DFixedConstraint.ctor(rigidBodyB.getNative()));
    }

    static public long getComponentType() {
        return Native3DFixedConstraint.getComponentType();
    }
}

class Native3DFixedConstraint {
    static native long ctor( long rbB);

    static native long getComponentType();

}
