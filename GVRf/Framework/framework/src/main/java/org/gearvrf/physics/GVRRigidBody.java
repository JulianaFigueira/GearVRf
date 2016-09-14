package org.gearvrf.physics;

import org.gearvrf.GVRComponent;
import org.gearvrf.GVRContext;
import org.gearvrf.GVRSceneObject;
import org.gearvrf.GVRTransform;

import java.security.acl.Owner;
import java.util.List;

public class GVRRigidBody extends GVRComponent {

    public GVRRigidBody(GVRContext gvrContext, List<NativeCleanupHandler> cleanupHandlers) {
        super(gvrContext, Native3DRigidBody.ctor(), cleanupHandlers);
    }

    public GVRRigidBody(GVRContext gvrContext) {
        super(gvrContext, Native3DRigidBody.ctor());
    }

    static public long getComponentType() {
        return Native3DRigidBody.getComponentType();
    }

    public float getMass() {
        return Native3DRigidBody.getMass(getNative());
    }

    public void setMass(float mass) {
        Native3DRigidBody.setMass(getNative(), mass);
    }

    /**
     * Get the transform of the scene object this component is attached to and update with the
     * native values from bullet.
     */
    public void updateTransform(GVRTransform transform) {
        Native3DRigidBody.updateTransform(getNative(), transform.getNative());
    }

    @Override
    public void onAttach(GVRSceneObject newOwner) {
       if(newOwner.getCollider() == null)
           throw new RuntimeException("GVRSceneObject needs a Collider for this operation");
        else
           Native3DRigidBody.onAttach();
    }

    @Override
    public void onDetach(GVRSceneObject oldOwner) {
        if(oldOwner.getCollider() != null)
            Native3DRigidBody.onDetach();
        //else do nothing
    }

}

class Native3DRigidBody {
    static native long ctor();

    static native long getComponentType();

    static native float getMass(long jrigid_body);

    static native float setMass(long jrigid_body, float jmass);

    static native long updateTransform(long jrigid_body, long jtransform);

    static native void onAttach();

    static native void onDetach();
}