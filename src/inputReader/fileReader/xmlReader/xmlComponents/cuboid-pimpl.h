//
// Created by dominik on 26.11.22.
//

#include "../cuboid-pskel.h"

class cuboid_pimpl : public virtual cuboid_pskel {
public:
    virtual void
    pre();

    virtual void
    x(double);

    virtual void
    n(int);

    virtual void
    h(double);

    virtual void
    m(double);

    virtual void
    v(double);

    virtual void
    post_cuboid();
};