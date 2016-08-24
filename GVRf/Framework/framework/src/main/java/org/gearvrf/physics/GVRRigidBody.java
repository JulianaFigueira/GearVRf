package org.gearvrf.physics;

import java.util.List;

import org.gearvrf.GVRCollider;
import org.gearvrf.GVRComponent;
import org.gearvrf.GVRTransform;
import org.gearvrf.GVRContext;

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
        float[] trans = new float[7];
        trans = Native3DRigidBody.getCollisionTransform(getNative());

        if( trans[0] == 0.0f && trans[1] == 0.0f && trans[2] == 0.0f && trans[3] == 0.0f && trans[4] == 0.0f && trans[5] == 0.0f && trans[6] == 0.0f)
            throw new RuntimeException("NO VALUESSSSSSS!!!!!!!! \n\n");

        transform.setRotation(trans[0], trans[1],trans[2], trans[3]);
        transform.setPosition(trans[4],trans[5],trans[6]);


    }

}

class Native3DRigidBody {
    static native long ctor(float jmass, long jcollider, long jtransform);

    static native long getComponentType();

    static native float getMass(long jrigid_body);

    static native float[] getCollisionTransform(long jrigid_body);
}