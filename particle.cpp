#include "particle.h"
#include "momentum.h"
#include <iostream>

// Default constructor

Particle::Particle() : particle_name("Unspecified"), particle_type("Unspecified"), momentum(nullptr), valid_flag(true) {}


// Parameterised constructor

Particle::Particle(std::string part_name, std::string part_type, double p0_comp, double p1_comp, double p2_comp, double p3_comp) : valid_flag(true)
{
    set_particle_name(part_name);
    set_particle_type(part_type);
    momentum = new Momentum(p0_comp, p1_comp, p2_comp, p3_comp);
}

// Getters

std::string Particle::get_particle_name() const{return particle_name;}
std::string Particle::get_particle_type() const{return particle_type;}
double Particle::get_p0_component() const {return momentum->get_p0_component();}
double Particle::get_p1_component() const{return momentum->get_p1_component();}
double Particle::get_p2_component() const{return momentum->get_p2_component();}
double Particle::get_p3_component() const{return momentum->get_p3_component();}

// Setters 

void Particle::set_particle_name(std::string part_name)
{

}

void Particle::set_particle_type(std::string part_type)
{

}

// Call momentum's setter in the particle class

void Particle::set_p0_component(double p0_comp)
{
    momentum -> set_p0_component(p0_comp);
}

void Particle::set_p1_component(double p1_comp)
{
    momentum -> set_p1_component(p1_comp);}

void Particle::set_p2_component(double p2_comp)
{
    momentum -> set_p2_component(p2_comp);}

void Particle::set_p3_component(double p3_comp)
{
    momentum -> set_p3_component(p3_comp);}

void Particle::display_information() const
{
 
}

// Copy constructor

Particle::Particle(const Particle& RHS_object) :
    particle_name(RHS_object.particle_name),
    particle_type(RHS_object.particle_type),
    momentum(nullptr),
    valid_flag(true)    // Reset valid flag to true, as a new object is created
{
    std::cout << "\nCall Particle Copy Constructor.\n";

    // Create a deep copy of new momentum object, by allocating new memory on the heap
    if(RHS_object.momentum != nullptr)
    {
        momentum = new Momentum(*(RHS_object.momentum));
    }
}

// Move constructor

Particle::Particle(Particle&& RHS_object) noexcept :
    particle_name(std::move(RHS_object.particle_name)),
    particle_type(std::move(RHS_object.particle_type)),
    momentum(RHS_object.momentum),
    valid_flag(true)
{
    std::cout << "\nCall Particle Move Constructor.\n";

    // Reset RHS_object values to a valid empty state
    RHS_object.particle_name = "";
    RHS_object.particle_type = "";
    RHS_object.momentum = nullptr;
    
} 

// Copy assignment operator

Particle& Particle::operator=(const Particle& RHS_object)
{
    std::cout << "\nCall Particle Copy Assignment.\n";

    // Self assignment check
    if(this != &RHS_object)
    {
        particle_name = RHS_object.particle_name;
        particle_type = RHS_object.particle_type;
        valid_flag = true;
        delete momentum; // Delete old momentum to prevent memory leak  
        // Create a deep copy of new momentum object, by allocating new memory on the heap
        if(RHS_object.momentum != nullptr)
        {
            momentum = new Momentum(*(RHS_object.momentum));
        }
    }
    // Returns the reference to allow for chaining,
    return *this;
}

// Move assignment operator

Particle& Particle::operator=(Particle&& RHS_object) noexcept
{
    std::cout << "\nCall Particle Move Assignment.\n";

    // Self assignment check
    if(this != &RHS_object)
    {
        /// Delete old momentum to prevent memory leak
        delete momentum;
        // Steal RHS's values
        particle_name = std::move(RHS_object.particle_name);
        particle_type = std::move(RHS_object.particle_type);
        momentum = RHS_object.momentum;
        valid_flag = true;

        // Reset RHS's values to a valid empty state
        RHS_object.particle_name = "";
        RHS_object.particle_type = "";
        RHS_object.momentum = nullptr;
    }
    return *this;
} 

Particle::~Particle() 
{
    std::cout << "\nCall Particle Destructor.\n";
} 

void Particle::display_information() const
{
    
}