//
// Created by dominik on 26.11.22.
//

#include "simulation-pimpl.h"
#include <iostream>

void simulation_pimpl::
pre ()
{
}

void simulation_pimpl::
t_end (double t_end)
{
    std::cout << "t_end: " << t_end << std::endl;
}

void simulation_pimpl::
delta_t (double delta_t)
{
    std::cout << "delta_t: " << delta_t << std::endl;
}

void simulation_pimpl::
post_simulation ()
{
}