

#pragma once

#include<vector>
#include<iterator>

#include "Particle.h"

/**
 * ParticleContainer provides a data structure for storing particles.
 * 
 * To enable simple iteration over the stored particles, ParticleContainer implements a custom iterator.
 * 
*/

class ParticleContainer{
	private:
		/**
		 * The data structure where the particles are stored internally.
		*/
		std::vector<Particle> particles;
	

	public:
		/**
		 * Custom iterator for the container ParticleContainer.
		*/
		class iterator{
			using iterator_category = std::forward_iterator_tag;
			using value_type = Particle;
			using difference_type = std::ptrdiff_t;
			using pointer = Particle*;
			using reference = Particle&;

			private:
				std::vector<Particle>::iterator current;

			public:
				explicit iterator(std::vector<Particle>::iterator current);
				iterator& operator++();
				iterator operator++(int);
				reference operator*() const;
				bool operator==(iterator it);
				bool operator!=(iterator it);

		};

		/**
		 * @brief Getter for field particles.
		 * 
		 * @return vector of particles
		*/
		const std::vector<Particle>& getParticles() const;

		/**
		 * @brief Setter for field particles 
		 * 
		 * @param particles vector of Particles
		*/
		void setParticles(const std::vector<Particle>& particles);
		iterator begin();
		iterator end();

		void addParticle(Particle&& particle);
		size_t size();
};
