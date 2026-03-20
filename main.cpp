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
    std::cout << "\nCreate particle objects.\n";
    
    // Test creation of valid particle 
    Particle Electron1("Electron", 35, 57, 97, 7);
    Particle Electron2("Electron", 35, 57, 97, 7);
    Particle Muon1("Muon", 33, 9, 60, 67);
    Particle Muon2("Muon", 54, -9, 0, -7);
    Particle Muon3("Muon", 94, 3, -12, 67);
    Particle Muon4("Muon", 23, 18, 60, 15);
    Particle Tau1("Tau", 6, -25, 95, -65);
    Particle Tau2("Tau", 25, -32, 52, -1);
    Particle Photon("Photon", 22, 40, 81, 10);

    // Test creation of invalid particles
    //Particle ChudParticle("Chud particle", 67, 67, 67, 67); // Valid flag will be triggered as false due to name
    //Particle SecretChudParticle("W", -67, 67, 67, 67); // Valid flag will be trigged as false due to momentum

    // Create particle array and store particles

    std::vector<Particle> particles;
    particles.push_back(Electron1);
    particles.push_back(Electron2);
    particles.push_back(Muon1);
    particles.push_back(Muon2);
    particles.push_back(Muon3);
    particles.push_back(Muon4);
    particles.push_back(Tau1);
    particles.push_back(Tau2);
    particles.push_back(Photon);
    //particles.push_back(ChudParticle);
    //particles.push_back(SecretChudParticle);

    std::cout << "\nCreate momentum objects.\n";
    
    // Test creation of a valid momentum and an invalid momentum
    Momentum ChadMomentum(67, 67, 67, 67);
    //Momentum ChudMomentum(-67, 67, 67, 67);

    // Create momentum array to store momenta

    std::vector<Momentum> momenta;
    momenta.push_back(ChadMomentum);
    //momenta.push_back(ChudMomentum); 
    

    // If an invalid input was flagged in the particle.cpp, program exits gracefully by returning 1
    
    for(const Particle& particle : particles)
    {
        if(particle.is_valid() == false)
        {
            std::cout << "\nExiting program.";
            return 1;
        }
    }
    
    // If an invalid input was flagged in the momentum.cpp, program exits gracefully by returning 1

    for(const Momentum& momentum : momenta)
    {
        if(momentum.is_valid() == false)
        {
            std::cout << "\nExiting program.";
            return 1;
        }
    }

    return 0;
}