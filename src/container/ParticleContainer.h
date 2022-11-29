

#pragma once

#include<vector>
#include<iterator>

#include "Particle.h"
#include "Container.h"

/**
 * @brief Class ParticleContainer provides a container for storing particles.
 * 
 * It encapsulates the data structure used to store the particles.
 * To enable simple iteration over the stored particles, ParticleContainer implements the iterator pattern.
*/

class ParticleContainer : public Container{
private:
    /**
     * @brief The data structure where the particles are stored internally.
    */
    std::vector<Particle> particles;


public:
    /**
     * @brief Getter for field particles.
     *
     * @return vector of particles
    */
    const std::vector<Particle> &getParticles() const;

    /**
     * @brief Setter for field particles
     *
     * @param particles vector of Particles
    */
    void setParticles(const std::vector<Particle> &particles);

    /**
     * @brief Inserts a Particle into ParticleContainer.
     *
     * @param particle rvalue reference to a Particle
    */
    void addParticle(Particle &&particle) override;

    /**
     * @brief Returns size of field particles.
     *
     * @return Number of particles stored in the respective ParticleContainer.
    */
    size_t size() override;

    /**
     * @brief overloaded access operator for ParticleContainer
     * @param i index which is accessed
     * @return lvalue reference to Particle at the passed index
     */
    Particle &operator[](size_t i);

    void applyX(std::function<void(Particle &)> fun) override;
    void applyF(std::function<void(Particle &, Particle &)> fun)  override;
    void addParticle(Particle& p) override;
    void apply(std::function<void(Particle &)> fun) override;
    ~ParticleContainer() override;
};
