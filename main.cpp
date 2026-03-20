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

    //---------- Testing Particle and Momentum Classes ----------//
    
    std::cout << "\nCreate particle objects.\n";
    
    // Test creation of valid particle 
    Particle electron1("Electron", 135, 57, 97, 7);
    Particle electron2("Electron", 135, 57, 97, 7);
    Particle muon1("Muon", 133, 9, 60, 67);
    Particle muon2("Muon", 154, -9, 0, -7);
    Particle tau1("Tau", 226, -25, 95, -65);
    Particle tau2("Tau", 325, -32, 52, -1);

    // Test creation of invalid particles
    //Particle ChudParticle("Chud particle", 67, 67, 67, 67); // Valid flag will be triggered as false due to name
    //Particle SecretChudParticle("W", -67, 67, 67, 67); // Valid flag will be trigged as false due to momentum

    // Create particle array and store particles

    std::vector<Particle> particles;
    particles.push_back(electron1);
    particles.push_back(electron2);
    particles.push_back(muon1);
    particles.push_back(muon2);
    particles.push_back(tau1);
    particles.push_back(tau2);
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
    
    //---------- Displaying Particles and Momenta ----------//

    std::cout << "\nParticle List.\n";
    for(const Particle& particle : particles)
    {
        particle.display_information();
        std::cout << "\n";
    }

    std::cout << "\nMomentum List.\n";
    for(const Momentum& momentum : momenta)
    {
        momentum.display_information();
        std::cout << "\n";
    }

    //---------- Particle and Momentum Validation ----------//

    // If an invalid input was flagged in the particle.cpp, program exits gracefully by returning 1
    
    for(const Particle& particle : particles)
    {
        if(particle.is_valid() == false)
        {
            std::cout << "\nExiting program.";
            std::cout << "\nInvalid: " << particle.get_particle_name() << "\n";
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

    //---------- Special Functions ----------//

    // Copy Constructor
    std::cout << "\nCopy constructor demonstration.\n";
    Particle particle_copy(electron1);
    std::cout << "\nOriginal: " << electron1.get_particle_name()
            << ", Energy = " << electron1.get_p0_component() << " MeV\n";
    std::cout << "\nCopied: " << particle_copy.get_particle_name()
            << ", Energy = " << particle_copy.get_p0_component() << " MeV\n";

    // Move Constructor
    std::cout << "\nMove constructor demonstration.\n";
    Particle particle_moved(std::move(muon1));
    std::cout << "\nMoved particle to a new object\n";
    std::cout << "Moved : " << particle_moved.get_particle_name()
            << ", Energy = " << particle_moved.get_p0_component() << " MeV\n";

    // Copy Assignment Operator 
    std::cout << "\nCopy assignment operator demonstration.\n";
    Particle particle_copy_assignment;
    particle_copy_assignment = electron2;
    std::cout << "Copied : " << particle_copy_assignment.get_particle_name()
            << ", Energy = " << particle_copy_assignment.get_p0_component() << " MeV\n";

    // Move Assingment Operator
    std::cout << "\nMove assignment operator demonstration.\n";
    Particle particle_move_assignment;
    particle_move_assignment = std::move(muon2);
    std::cout << "Moved : " << particle_move_assignment.get_particle_name()
            << ", Energy = " << particle_move_assignment.get_p0_component() << " MeV\n";


    //---------- Arithmetic Functions ----------//

    // Gather electron 1, 2 and muon 1, 2 momenta

    Momentum electron1_momentum(
        electron1.get_p0_component(),
        electron1.get_p1_component(),
        electron1.get_p2_component(),
        electron1.get_p3_component());

    Momentum electron2_momentum(
        electron2.get_p0_component(),
        electron2.get_p1_component(),
        electron2.get_p2_component(),
        electron2.get_p3_component());
                                
    Momentum muon1_momentum(
        muon1.get_p0_component(),
        muon1.get_p1_component(),
        muon1.get_p2_component(),
        muon1.get_p3_component());
    
    Momentum muon2_momentum(
        muon2.get_p0_component(),
        muon2.get_p1_component(),
        muon2.get_p2_component(),
        muon2.get_p3_component());

    
    // Sum the four momenta of electron 1 and electron 2

    Momentum four_momentum_addition = electron1_momentum + electron2_momentum;
    std::cout << "\nFour momentum sum of electron 1 and electron 2; " <<
        "\np0 = " << four_momentum_addition.get_p0_component() << " MeV, " <<
        "\np1 = " << four_momentum_addition.get_p1_component() << " MeV/c, " <<
        "\np2 = " << four_momentum_addition.get_p2_component() << " MeV/c, " <<
        "\np3 = " << four_momentum_addition.get_p3_component() << " MeV/c.\n";

    // Subtract the four momenta of electron 2 from electron 1

    Momentum four_momentum_subtraction = electron1_momentum - electron2_momentum;
    std::cout << "\nFour momentum subtraction of electron 2 from electron 1; " <<
        "\np0 = " << four_momentum_subtraction.get_p0_component() << " MeV, " <<
        "\np1 = " << four_momentum_subtraction.get_p1_component() << " MeV/c, " <<
        "\np2 = " << four_momentum_subtraction.get_p2_component() << " MeV/c, " <<
        "\np3 = " << four_momentum_subtraction.get_p3_component() << " MeV/c.\n";

    // Multiply the four momenta of electron 1 by a scalar multiple

    Momentum four_momentum_scalar_multiplication = electron1_momentum * 2.0;
    std::cout << "\nFour momentum scalar multiplication of electron 1 by 2; " <<
        "\np0 = " << four_momentum_scalar_multiplication.get_p0_component() << " MeV, " <<
        "\np1 = " << four_momentum_scalar_multiplication.get_p1_component() << " MeV/c, " <<
        "\np2 = " << four_momentum_scalar_multiplication.get_p2_component() << " MeV/c, " <<
        "\np3 = " << four_momentum_scalar_multiplication.get_p3_component() << " MeV/c.\n";

    // Dot product of muon 1 with muon 2

    double dot_product = muon1_momentum * muon2_momentum;
    std::cout << "\nFour momentum of muon 1 inner product with muon 2 " << dot_product << "  MeV²\n";

    //---------- Utility Functions ----------//

    // Calculate invariant mass of electron 1

    std::cout << "\nInvariant mass of electron 1; " << electron1_momentum.invariant_mass() << " MeV/c²\n";

    // Calculate beta of electron 1

    std::cout << "\nBeta 'β' (v/c) of electron 1; " << electron1_momentum.calculate_beta() << " c\n";

    // Calculate the Lorentz factor of electron 1

    std::cout << "\nLorentz factor 'γ'of electron 1; " << electron1_momentum.calculate_gamma() << "\n";


    return 0;
}