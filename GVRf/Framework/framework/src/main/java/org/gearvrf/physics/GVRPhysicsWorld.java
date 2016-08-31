package org.gearvrf.physics;


import java.util.LinkedList;

public final class GVRPhysicsWorld{
    private static float stepLength = 1.0f/60.0f;
    private static LinkedList<GVRRigidBody> rigidBodies = new LinkedList<GVRRigidBody>();

    public static void setStepLength(float stepLen)
    {
        stepLength = stepLen;
    }

    public static void addRigidBody(GVRRigidBody rigidBody) {
        NativePhysics3DWorld.addRigidBody(rigidBody.getNative());
        rigidBodies.add(rigidBody);
    }

    public static void removeRigidBody(GVRRigidBody rigidBody) {
        NativePhysics3DWorld.removeRigidBody(rigidBody.getNative());
        rigidBodies.remove(rigidBody);
    }

    public static void step() {
        NativePhysics3DWorld.step(stepLength);
    }

    public static void step(float stepLength) {
        setStepLength(stepLength);
        step();

        for(GVRRigidBody body : rigidBodies){
            body.updateTransform(body.getOwnerObject().getTransform());
        }
    }
}

class NativePhysics3DWorld {
    static native void addRigidBody(long jrigid_body);

    static native void removeRigidBody(long jrigid_body);

    static native void step(float jtime_step);
}   