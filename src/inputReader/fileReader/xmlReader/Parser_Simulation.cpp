//
// Created by dominik on 24.11.22.
//

#include "Parser_Simulation.h"

namespace xmlParser {
    Parser_Simulation::Parser_Simulation(const double &t_end, const double &delta_t) : t_end(t_end), delta_t(delta_t) {}
    const double &Parser_Simulation::getdelta_t() const {
        return delta_t;
    }
    const double &Parser_Simulation::gett_end() const {
        return t_end;
    }
}