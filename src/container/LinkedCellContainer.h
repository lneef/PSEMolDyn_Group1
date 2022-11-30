//
// Created by lukas on 29.11.22.
//
#pragma once

#include "Container.h"
#include "ParticleList.h"
#include <vector>

class LinkedCellContainer : public Container {
public:
    void apply(std::function<void(Particle &)> fun) override;
    void applyX(std::function<void(Particle &)> fun) override ;
    ~LinkedCellContainer() override;
    void applyF(std::function<void(Particle &, Particle &)> fun) override ;
    size_t size() override;
    void addParticle(Particle& p) override;
    void addParticle(Particle&& p) override;
    int index(Particle &p);
    LinkedCellContainer(std::array<int, 3> mesh_arg, double rcutoff_arg, std::vector<ParticleList>& list);

    std::vector<ParticleList> getCells() const;
private:
    std::vector<ParticleList> cells;

    std::array<int, 3> mesh;
    double rcutoff;

    void update();
};



