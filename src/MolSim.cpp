
#include "FileReader.h"
#include "outputWriter/XYZWriter.h"
#include "utils/ArrayUtils.h"

#include <iostream>
#include <list>

#include "SimpleForceCalc.h"

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

/**
 * plot the particles to a xyz-file
 */
void plotParticles(int iteration);

constexpr double start_time = 0;
double end_time = 1000;
double delta_t = 0.014;

// TODO: what data structure to pick?
std::list<Particle> particles;

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

    FileReader fileReader;
    fileReader.readFile(particles, argsv[1]);

    double current_time = start_time;

    int iteration = 0;

    SimpleForceCalc forceCalc;

    // for this loop, we assume: current x, current f and current v are known
    while (current_time < end_time) {
        // calculate new x
        calculateX();
        // calculate new f
//        calculateF();
        forceCalc.calculateF(particles);
        // calculate new v
        calculateV();

        iteration++;
        if (iteration % 10 == 0) {
            plotParticles(iteration);
        }
        std::cout << "Iteration " << iteration << " finished." << std::endl;

        current_time += delta_t;
    }

    std::cout << "output written. Terminating..." << std::endl;
    return 0;
}

/*double calculateNorm(std::array<double, 3> x) {
    double norm = sqrt(pow(x[0], 2) + pow(x[1], 2) + pow(x[2], 2));
    return norm;
}*/

/*void calculateF() {
    std::list<Particle>::iterator iterator;
    iterator = particles.begin();

    for (auto &p1: particles) {
        std::array<double, 3> newF{};
        for (auto &p2: particles) {
            // @TODO: insert calculation of forces here!
            if (p1 == p2) {
                continue;
            }
            std::array<double, 3> xij;
            for (int i = 0; i < 3; i++) {
                xij[i] = p1.getX()[i] - p2.getX()[i];
            }
            double norm = calculateNorm(xij);

            std::array<double, 3> xji;
            for (int i = 0; i < 3; i++) {
                xji[i] = p2.getX()[i] - p1.getX()[i];
                newF[i] += (p1.getM() * p2.getM() * (xji[i])) / pow(norm, 3);
            }
        }
		p1.setF(newF);
    }
}*/

void calculateX() {
    for (auto &p: particles) {
        // @TODO: insert calculation of position updates here!
        const std::array<double, 3> &tempV{p.getV()};
        const std::array<double, 3> &tempOldF{p.getOldF()};
        const std::array<double, 3> &tempX{p.getX()};

        std::array<double, 3> newX{};

        for (int i = 0; i < 3; i++)
            newX[i] = tempX[i] + delta_t * tempV[i] + pow(delta_t, 2) * tempOldF[i] / (2 * p.getM());

        p.setX(newX);
    }
}

void calculateV() {
    for (auto &p: particles) {
        // @TODO: insert calculation of veclocity updates here!
        const std::array<double, 3> &tempV{p.getV()};
        const std::array<double, 3> &tempOldF{p.getOldF()};
        const std::array<double, 3> &tempF{p.getF()};

        std::array<double, 3> newV{};

        for (int i = 0; i < 3; i++) {
            newV[i] = tempV[i] + delta_t * (tempOldF[i] + tempF[i]) / (2 * p.getM());
        }

        p.setV(newV);
    }
}


void plotParticles(int iteration) {

    std::string out_name("MD_vtk");

    outputWriter::XYZWriter writer;
    writer.plotParticles(particles, out_name, iteration);
}