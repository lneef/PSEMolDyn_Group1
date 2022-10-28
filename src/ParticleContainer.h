#include<list>
#include<iterator>

#include "Particle.h"

class ParticleContainer{
	private:
		std::list<Particle> particles;
	
	public:
		class iterator{
			using iterator_category = std::forward_iterator_tag;
			using value_type = Particle;
			using difference_type = std::ptrdiff_t;
			using pointer = Particle*;
			using reference = Particle&;

			private:
				std::list<Particle>::iterator current;

			public:
				explicit iterator(std::list<Particle>::iterator current);
				iterator& operator++();
				iterator operator++(int);
				reference operator*() const;
				bool operator==(iterator it);
				bool operator!=(iterator it);

		};
		const std::list<Particle>& getParticles() const;
		void setParticles(const std::list<Particle>& particles);
		iterator begin();
		iterator end();
};
