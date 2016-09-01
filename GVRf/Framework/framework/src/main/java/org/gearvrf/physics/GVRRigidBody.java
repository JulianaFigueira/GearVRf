package org.gearvrf.physics;

import org.gearvrf.GVRCollider;
import org.gearvrf.GVRComponent;
import org.gearvrf.GVRContext;
import org.gearvrf.GVRSceneObject;
import org.gearvrf.GVRTransform;

import java.util.List;

public class GVRRigidBody extends GVRComponent {
    private final GVRCollider mCollider;

    public GVRRigidBody(GVRContext gvrContext,
            List<NativeCleanupHandler> cleanupHandlers, float mass,
            GVRCollider collider) {// TODO: Implement native constructor.
        super(gvrContext, Native3DRigidBody.ctor(mass, collider.getNative(), collider.getTransform().getNative()), cleanupHandlers);

        mCollider = collider;
    }

    public GVRRigidBody(GVRContext gvrContext, float mass, GVRCollider collider, GVRTransform transform) {
        super(gvrContext, Native3DRigidBody.ctor(mass, collider.getNative(), transform.getNative()));

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

    /**
     * Get the transform of the scene object this component is attached to and update with the
     * native values from bullet.
     */
    public void updateTransform(GVRTransform transform) {
        Native3DRigidBody.updateTransform(getNative(), transform.getNative());
    }

    @Override
    public void onAttach(GVRSceneObject newOwner) {
        GVRPhysicsWorld.addRigidBody(this);
    }

    @Override
    public void onDetach(GVRSceneObject oldOwner) {
        GVRPhysicsWorld.removeRigidBody(this);
    }

}

class Native3DRigidBody {
    static native long ctor(float jmass, long jcollider, long jtransform);

    static native long getComponentType();

    static native float getMass(long jrigid_body);

    static native long updateTransform(long jrigid_body, long jtransform);
}