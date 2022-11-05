
#include "inputReader/TxtReader.h"
#include "outputWriter/VTKWriter.h"
#include "utils/ArrayUtils.h"

#include <iostream>
#include <memory>

#include "forceCalculation/Gravitation.h"
#include "forceCalculation/Force.h"
#include "ParticleContainer.h"
#include "forceCalculation/LennardJones.h"

/**** forward declaration of the calculation functions ****/

/**
 * calculate the force for all particles
 */
void calculateF();

/**
 * calculate the position for all particles
 */
void calculateX();

/**
 * calculate the position for all particles
 */
void calculateV();

int checkForceInput();

/**
 * plot the particles to a xyz-file
 */
void plotParticles(int iteration);

constexpr double start_time = 0;
double end_time = 1000;
double delta_t = 0.014;


ParticleContainer particles;


int main(int argc, char *argsv[]) {

    std::cout << "Hello from MolSim for PSE!" << std::endl;
    if (argc != 2) {
        std::cout << "Erroneous programme call! " << std::endl;
        std::cout << "./molsym filename" << std::endl;
    }

    //input t_end and delta_t
    std::cout << "Please enter the endtime:\n";
    std::cin >> end_time;
    std::cout << "Please enter the default time:\n";
    std::cin >> delta_t;

    //unique pointer to the input method
    std::unique_ptr <inputReader::FileReader> fileReader = std::make_unique<inputReader::TxtReader>();
    fileReader->readFile(particles, argsv[1]);

    //unique pointer to the force calculation method
    std::unique_ptr <Force> force = std::make_unique<LennardJones>();

    double current_time = start_time;

    int iteration = 0;

// for this loop, we assume: current x, current f and current v are known
    while (current_time < end_time) {
// calculate new x
        calculateX();

// calculate new f
        force->calculateF(particles);

// calculate new v
        calculateV();

        iteration++;
        if (iteration % 10 == 0) {
            plotParticles(iteration);
        }
        std::cout << "Iteration " << iteration << " finished." <<
                  std::endl;

        current_time +=
                delta_t;
    }

    std::cout << "output written. Terminating..." <<
              std::endl;
    return 0;
}

//calculate new position
void calculateX() {
    for (auto &p: particles) {
        const std::array<double, 3> &tempV{p.getV()};
        const std::array<double, 3> &tempF{p.getF()};
        const std::array<double, 3> &tempX{p.getX()};

        std::array<double, 3> newX{};

        for (int i = 0; i < 3; i++)
            //Velocity-Störmer-Verlet-Algorithm
            newX[i] = tempX[i] + delta_t * tempV[i] + pow(delta_t, 2) * tempF[i] / (2 * p.getM());

        p.setX(newX);
    }
}

//calculate new velocity
void calculateV() {
    for (auto &p: particles) {
        const std::array<double, 3> &tempV{p.getV()};
        const std::array<double, 3> &tempOldF{p.getOldF()};
        const std::array<double, 3> &tempF{p.getF()};

        std::array<double, 3> newV{};

        for (int i = 0; i < 3; i++) {
            //Velocity-Störmer-Verlet-Algorithm
            newV[i] = tempV[i] + delta_t * (tempOldF[i] + tempF[i]) / (2 * p.getM());
        }

        p.setV(newV);
    }
}


void plotParticles(int iteration) {

    std::string out_name("MD_vtk");

    //unique pointer to the input method
    std::unique_ptr <outputWriter::FileWriter> writer = std::make_unique<outputWriter::VTKWriter>();
    writer->plotParticles(particles, out_name, iteration);
}
