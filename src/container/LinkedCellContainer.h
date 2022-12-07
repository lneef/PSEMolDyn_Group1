//
// Created by lukas on 29.11.22.
//
#pragma once

#include "Container.h"
#include "ParticleContainer.h"
#include "Reflecting.h"
#include <vector>

/**
 * @brief LinkedCellContainer implements the linked cell algorithm for a 2D simulation
 *
 * @warning The default boundary condition is outflow. If for a given boundary reflecting should be used, the condition must be added via addReflecting
 */
class LinkedCellContainer : public Container {
public:

    /**
     * applies the given function to the particles in the container
     * @param fun function taking lvalue reference to particle
     */
    void apply(std::function<void(Particle &)> fun) override;

    /**
     * @brief applies the given function to calculate the position of a particle
     * @param fun function taking lvalue reference to particle
     */
    void applyX(std::function<void(Particle &)> fun) override;

    /**
     * @brief overridden destructor to prevent memory leaks
     */
    ~LinkedCellContainer() override;

    /**
     * @brief adds a reflecting boundary condition to the container
     * @param ref rvalue reference to object of type Reflecting
     */
    void addReflecting(Reflecting &&ref);

    /**
     * @brief calculates the force effective on particles using the given function
     * @param fun std::function taking two lvalue reference to particles
     */
    void applyF(std::function<void(Particle &, Particle &)> fun) override;

    size_t size() override;

    /**
     * @brief adds a particle to linked cells
     * @param p rvalue reference to particle
     */
    void addParticle(Particle &&p) override;

    /**
     * @brief calculates the index of cells the given particle belongs to
     * @param p lvalue reference to particle
     * @return index of the particle in the linked cells data structure
     */
    size_t index(Particle &p);

    /**
     * @brief default constructor for LinkedCellContainer
     */
    LinkedCellContainer();

    /**
     * @brief setter for cutoff radius
     * @param rcutoff_arg cutoff radius for the linked cell algorihtm
     */
    void setRCutOff(double rcutoff_arg);

    /**
     * setter for the domain
     * @param domain_arg three dimensional vector representing the domain
     */
    void setDomain(std::array<double, 3> &domain_arg);

    /**
     * @brief funtion to initailize the linked cell algorithm for given domain and cutoff radius
     * @param rcutoff_arg cutoff radius for the linked cell algorithm
     * @param domain_arg domain the linked cells are covering
     */
    void setSize(double rcutoff_arg, std::array<double, 3> &domain_arg, size_t dim);


    /**
     * @brief function to get the cells for tests
     * @return std::vector representing the linked cells
     */
    std::vector<ParticleContainer>& getCells();

    /**
     * @brief returns the domain size
     * @return size of the domain
     */
    std::array<double, 3> &getDomain();

    /**
     * @brief returns particles in halo
     * @return lvalue reference to ParticleContainer containing particles in the halo
     */
    [[nodiscard]] const ParticleContainer &getHalo() const;

    /**
     * @brief returns reference to boundary cells
     * @return std::vector containing reference wrappers to boundary cells
     */
    [[nodiscard]] const std::vector<std::reference_wrapper<ParticleContainer>> &getBoundary() const;


private:

    /**
     * @brief std::vector to store the inner cells of the linked cell algorithm
     */
    std::vector<ParticleContainer> cells;

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
    std::vector<std::reference_wrapper<ParticleContainer>> halo;

    /**
     * @brief vector containing references to boundary cells
     */
    std::vector<std::reference_wrapper<ParticleContainer>> boundary;

    /**
     * @brief updates the boundary field after initialization
     */
    void setUp();

    /**
     * @brief vector containing reelecting boundaries
     */
    std::vector<Reflecting> conditions;

    /**
     * @brief applies reflecting boundary to particles in boundary cells
     * @param cond object representing reflecting boundary condition
     * @param fun function to calculate force
     */
    void applyFBoundary(Reflecting cond, std::function<void(Particle &, Particle &)> &fun);

    /**
     * @brief removes all particles from the halo
     */
    void clearHalo();


    /**
     * @brief adds particle to the halo
     * @param p lvalue reference to particle
     */
    void addHalo(Particle &p);

     /**
     * @brief adds a particle to linked cells
     * @param p lvalue reference to particle
     */
    void update(Particle &p);

    /**
     * @brief check if particle is inside the domain for 2D and 3D simualtions
     * @param p lvalue reference to particle
     * @return true if particle is inside the domain for the fourth dimension
     */
    bool inside3D(Particle& p);
};



