//
// Created by dominik on 26.11.22.
//

#include "output-pimpl.h"
#include <iostream>

void output_pimpl::
pre ()
{
}

void output_pimpl::
name (const ::std::string& name)
{
    std::cout << "name: " << name << std::endl;
}

void output_pimpl::
frequency (double frequency)
{
    std::cout << "frequency: " << frequency << std::endl;
}

void output_pimpl::
post_output ()
{
}