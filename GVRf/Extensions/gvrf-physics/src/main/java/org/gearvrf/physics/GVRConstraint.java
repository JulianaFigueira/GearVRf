package org.gearvrf.physics;

import org.gearvrf.GVRContext;

import java.util.List;

abstract class GVRConstraint extends GVRPhysicsWorldObject {

    protected GVRConstraint(GVRContext gvrContext, long nativePointer) {
        super(gvrContext, nativePointer);
    }

    protected GVRConstraint(GVRContext gvrContext, long nativePointer, List<NativeCleanupHandler> cleanupHandlers) {
        super(gvrContext, nativePointer, cleanupHandlers);
    }

    @Override
    protected void addToWorld(GVRWorld world) {
        if (world != null) {
            world.addConstraint(this);
        }
    }

    @Override
    protected void removeFromWorld(GVRWorld world) {
        if (world != null) {
            world.removeConstraint(this);
        }
    }
}
