package org.gearvrf.physics;

import org.gearvrf.GVRContext;

/**
 * Created by c.bozzetto on 19/05/2017.
 */

public class GVRPoint2PointConstraint extends GVRConstraint {
    public GVRPoint2PointConstraint(GVRContext gvrContext, GVRRigidBody rigidBodyB, float pivotInA[], float pivotInB[]) {
        super(gvrContext, Native3DPoint2PointConstraint.ctor(rigidBodyB.getNative(), pivotInA, pivotInB));
    }

    public void getPivotInA(float pivot[]) {
        Native3DPoint2PointConstraint.getPivotInA(pivot);
    }

    public void setPivotInA(final float pivot[]) {
        Native3DPoint2PointConstraint.setPivotInA(pivot[0], pivot[1], pivot[2]);
    }

    public void getPivotInB(float pivot[]) {
        Native3DPoint2PointConstraint.getPivotInB(pivot);
    }

    public void setPivotInB(final float pivot[]) {
        Native3DPoint2PointConstraint.setPivotInB(pivot[0], pivot[1], pivot[2]);
    }

    static public long getComponentType() {
        return Native3DPoint2PointConstraint.getComponentType();
    }
}

class Native3DPoint2PointConstraint {
    static native long ctor(long rbB, float pivotInA[], float pivotInB[]);

    static native long getComponentType();

    static native void setPivotInA(float x, float y, float z);

    static native void getPivotInA(float pivot[]);

    static native void setPivotInB(float x, float y, float z);

    static native void getPivotInB(float pivot[]);
}