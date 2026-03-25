#ifndef MOMENTUM_H
#define MOMENTUM_H
// Header guard

#include <string>
#include <vector>

// Create class momentum based on 4 vector with components p^mu = (p0, p1, p2, p3)

class Momentum
{
private:
    std::vector<double>* four_momentum; 
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
// Special functions
    Momentum(const Momentum& RHS_object); // Copy constructor
    Momentum(Momentum&& RHS_object) noexcept; // Move constructor
    Momentum& operator=(const Momentum& RHS_object); // Copy assignment operator
    Momentum& operator=(Momentum&& RHS_object) noexcept ; // Move assignment operator
    ~Momentum(); // Destructor
// Arithmetic operators
    Momentum operator+(const Momentum& RHS_object) const; // Addition operator
    Momentum operator-(const Momentum& RHS_object) const; // Subtraction operator
    double operator*(const Momentum& RHS_object) const; // Dot product operator
    Momentum operator*(double scalar) const; // Scalar multiplier operator
// Utility function
    double invariant_mass(); // Calculate invariant mass operator
    double calculate_beta() const; // Calculate velocity operator
    double calculate_gamma() const; // Calculate Lorentz factor operator
// Display function to display momentum information
    void display_information() const;
};

#endif 
// End header guard