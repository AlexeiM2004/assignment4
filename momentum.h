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
    Momentum(); // Default constructor
    Momentum(double p0_comp, double p1_comp, double p2_comp, double p3_comp); // Parameterised constructor
    ~Momentum(); // Destructor
    

};

#endif 
// End header guard