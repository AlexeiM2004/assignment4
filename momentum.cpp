#include "momentum.h"
#include <iostream>

// Default constructor

Momentum::Momentum() : p0_component(0), p1_component(0), p2_component(0), p3_component(0), valid_flag(true) {}

// Parameterised constructor

Momentum::Momentum(double p0_comp, double p1_comp, double p2_comp, double p3_comp) : valid_flag(true)
{
    set_p0_component(p0_comp);
    set_p1_component(p1_comp);
    set_p2_component(p2_comp);
    set_p3_component(p3_comp);
}

// Getters

double Momentum::get_p0_component() const {return p0_component;}
double Momentum::get_p1_component() const{return p1_component;}
double Momentum::get_p2_component() const{return p2_component;}
double Momentum::get_p3_component() const{return p3_component;}

// Setters 

// p0 component setter must be validated such that p0 is non-negative

void Momentum::set_p0_component(double p0_comp)
{
    if(p0_comp >= 0)
    {
        p0_component = p0_comp;
        valid_flag = true;
    }else{
        std::cout << "\nPlease enter a valid p0 component value, such that p0 >= 0.\n";
        valid_flag = false;
    }
}

// p1, p2, p3 setters can take positive and negative values

void Momentum::set_p1_component(double p1_comp)
{
    p1_component = p1_comp;
}

void Momentum::set_p2_component(double p2_comp)
{
    p2_component = p2_comp;
}

void Momentum::set_p3_component(double p3_comp)
{
    p3_component = p3_comp;
}

// Copy constructor

Momentum::Momentum(const Momentum& RHS_object) :
    p0_component(RHS_object.p0_component),
    p1_component(RHS_object.p1_component),
    p2_component(RHS_object.p2_component),
    p3_component(RHS_object.p3_component),
    valid_flag(true)    // Reset valid flag to true, as a new object is created
{
    std::cout << "\nCall Momentum Copy Constructor.\n";
}

// Move constructor

Momentum::Momentum(Momentum&& RHS_object) noexcept :
    p0_component(RHS_object.p0_component),
    p1_component(RHS_object.p1_component),
    p2_component(RHS_object.p2_component),
    p3_component(RHS_object.p3_component),
    valid_flag(true)
{
    std::cout << "\nCall Momentum Move Constructor.\n";

    // Reset RHS_object values to a valid empty state
    RHS_object.p0_component = 0;
    RHS_object.p1_component = 0;
    RHS_object.p2_component = 0;
    RHS_object.p3_component = 0;
} 

// Copy assignment operator

Momentum& Momentum::operator=(const Momentum& RHS_object)
{
    std::cout << "\nCall Momentum Copy Assignment.\n";

    // Self assignment check
    if(this != &RHS_object)
    {
        p0_component = RHS_object.p0_component;
        p1_component = RHS_object.p1_component;
        p2_component = RHS_object.p2_component;
        p3_component = RHS_object.p3_component;
        valid_flag = true;
    }
    // Returns the reference to allow for chaining,
    return *this;
}

// Move assignment operator

Momentum& Momentum::operator=(Momentum&& RHS_object) noexcept
{
    std::cout << "\nCall Momentum Move Assignment.\n";

    // Self assignment check
    if(this != &RHS_object)
    {
        // Steal RHS's values
        p0_component = RHS_object.p0_component;
        p1_component = RHS_object.p1_component;
        p2_component = RHS_object.p2_component;
        p3_component = RHS_object.p3_component;  
        valid_flag = true;

        // Reset RHS's values to a valid empty state
        RHS_object.p0_component = 0;
        RHS_object.p1_component = 0;
        RHS_object.p2_component = 0;
        RHS_object.p3_component = 0;
    }
    return *this;
} 

Momentum::~Momentum() 
{
    std::cout << "\nCall Momentum Destructor.\n";
} 

void Momentum::display_information() const
{

}