//
// Created by dominik on 27.11.22.
//

#include "xmlComponents/boundaries-pimpl.h"
#include "xmlComponents/cuboid-pimpl.h"
#include "xmlComponents/input-pimpl.h"
#include "xmlComponents/output-pimpl.h"
#include "xmlComponents/simulation-pimpl.h"
#include "xmlComponents/reader-pimpl.h"
#include "../../../Simulation.h"
#include "../FileReader.h"

namespace inputReader {
    class Cuboid_XMLFile : public inputReader::FileReader {
    protected:
        boundaries_pimpl boundaries_parser;
        cuboid_pimpl cuboid_parser;
        input_pimpl input_parser;
        output_pimpl output_parser;
        simulation_pimpl simulation_parser;
        reader_pimpl reader_parser;
        xml_schema::double_pimpl double_parser;
        xml_schema::int_pimpl int_parser;
        xml_schema::string_pimpl string_parser;
        std::unique_ptr<Force> force;
        std::unique_ptr<outputWriter::FileWriter> writer;
    public:
        explicit Cuboid_XMLFile(std::string filename, std::unique_ptr<Force> &force,
                                std::unique_ptr<outputWriter::FileWriter> &writer);

        ~Cuboid_XMLFile();

        void read(ParticleContainer &particles) override;
    };
}
