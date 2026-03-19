#include "momentum.h"
#include <iostream>

// Default constructor

Momentum::Momentum() : valid_flag(true) 
{
    four_momentum = new std::vector<double>;
    four_momentum->push_back(0); // p0 (E) component
    four_momentum->push_back(0); // p1 (px) component
    four_momentum->push_back(0); // p2 (py) component
    four_momentum->push_back(0); // p3 (pz) component
}

// Parameterised constructor

Momentum::Momentum(double p0_comp, double p1_comp, double p2_comp, double p3_comp) : valid_flag(true)
{
    four_momentum = new std::vector<double>;
    four_momentum->push_back(0); // p0 (E) component
    four_momentum->push_back(0); // p1 (px) component
    four_momentum->push_back(0); // p2 (py) component
    four_momentum->push_back(0); // p3 (pz) component

    set_p0_component(p0_comp);
    set_p1_component(p1_comp);
    set_p2_component(p2_comp);
    set_p3_component(p3_comp);
}

// Getters

double Momentum::get_p0_component() const {return (*four_momentum)[0];}
double Momentum::get_p1_component() const{return (*four_momentum)[1];}
double Momentum::get_p2_component() const{return (*four_momentum)[2];}
double Momentum::get_p3_component() const{return (*four_momentum)[3];}

// Setters 

// p0 component setter must be validated such that p0 is non-negative

void Momentum::set_p0_component(double p0_comp)
{
    if(p0_comp >= 0)
    {
        (*four_momentum)[0] = p0_comp;
        valid_flag = true;
    }else{
        std::cout << "\nPlease enter a valid p0 component value, such that p0 >= 0.\n";
        valid_flag = false;
    }
}

// p1, p2, p3 setters can take positive and negative values

void Momentum::set_p1_component(double p1_comp)
{
    (*four_momentum)[1] = p1_comp;
}

void Momentum::set_p2_component(double p2_comp)
{
    (*four_momentum)[2] = p2_comp;
}

void Momentum::set_p3_component(double p3_comp)
{
    (*four_momentum)[3] = p3_comp;
}

// Copy constructor

Momentum::Momentum(const Momentum& RHS_object) : valid_flag(true)
{
    four_momentum = new std::vector<double>(*(RHS_object.four_momentum));
    std::cout << "\nCall Momentum Copy Constructor.\n";
}

// Move constructor

Momentum::Momentum(Momentum&& RHS_object) noexcept :
    valid_flag(true),
    four_momentum(RHS_object.four_momentum)
{
    std::cout << "\nCall Momentum Move Constructor.\n";

    // Reset RHS_object vector to a valid empty state using nullptr
    RHS_object.four_momentum = nullptr;
} 

// Copy assignment operator

Momentum& Momentum::operator=(const Momentum& RHS_object)
{
    std::cout << "\nCall Momentum Copy Assignment.\n";

    // Self assignment check
    if(this != &RHS_object)
    {
        // Delete existing momentum vector to prevent memory leak
        delete four_momentum;

        four_momentum = new std::vector<double>(*(RHS_object.four_momentum));
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
        // Delete existing momentum vector to prevent memory leak
        delete four_momentum;

        // Steal RHS's values
        four_momentum = RHS_object.four_momentum;
        valid_flag = true;

        // Reset RHS's values to a valid empty state
        RHS_object.four_momentum = nullptr;
    }
    return *this;
} 

Momentum::~Momentum() 
{
    std::cout << "\nCall Momentum Destructor.\n";
    delete four_momentum;
} 

void Momentum::display_information() const
{

}