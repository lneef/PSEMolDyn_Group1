//
// Created by lukas on 08.11.22.
//

#pragma once

#include <memory>
#include "container/ParticleContainer.h"
#include "Simulation.h"


namespace inputReader {
    /**
     * @brief InputReader provides a uniform interface for reading particles for any input type
     */
    class InputReader {
    public:
        /**
             * @brief reads particles from file and initializes simulation
             *@param sim object of type Simulation that is initialized by the respective reader of the subclasses
             *
            */
        virtual void read(std::shared_ptr<Simulation> &sim) = 0;

        virtual ~InputReader();

    };

}

