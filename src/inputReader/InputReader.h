//
// Created by lukas on 08.11.22.
//

#pragma once

#include <memory>
#include "container/ParticleContainer.h"


namespace inputReader {
    /**
     * @brief InputReader provides a uniform interface for reading particles for any input type
     */
    class InputReader {
    public:
        /**
             * @brief reads particles from file and stores them in an instance of ParticleContainer
             *
             * @param particles ParticleContainer where the read particles are stored.
            */
        virtual void read(std::unique_ptr<ParticleContainer> &particles) = 0;

        virtual ~InputReader();

    };

}

