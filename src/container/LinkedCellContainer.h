//
// Created by lukas on 29.11.22.
//
#pragma once

#include "Container.h"
#include "ParticleList.h"
#include "ParticleContainer.h"
#include "BoundaryCell.h"
#include "Reflecting.h"
#include <vector>

/**
 * @brief LinkedCellContainer implements the linked cell algorithm for a 2D simulation
 */
class LinkedCellContainer : public Container {
public:

    void apply(std::function<void(Particle &)> fun) override;

    void applyX(std::function<void(Particle &)> fun) override;

    ~LinkedCellContainer() override;

    void addReflecting(Reflecting && ref);

    void applyF(std::function<void(Particle &, Particle &)> fun) override;

    size_t size() override;

    void addParticle(Particle &p) override;

    void addParticle(Particle &&p) override;

    size_t index(Particle &p);

    LinkedCellContainer();
    std::vector<ParticleList>& get();

    /**
     * @brief setter for cutoff radius
     * @param rcutoff_arg cutoff radius for the linked cell algorihtm
     */
    void setRCutOff(double rcutoff_arg);

    /**
     * setter for the domain
     * @param domain_arg three dimensional vector representing the domain
     */
    void setDomain(std::array<double, 3>& domain_arg);

    /**
     * @brief funtion to initailize the linked cell algorithm for given domain and cutoff radius
     * @param rcutoff_arg cutoff radius for the linked cell algorithm
     * @param domain_arg domain the linked cells are covering
     */
    void setSize(double rcutoff_arg, std::array<double,3>& domain_arg);


    /**
     * @brief function to get the cells for tests
     * @return std::vector representing the linked cells
     */
    std::vector<ParticleList> getCells();

    std::array<double, 3>& getDomain();

    [[nodiscard]] const ParticleContainer& getHalo() const;

    [[nodiscard]] const std::vector<BoundaryCell>& getBoundary() const;


private:

    /**
     * @brief std::vector to store the inner cells of the linked cell algorithm
     */
    std::vector<ParticleList> cells;

    /**
     * @brief array to hold the number of cells in all three dimensions
     */
    std::array<size_t, 3> mesh{};

    /**
     * @brief vector spanning the domain which is covered by the cells
     */
    std::array<double, 3> domain{};

    /**
     * @brief cutoff radius, i.e. length of the sides of the cells
     */
    double rcutoff{};

    /**
     * @brief updates the cell a particle is contained in after calculating the positions
     */
    void update();

    /**
     * @brief ParticleContainer storing the particles in the halo
     */
    ParticleContainer halo;

    /**
     * @brief vector containing references to boundary cells
     */
    std::vector<BoundaryCell> boundary;

    /**
     * @brief updates the boundary field after initialization
     */
    void setUpBoundary();

    std::vector<Reflecting> conditions;

    void applyFBoundary(Reflecting cond, std::function<void(Particle &, Particle &)>& fun);

    void clearHalo();
};



