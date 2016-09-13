package org.gearvrf.physics;

import org.gearvrf.GVRComponent;
import org.gearvrf.GVRContext;
import org.gearvrf.GVRSceneObject;
import org.gearvrf.GVRTransform;

import java.util.List;

public class GVRRigidBody extends GVRComponent {

    public GVRRigidBody(GVRContext gvrContext,
            List<NativeCleanupHandler> cleanupHandlers, GVRSceneObject sceneObject) {
        super(gvrContext, Native3DRigidBody.ctor(sceneObject.getNative()), cleanupHandlers);
    }

    public GVRRigidBody(GVRContext gvrContext, GVRSceneObject sceneObject) {
        super(gvrContext, Native3DRigidBody.ctor(sceneObject.getNative()));
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
       // GVRPhysicsWorld.addRigidBody(this);
    }

    @Override
    public void onDetach(GVRSceneObject oldOwner) {
        //GVRPhysicsWorld.removeRigidBody(this);
    }

}

class Native3DRigidBody {
    static native long ctor(long jscene_object);

    static native long getComponentType();

    static native float getMass(long jrigid_body);

    static native float setMass(long jrigid_body, float jmass);

    static native long updateTransform(long jrigid_body, long jtransform);
}