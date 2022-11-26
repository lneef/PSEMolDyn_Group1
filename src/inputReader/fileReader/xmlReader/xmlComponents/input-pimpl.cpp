//
// Created by dominik on 26.11.22.
//

#include "input-pimpl.h"
#include <iostream>

void input_pimpl::
pre ()
{
}

void input_pimpl::
path (const ::std::string& path)
{
    std::cout << "path: " << path << std::endl;
}

void input_pimpl::
post_input ()
{
}