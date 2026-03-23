#include "particle.h"
#include "momentum.h"
#include <iostream>
#include <algorithm>

// Default constructor

Particle::Particle() : particle_name("Unspecified"), particle_type("Unspecified"), momentum(nullptr), valid_flag(true) {}


// Parameterised constructor

Particle::Particle(std::string part_name, double p0_comp, double p1_comp, double p2_comp, double p3_comp) : valid_flag(true)
{
    set_particle_name(part_name);
    momentum = new Momentum(p0_comp, p1_comp, p2_comp, p3_comp);
}

// Getters

std::string Particle::get_particle_name() const{return particle_name;}
double Particle::get_p0_component() const {return momentum->get_p0_component();}
double Particle::get_p1_component() const{return momentum->get_p1_component();}
double Particle::get_p2_component() const{return momentum->get_p2_component();}
double Particle::get_p3_component() const{return momentum->get_p3_component();}

// Setters 

void Particle::set_particle_name(std::string part_name)
{
    // A static vector containing all valid particle types. 
    static std::vector<std::string> valid_particle_list = {"Electron","Muon","Tau"};
    // Checks the type against the static vector
    if(std::find(valid_particle_list.begin(), valid_particle_list.end(), part_name) != valid_particle_list.end())
    {
        particle_name = part_name;
        particle_type = "Lepton";
    }else{
        std::cout << "\nInvalid particle name input, please use a valid particle name.\n";
        std::cout << "\nValid input names are;\n";
        for(const auto& particle : valid_particle_list)
        {
            std::cout << particle << "\n";
        }
        std::cout << "\nNote that, input is case sensitive.\n";
        particle_name = part_name;
        valid_flag = false;
    }
}


// Call momentum's setter in the particle class

void Particle::set_p0_component(double p0_comp)
{
    momentum -> set_p0_component(p0_comp);
}

void Particle::set_p1_component(double p1_comp)
{
    momentum -> set_p1_component(p1_comp);
}

void Particle::set_p2_component(double p2_comp)
{
    momentum -> set_p2_component(p2_comp);
}

void Particle::set_p3_component(double p3_comp)
{
    momentum -> set_p3_component(p3_comp);
}

// Copy constructor

Particle::Particle(const Particle& RHS_object) :
    particle_name(RHS_object.particle_name),
    particle_type(RHS_object.particle_type),
    momentum(nullptr),
    valid_flag(true)    // Reset valid flag to true, as a new object is created
{
    std::cout << "\nCall Particle Copy Constructor.";

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

// Destructor

Particle::~Particle() 
{
    std::cout << "\nCall Particle Destructor.\n";
    delete momentum;
} 

void Particle::display_information() const
{
    std::cout << "\nParticle Information;";
    std::cout << "\nParticle name - " << particle_name << ",";
    std::cout << "\nParticle type - " << particle_type << ",";
    std::cout << "\nParticle energy - " << get_p0_component() << " MeV,";
    std::cout << "\nParticle x momentum - " << get_p1_component() << " MeV/c,";
    std::cout << "\nParticle y momentum - " << get_p2_component() << " MeV/c";
    std::cout << "\nParticle z momentum - " << get_p3_component() << " MeV/c.";
}