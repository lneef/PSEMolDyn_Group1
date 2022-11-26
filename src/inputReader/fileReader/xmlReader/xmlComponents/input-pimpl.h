//
// Created by dominik on 26.11.22.
//

#include "../cuboid-pskel.h"

class input_pimpl: public virtual input_pskel
{
public:
    virtual void
    pre ();

    virtual void
    path (const ::std::string&);

    virtual void
    post_input ();
};