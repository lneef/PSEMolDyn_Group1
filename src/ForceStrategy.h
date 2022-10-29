//
// Created by dominik on 29.10.22.
//
#include "ForceCalc.h"
#include <memory>

class ForceStrategy {
private:
    std::unique_ptr <ForceCalc> forceType;
public:
    explicit ForceStrategy(std::unique_ptr <ForceCalc> &&forceType = {});

    void set_force(std::unique_ptr <ForceCalc> &&newForceType);
    std::unique_ptr <ForceCalc> getForceType() const;
    void calculateF(std::list <Particle> &particles);
};