#ifndef PARTICLE_H
#define PARTICLE_H
// Header guard

#include <string>
#include "momentum.h"

class Particle
{
private:
    std::string particle_name;
    std::string particle_type;
    Momentum* momentum; 
public:
    Particle(); // Default constructor
    Particle(std::string part_name, std::string part_type, double part_momentum); // Parameterised constructor
    ~Particle(); // Destructor
};

#endif 
// End header guard
