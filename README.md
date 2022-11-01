MolSim
===

# Group 1 #
Members:
* Lukas Neef
* Dominik Rammelsberger

# Code #
* Link: https://gitlab.lrz.de/molsim1/psemoldyn_group1
* Branch: main
* Revision: 

# Run Instructions #
* Compiler: GNU 12.2.0
* cmake .
* make

# Doxygen #
* Per default cmake . creates a target for generating a doxygen documentation
* you can disable this behaviour by passing DISABLE_DOXYGEN=ON
* to create the doxygen documentation run make doc\_doxygen

# Misc #
* calculation of F is implemented in Gravitation.cpp
* ParticleContainer provides an iterator for simple iteration
