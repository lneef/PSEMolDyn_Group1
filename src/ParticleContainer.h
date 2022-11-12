

#pragma once

#include<vector>
#include<iterator>

#include "Particle.h"

/**
 * @brief Class ParticleContainer provides a container for storing particles.
 * 
 * It encapsulates the data structure used to store the particles.
 * To enable simple iteration over the stored particles, ParticleContainer implements the iterator pattern.
*/

class ParticleContainer {
private:
    /**
     * @brief The data structure where the particles are stored internally.
    */
    std::vector<Particle> particles;


public:
    /**
     * @brief The class iterator implements the iterator pattern for ParticleContainer.
     * 
     * It provides an iterator over the particles stored in the field particles of ParticleContainer.
    */
    class iterator {

        /**
         * @brief iterator should enable iteration over stored particles and thus is of type forward_iterator.
        */
        using iterator_category = std::forward_iterator_tag;

        /**
         * @brief iteration happens over value of type Particle.
        */
        using value_type = Particle;

        /**
         * @brief difference between iterator is of type std::ptrdiff_t.
         *
        */
        using difference_type = std::ptrdiff_t;

        /**
         * @brief iteration over Particles with pointers of type Particle*.
        */
        using pointer = Particle *;

        /**
         * @brief iteration over Particles with references of type Particle&.
        */
        using reference = Particle &;

    private:
        /**
         * @brief iteration uses a iterator for the data structure where the particles are stored internally to enable iteration
         *
         * @see particles
        */
        std::vector<Particle>::iterator current;

    public:
        /**
         * @brief Constructor to create iterators for begin() and end()
         *
         * @param current iterator which points to an element of particles
        */
        explicit iterator(std::vector<Particle>::iterator current);

        /**
         * @brief Pre-increment operator for class iterator.
        */
        iterator &operator++();

        /**
         * @brief Post-increment operator for class iterator.
        */
        iterator operator++(int);

        /**
         * @brief Dereference operator for class iterator.
        */
        reference operator*() const;

        /**
         * equality operator checks if two instances point to the same position
         *
         * @param it iterator to be checked for equality with this
         *
         * @return true if both iterator point to the same position, false otherwise
         */
        bool operator==(iterator it);

        /**
         * inequality operator checks if two instance point to different positions
         *
         * @param it iterator to be checked for inequality with this
         *
         * @return true if both iterator point to different positions, false otherwise
        */
        bool operator!=(iterator it);

    };

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
     * @brief return iterator pointing to the first element of the field particles
     *
     * @return iterator pointing to the first element stored in the object of type ParticleContainer
    */
    iterator begin();

    /**
     * @brief returns iterator pointing behind the last elements of the field particles
     *
     * @return iterator pointing behing the last element stored in the object of type ParticleContainer.
    */
    iterator end();

    /**
     * @brief Inserts a Particle into ParticleContainer.
     *
     * @param particle rvalue reference to a Particle
    */
    void addParticle(Particle &&particle);

    /**
     * @brief Returns size of field particles.
     *
     * @return Number of particles stored in the respective ParticleContainer.
    */
    size_t size();

    /**
     * @brief function to iterate over particles and to call function passed as argument for each particle
     * @tparam T function taking Particle& and returning void
     * @param fun function working on particle passed as argument
     */
    template<class T>
    void apply(T fun) {
        for (auto &p: particles) {
            fun(p);
        }
    }

    template<class T>
    void apply2(T fun) {
        size_t len = particles.size();
        for (size_t i = 0; i < len; ++i) {
            for (size_t j = i + 1; j < len; ++j) {
                fun(particles[i], particles[j]);
            }
        }
    }
};
