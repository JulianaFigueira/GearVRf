package org.gearvrf.physics;

import org.gearvrf.GVRContext;
import org.gearvrf.GVRHybridObject;
import org.gearvrf.GVRSceneObject;

import java.util.List;

public final class GVRPhysicsWorld extends GVRSceneObject {
    private static float stepLength = 1.0f/60.0f;

    public GVRPhysicsWorld(GVRContext gvrContext) {
        super(gvrContext);
        NativePhysics3DWorld.ctor();
    }

    private void addRigidBody(GVRRigidBody rigidBody) {
        NativePhysics3DWorld.addRigidBody(rigidBody.getNative());
    }

    private void removeRigidBody(GVRRigidBody rigidBody) {
        NativePhysics3DWorld.removeRigidBody(rigidBody.getNative());
    }

    @Override
    public boolean addChildObject(GVRSceneObject child) {
        boolean result = super.addChildObject(child);

        if(result) {
            GVRRigidBody body = (GVRRigidBody) child.getComponent(GVRRigidBody.getComponentType());
            if (body == null) {
                //TODO: if collider, create ghost body
            } else {
                this.addRigidBody(new GVRRigidBody(this.getGVRContext()));
            }
        }
        return result;
    }

    @Override
    public void removeChildObject(GVRSceneObject child){
        boolean result = super.addChildObject(child);

        if(result) {
                GVRRigidBody body = (GVRRigidBody) child.getComponent(GVRRigidBody.getComponentType());
            if(body == null) {
                //TODO: if collider, remove ghost body
            }else
            {
                this.removeRigidBody(new GVRRigidBody(this.getGVRContext()));
            }
        }
    }

    public void setStepLength(float stepLen) {
        stepLength = stepLen;
    }

    public void step() {
        NativePhysics3DWorld.step(stepLength);
    }

    public void step(float stepLength) {
        setStepLength(stepLength);
        step();
    }

}

class NativePhysics3DWorld {
    static native long ctor();

    static native void addRigidBody(long jrigid_body);

    static native void removeRigidBody(long jrigid_body);

    static native void step(float jtime_step);
}   