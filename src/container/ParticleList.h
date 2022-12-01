//
// Created by lukas on 29.11.22.
//
#pragma once

#include <list>
#include "Container.h"
class ParticleList : Container{
public:
    void apply(std::function<void(Particle &)> fun) override;
    void applyX(std::function<void(Particle &)> fun) override ;
    ~ParticleList() override;
    void applyF(std::function<void(Particle &, Particle &)> fun) override ;
    size_t size() override;
    void addParticle(Particle& p) override;
    void addParticle(Particle&& p) override;
    std::list<Particle>::iterator begin();
    std::list<Particle>::iterator end();
    std::list<Particle>::iterator remove(std::list<Particle>::iterator &iterator);
private:
    std::list<Particle> particles;


};


