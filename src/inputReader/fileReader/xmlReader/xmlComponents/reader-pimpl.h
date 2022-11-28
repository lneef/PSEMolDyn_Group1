//
// Created by dominik on 28.11.22.
//
#include "../cuboid-pskel.h"
#include "../../../../Simulation.h"

class reader_pimpl : public virtual reader_pskel {
protected:
    std::string in_values;
    std::vector<double> sim_values;
    std::vector<std::string> out_values;
    std::unique_ptr<Force> force;
    std::unique_ptr<outputWriter::FileWriter> writer;
    std::string filename;
    ParticleContainer &part;
public:
    virtual void pre(std::string filename, std::unique_ptr<Force> &force,
                     std::unique_ptr<outputWriter::FileWriter> &writer,ParticleContainer &particles);

    virtual void cuboid();

    virtual void simulation(std::vector<double> sim);

    virtual void output(std::vector<std::string> out);

    virtual void boundaries();

    virtual void input(std::string input_path);

    virtual Simulation post_reader();
};
