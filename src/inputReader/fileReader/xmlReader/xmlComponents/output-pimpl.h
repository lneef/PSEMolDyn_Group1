//
// Created by dominik on 26.11.22.
//

#include "../cuboid-pskel.h"

class output_pimpl: public virtual output_pskel
{
public:
    virtual void
    pre ();

    virtual void
    name (const ::std::string&);

    virtual void
    frequency (double);

    virtual void
    post_output ();
};