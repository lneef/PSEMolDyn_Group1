/*
 * FileReader.h
 *
 *  Created on: 23.02.2010
 *      Author: eckhardw
 */

#pragma once

#include "../Particle.h"

#include "../ParticleContainer.h"

#include "InputTemplate.h"
namespace inputReader{
class FileReader : public InputTemplate {

public:
    FileReader();

    virtual ~FileReader();

    void readFile(ParticleContainer &particles, char *filename);
};
}
