#pragma once

#include<string>
#include "../ParticleContainer.h"
namespace outputWriter{
class OutputTemplate{
public:
	virtual void plotParticles(ParticleContainer& particles, const std::string& filename, int iteration) = 0;
};
}
