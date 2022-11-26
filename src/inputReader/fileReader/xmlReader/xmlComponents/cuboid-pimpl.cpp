//
// Created by dominik on 26.11.22.
//

#include "cuboid-pimpl.h"
#include <iostream>

void cuboid_pimpl::
pre ()
{
}

void cuboid_pimpl::
x (double x)
{
    std::cout << "x: " << x << std::endl;
}

void cuboid_pimpl::
n (int n)
{
    std::cout << "n: " << n << std::endl;
}

void cuboid_pimpl::
h (double h)
{
    std::cout << "h: " << h << std::endl;
}

void cuboid_pimpl::
m (double m)
{
    std::cout << "m: " << m << std::endl;
}

void cuboid_pimpl::
v (double v)
{
    std::cout << "v: " << v << std::endl;
}

void cuboid_pimpl::
post_cuboid ()
{
}