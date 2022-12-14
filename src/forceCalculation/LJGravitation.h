#pragma once
#include "Force.h"
#include "LennardJones.h"

class LJGravitation : public Force{
public:
    explicit LJGravitation(double g_arg);
    ~LJGravitation() override;
    void calculateF(std::shared_ptr<Container>& particles) override;
private:
    double g;
    LennardJones ljForce{};
};


