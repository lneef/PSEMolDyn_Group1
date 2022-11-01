/*
 * XYZWriter.h
 *
 *  Created on: 01.03.2010
 *      Author: eckhardw
 */

#pragma once

#include "../Particle.h"
#include "../ParticleContainer.h"
#include "OutputTemplate.h"
#include <fstream>


namespace outputWriter {

class XYZWriter : public OutputTemplate{

public:
  XYZWriter();

  virtual ~XYZWriter();

  void plotParticles(ParticleContainer& particles, const std::string &filename,
                     int iteration) override;
};

} // namespace outputWriter
