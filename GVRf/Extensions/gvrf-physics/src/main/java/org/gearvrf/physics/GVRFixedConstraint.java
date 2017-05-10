package org.gearvrf.physics;

import org.gearvrf.GVRComponent;
import org.gearvrf.GVRContext;
import org.gearvrf.GVRSceneObject;

/**
 * Created by juliana.f on 5/10/17.
 */

public class GVRFixedConstraint extends GVRConstraint {

    public GVRFixedConstraint(GVRContext gvrContext, GVRRigidBody rigidBodyB) {
        super(gvrContext, Native3DFixedConstraint.ctor(rigidBodyB.getNative()));
    }

    static public long getComponentType() {
        return Native3DFixedConstraint.getComponentType();
    }

    /**
     * Returns the {@linkplain GVRWorld physics world} of this {@linkplain GVRRigidBody rigid body}.
     *
     * @return The physics world of this {@link GVRRigidBody}
     */
    public GVRWorld getWorld() {
        return getWorld(getOwnerObject());
    }

    /**
     * Returns the {@linkplain GVRWorld physics world} of the {@linkplain org.gearvrf.GVRScene scene}.
     *
     * @param owner Owner of the {@link GVRRigidBody}
     * @return Returns the {@link GVRWorld} of the scene.
     */
    private static GVRWorld getWorld(GVRSceneObject owner) {
        return getWorldFromAscendant(owner);
    }

    /**
     * Looks for {@link GVRWorld} component in the ascendants of the scene.
     *
     * @param worldOwner Scene object to search for a physics world in the scene.
     * @return Physics world from the scene.
     */
    private static GVRWorld getWorldFromAscendant(GVRSceneObject worldOwner) {
        GVRComponent world = null;

        while (worldOwner != null && world == null) {
            world = worldOwner.getComponent(GVRWorld.getComponentType());
            worldOwner = worldOwner.getParent();
        }

        return (GVRWorld) world;
    }

    @Override
    public void onAttach(GVRSceneObject newOwner) {
        if (newOwner.getCollider() == null) {
            throw new UnsupportedOperationException("You must have a collider attached to the scene object before attaching the rigid body");
        }
        if ((newOwner.getRenderData() == null) ||
                (newOwner.getRenderData().getMesh() == null)) {
            throw new UnsupportedOperationException("You must have a mesh attached to the scene object before attaching the rigid body");
        }
        super.onAttach(newOwner);
        if (isEnabled()) {
            addToWorld(getWorld(newOwner));
        }
    }

    @Override
    public void onDetach(GVRSceneObject oldOwner) {
        super.onDetach(oldOwner);
        if (isEnabled()) {
            removeFromWorld(getWorld(oldOwner));
        }
    }

    @Override
    public void onNewOwnersParent(GVRSceneObject newOwnersParent) {
        if (isEnabled()) {
            addToWorld(getWorld(newOwnersParent));
        }
    }

    @Override
    public void onRemoveOwnersParent(GVRSceneObject oldOwnersParent) {
        if (isEnabled()) {
            removeFromWorld(getWorld(oldOwnersParent));
        }
    }

    @Override
    public void onEnable() {
        super.onEnable();

        addToWorld(getWorld());
    }

    @Override
    public void onDisable() {
        super.onDisable();

        removeFromWorld(getWorld());
    }


    private void addToWorld(GVRWorld world) {
        if (world != null) {
            world.addConstraint(this);
        }
    }

    private void removeFromWorld(GVRWorld world) {
        if (world != null) {
            world.removeConstraint(this);
        }
    }
}

class Native3DFixedConstraint {
    static native long ctor( long rbB);

    static native long getComponentType();


}
