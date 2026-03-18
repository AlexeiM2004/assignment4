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
    bool valid_flag;
public:
// Default constructor
    Particle(); 
// Parameterised constructor   
    Particle(std::string part_name, std::string part_type, double p0_comp, double p1_comp, double p2_comp, double p3_comp);
// Getters for each member
    std::string get_particle_name() const;
    std::string get_particle_type() const;
    double get_p0_component() const;
    double get_p1_component() const;
    double get_p2_component() const;
    double get_p3_component() const;
    bool is_valid() const {return valid_flag;}
// Setters for each member
    void set_particle_name(std::string part_name);
    void set_particle_type(std::string part_type);
    void set_p0_component(double p0_comp);
    void set_p1_component(double p1_comp);
    void set_p2_component(double p2_comp);
    void set_p3_component(double p3_comp);
// Display function to display particle information
    void display_information() const;
// Special functions
    Particle(const Particle& RHS_object); // Copy constructor
    Particle(Particle&& RHS_object); // Move constructor
    Particle& operator=(const Particle& RHS_object); // Copy assignment operator
    Particle& operator=(Particle&& RHS_object); // Move assignment operator
    ~Particle(); // Destructor

};

#endif 
// End header guard
