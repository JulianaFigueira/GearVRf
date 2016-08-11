package org.gearvrf.physics;

import java.util.List;

import org.gearvrf.GVRCollider;
import org.gearvrf.GVRComponent;
import org.gearvrf.GVRContext;

public class GVRRigidBody extends GVRComponent {
    private final GVRCollider mCollider;

    public GVRRigidBody(GVRContext gvrContext,
            List<NativeCleanupHandler> cleanupHandlers, float mass,
            GVRCollider collider) {// TODO: Implement native constructor.
        super(gvrContext, Native3DRigidBody.ctor(mass, collider.getNative()), cleanupHandlers);

        mCollider = collider;
    }

    public GVRRigidBody(GVRContext gvrContext, float mass, GVRCollider collider) {
        super(gvrContext, Native3DRigidBody.ctor(mass, collider.getNative()));

        mCollider = collider;
    }

    static public long getComponentType() {
        return Native3DRigidBody.getComponentType();
    }

    public float getMass() {
        return Native3DRigidBody.getMass(getNative());
    }

    public GVRCollider getCollider() {
        return mCollider;
    }
}

class Native3DRigidBody {
    static native long ctor(float jmass, long jcollider);

    static native long getComponentType();

    static native float getMass(long jrigid_body);
}