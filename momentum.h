#ifndef MOMENTUM_H
#define MOMENTUM_H
// Header guard

#include <string>

// Create class momentum based on 4 vector with components p^mu = (p0, p1, p2, p3)

class Momentum
{
private:
    double p0_component;
    double p1_component;
    double p2_component;
    double p3_component;
    bool valid_flag;
public:
// Default constructor
    Momentum();
// Parameterised constructor
    Momentum(double p0_comp, double p1_comp, double p2_comp, double p3_comp);
// Getters for each member
    double get_p0_component() const;
    double get_p1_component() const;
    double get_p2_component() const;
    double get_p3_component() const;
    bool is_valid() const {return valid_flag;}
// Setters for each member
    void set_p0_component(double p0_comp);
    void set_p1_component(double p1_comp);
    void set_p2_component(double p2_comp);
    void set_p3_component(double p3_comp);
// Display function to display momentum information
    void display_information() const;
// Special functions
    Momentum(const Momentum& RHS_object); // Copy constructor
    Momentum(Momentum&& RHS_object); // Move constructor
    Momentum& operator=(const Momentum& RHS_object); // Copy assignment operator
    Momentum& operator=(Momentum&& RHS_object); // Move assignment operator
    ~Momentum(); // Destructor

};

#endif 
// End header guard