//
// Created by dominik on 26.11.22.
//

#include "../cuboid-pskel.h"

class input_pimpl : public virtual input_pskel {
protected:
    std::string input_path;
public:
    virtual void pre();

    virtual void path(const ::std::string &);

    virtual std::string post_input();
};