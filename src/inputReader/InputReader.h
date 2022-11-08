//
// Created by lukas on 08.11.22.
//
#include "../ParticleContainer.h"
#ifndef PSEMOLDYN_GROUP1_INPUTREADER_H
#define PSEMOLDYN_GROUP1_INPUTREADER_H

namespace inputReader {
    class InputReader {
    public:
        /**
             * @brief reads particles from file and stores them in an instance of ParticleContainer
             *
             * @param particles ParticleContainer where the read particles are stored.
            */
        virtual void read(ParticleContainer &particles) = 0;

        virtual ~InputReader();

    };

}
#endif //PSEMOLDYN_GROUP1_INPUTREADER_H
