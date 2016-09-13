//
// Created by juliana.f on 9/12/2016.
//

#ifndef FRAMEWORK_BULLET_BODYINFO_H
#define FRAMEWORK_BULLET_BODYINFO_H

#include "../physics3d/physics_3dbodyinfo.h"

namespace gvr {
class BulletBodyInfo : public Physics3DBodyInfo {
public:
    BulletBodyInfo(float mass){}

    void setMass(float mass)
    {
        mMass = mass;
    }

    float getMass()
    {
        return mMass;
    }

private:
    float mMass;
};
}
#endif //FRAMEWORK_BULLET_BODYINFO_H
