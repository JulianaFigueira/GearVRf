package org.gearvrf.physics;

import java.util.List;

import org.gearvrf.GVRContext;
import org.gearvrf.GVRHybridObject;

public class GVRPhysicsWorld extends GVRHybridObject {
    public GVRPhysicsWorld(GVRContext gvrContext,
            List<NativeCleanupHandler> cleanupHandlers) {
        super(gvrContext, NativePhysics3DWorld.ctor(), cleanupHandlers);
    }

    public GVRPhysicsWorld(GVRContext gvrContext) {
        super(gvrContext, NativePhysics3DWorld.ctor());
    }

    public void addRigidBody(GVRRigidBody rigidBody) {
        NativePhysics3DWorld.addRigidBody(getNative(), rigidBody.getNative());
    }

    public void removeRigidBody(GVRRigidBody rigidBody) {
        NativePhysics3DWorld.removeRigidBody(getNative(), rigidBody.getNative());
    }
}

class NativePhysics3DWorld {
    static native long ctor();

    static native void addRigidBody(long jworld, long jrigid_body);

    static native void removeRigidBody(long jworld, long jrigid_body);
}   