package org.gearvrf.physics;

import org.gearvrf.GVRComponent;
import org.gearvrf.GVRContext;
import java.util.List;

public class GVRPhysicsBodyInfo extends GVRComponent {
    private float mMass;

    protected GVRPhysicsBodyInfo(GVRContext gvrContext, List<NativeCleanupHandler> cleanupHandlers, float mass) {
        super(gvrContext, Native3DPhysicsBodyInfo.ctor(mass), cleanupHandlers);
    }

    public GVRPhysicsBodyInfo(GVRContext gvrContext, float mass) {
        super(gvrContext, Native3DPhysicsBodyInfo.ctor(mass));
    }

    static public long getComponentType() {
        return Native3DPhysicsBodyInfo.getComponentType();
    }

    public float getMass() {
        return Native3DPhysicsBodyInfo.getMass(this.getNative());
    }

    public void setMass(float mass) {
        Native3DPhysicsBodyInfo.setMass(this.getNative(), mass);
    }
}

class Native3DPhysicsBodyInfo {
    static native long ctor(float jmass);

    static native long getComponentType();

    static native float getMass(long jphysics_body_info);

    static native void setMass(long jphysics_body_info, float jmass);
}
