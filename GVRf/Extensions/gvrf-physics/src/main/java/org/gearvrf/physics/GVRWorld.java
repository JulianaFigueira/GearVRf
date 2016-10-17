/* Copyright 2015 Samsung Electronics Co., LTD
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package org.gearvrf.physics;

import org.gearvrf.GVRBehavior;
import org.gearvrf.GVRContext;
import org.gearvrf.GVRSceneObject;
import org.gearvrf.ISceneObjectEvents;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Objects;


/**
 *  Represents a physics world where all {@link GVRSceneObject} with {@link GVRRigidBody} component
 *  attached to are simulated.
 *
 *  {@link GVRWorld} is a component that must be attached to the scene's root object.
 */

public class GVRWorld extends GVRBehavior implements ISceneObjectEvents {
    private Map<Long, GVRRigidBody> mRigidBodies = new HashMap<Long, GVRRigidBody>();
    private LinkedList<GVRCollisionInfo> mPreviousCollisions = new LinkedList<GVRCollisionInfo>();

    static {
        System.loadLibrary("gvrf-physics");
    }

    public GVRWorld(GVRContext gvrContext) {
        super(gvrContext, NativePhysics3DWorld.ctor());
        mHasFrameCallback = false;
    }

    static public long getComponentType() { return NativePhysics3DWorld.getComponentType(); }

    public boolean addBody(GVRRigidBody gvrBody) {
        this.mRigidBodies.put(gvrBody.getNative(), gvrBody);
        return NativePhysics3DWorld.addRigidBody(getNative(), gvrBody.getNative());
    }

    public void removeBody(GVRRigidBody gvrBody) {
        this.mRigidBodies.remove(gvrBody.getNative());
        NativePhysics3DWorld.removeRigidBody(getNative(), gvrBody.getNative());
    }

    @Override
    public void onDrawFrame(float frameTime) {
        NativePhysics3DWorld.step(getNative(), frameTime);
        generateCollisionEvents();
    }

    private void generateCollisionEvents(){
        LinkedList<GVRCollisionInfo> collisionInfos = new LinkedList<GVRCollisionInfo>();

        if (!NativePhysics3DWorld.listCollisions(getNative(), collisionInfos)){
            return;
        }

        for (GVRCollisionInfo info : collisionInfos){

            String eventName = "";

            if (mPreviousCollisions.contains(info)) {
                mPreviousCollisions.remove(info);
                eventName = "onInside";
            } else {
                eventName = "onEnter";
            }

            sendCollisionEvent(info, eventName);
        }

        for ( GVRCollisionInfo cp : mPreviousCollisions){
            sendCollisionEvent(cp, "onExit");
        }

        mPreviousCollisions = collisionInfos;
    }

    private void sendCollisionEvent(GVRCollisionInfo info, String eventName) {
        GVRSceneObject bodyA = mRigidBodies.get(info.bodyA).getOwnerObject();
        GVRSceneObject bodyB = mRigidBodies.get(info.bodyB).getOwnerObject();

        if (bodyA.getEventReceiver() != null) {
            getGVRContext().getEventManager().sendEvent(bodyA, ICollisionEvents.class, eventName,
                    bodyA, bodyB, info.normal, info.distance);
        }
    }

    @Override
    public void onAttach(GVRSceneObject newOwner) {
        super.onAttach(newOwner);

        //FIXME: Implement a way to check if already exists a GVRWold attached to the scene
        if (newOwner.getParent() != null) {
            throw new RuntimeException("GVRWold must be attached to the scene's root object!");
        }

        if (!mHasFrameCallback) {
            newOwner.getEventReceiver().addListener(this);
        }
    }

    @Override
    public void onDetach(GVRSceneObject oldOwner) {
        super.onDetach(oldOwner);

        if (!mHasFrameCallback) {
            oldOwner.getEventReceiver().removeListener(this);
        }
    }

    @Override
    public void onInit(GVRContext gvrContext, GVRSceneObject sceneObject) {
        if (mHasFrameCallback)
            return;

        mHasFrameCallback = true;
        getOwnerObject().getEventReceiver().removeListener(this);

        if (isEnabled()) {
            startListening();
        }
    }

    @Override
    public void onLoaded() {

    }

    @Override
    public void onAfterInit() {

    }

    @Override
    public void onStep() {

    }
}

class NativePhysics3DWorld {
    static native long ctor();

    static native long getComponentType();

    static native boolean addRigidBody(long jphysics_world, long jrigid_body);

    static native void removeRigidBody(long jphysics_world, long jrigid_body);

    static native void step(long jphysics_world, float jtime_step);

    static native boolean listCollisions(long jphysics_world, Object jnewlist);
}
