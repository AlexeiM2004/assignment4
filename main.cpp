// Assignment 4 - Particles and 4 Momenta Manipulation.
// Practices overloading special functions and operators in classes.
// Alexei Maiorov, Student ID: [11022726]
// Date: [18/03/2026]

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "momentum.h"
#include "particle.h"

int main()
{

    // If an invalid input was flagged in the momentum.cpp, the program exits gracefully by returning 1
    for(const Momentum& momentum: momenta)
    {
        if(momentum.is_valid() == false)
        {
            std::cout << "\nExiting program.";
            return 1;
        }
    }

    // If an invalid input was flagged in the source.cpp, the program exits gracefully by returning 1
    for(const Particle& particle : particles)
    {
        if(particle.is_valid() == false)
        {
            std::cout << "\nExiting program.";
            return 1;
        }
    }

    return 0;
}