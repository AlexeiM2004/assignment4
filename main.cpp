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

    // Test creation of valid particle 

    std::cout << "\nCreate valid particles.\n";

    Particle Electron("Electron", 35, 57, 97, 7);
    Particle Muon("Muon", 33, 9, 60, 67);
    Particle Taon("Taon", 6, 25, 95, 65);
    Particle Photon("Photon", 22, 40, 81, 10);

    // Test creation of invalid particles

    std::cout << "\nCreate a particle with an invalid name.\n";

    Particle Chud("Chud particle", 67, 67, 67, 67); // Valid flag will be triggered as false

    std::cout << "\nCreate a particle with an invalid 4 momenta.\n";

    Particle SecretChud("W", -67, 67, 67, 67); // Valid flag will be trigged as false.

    // Create particle array and store particles

    std::vector<Particle> particles;

    particles.push_back(Electron);
    particles.push_back(Muon);
    particles.push_back(Taon);
    particles.push_back(Photon);
    particles.push_back(Chud);
    particles.push_back(SecretChud);

    // If an invalid input was flagged in the particle.cpp, program exits gracefully by returning 1
    
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