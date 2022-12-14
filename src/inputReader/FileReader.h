
#pragma once

#include "Particle.h"
#include "InputReader.h"

namespace inputReader {

/**
 * @brief FileReader provides a uniform interface for reading particles from a file
 * 
 * The class provides the abstract method readFile() which is implemented by its subclasses. This enables easier extensibility and integration of the methods used to read particles from files.
 * 
*/
    class FileReader : public InputReader {
    public:
        /**
         * @brief virtual destructor to prevent memory leaks
        */
        ~FileReader() override;

    protected:
        /**
         * @brief filename of the file from where the input is read
         */
        std::string filename;
    };
}
