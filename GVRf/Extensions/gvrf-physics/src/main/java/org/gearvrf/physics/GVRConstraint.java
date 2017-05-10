package org.gearvrf.physics;

import org.gearvrf.GVRComponent;
import org.gearvrf.GVRContext;

import java.util.List;

/**
 * Created by juliana.f on 5/10/17.
 */

abstract class GVRConstraint extends GVRComponent {
    protected GVRConstraint(GVRContext gvrContext, long nativePointer) {
        super(gvrContext, nativePointer);
    }

    protected GVRConstraint(GVRContext gvrContext, long nativePointer, List<NativeCleanupHandler> cleanupHandlers) {
        super(gvrContext, nativePointer, cleanupHandlers);
    }
}
