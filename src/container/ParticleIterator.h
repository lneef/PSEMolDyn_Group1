#include "Particle.h"
#include "ParticleContainer.h"
#include <vector>

class ParticleIterator{
    using iterator_category = std::forward_iterator_tag;
    using difference_type   = std::ptrdiff_t;
    using value_type        = Particle;
    using pointer           = Particle*;
    using reference         = Particle&;
public:
    bool operator!=(ParticleIterator& it2);
    bool operator!=(ParticleIterator&& it2);
    explicit ParticleIterator(std::vector<Particle>::iterator ref);

    reference operator*();
    ParticleIterator& operator++();

    std::vector<Particle>::iterator & get();
private:
    std::vector<Particle>::iterator it;
};