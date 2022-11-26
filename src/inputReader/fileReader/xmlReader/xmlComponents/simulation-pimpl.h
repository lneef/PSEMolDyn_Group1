//
// Created by dominik on 26.11.22.
//
#include "../cuboid-pskel.h"

class simulation_pimpl : public virtual simulation_pskel {
protected:
    double end_time;
    double delta_time;
public:
    virtual void pre();

    virtual void t_end(double);

    virtual void delta_t(double);

    virtual std::vector<double> post_simulation();
};