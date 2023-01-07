#pragma once
#include "Particle.h"
#include <vector>

class ParticleIterator {
    /**
     * @brief category of the iterator is forward_iterator
     */
    using iterator_category = std::forward_iterator_tag;

    /**
     * @brief difference_type for iterator
     */
    using difference_type = std::ptrdiff_t;

    /**
     * @brief iterator stores values of type Particle
     */
    using value_type = Particle;

    /**
     * @brief pointer type for the iterator
     */
    using pointer = Particle *;

    /**
     * @brief reference type of the iterator
     */
    using reference = Particle &;
public:
    /**
     * @brief first inequality operator for ParticleIterator
     * @param it2 lvalue reference to object of type ParticleIterator
     * @return true, if both iterator point to the same element
     */
    bool operator!=(ParticleIterator &it2);

    /**
     *
     * @param it2
     * @return
     */
    bool operator!=(ParticleIterator &&it2);

    /**
     * @brief constructor of ParticleIterator
     * @param ref std::vector::iterator the ParticleIterator should point to
     */
    explicit ParticleIterator(std::vector<Particle>::iterator ref);

    /**
    * @brief dereference operator for ParticleIterator
    * @return reference to particle pointed to by the iterator
    */
    reference operator*();

    /**
    * @brief preincrement operator for ParticleIterator
    * @return lvalue reference to ParticleIterator
    */
    ParticleIterator &operator++();

    /**
     * @brief
     * @return pointer to the current element
     */
    pointer operator->();

    /**
     * @brief getter for internal representation of the iterator
     * @return
     */
    std::vector<Particle>::iterator &get();

private:
    /**
     * @brief iterator to represent the state of ParticleIterator internally
     */
    std::vector<Particle>::iterator it;
};