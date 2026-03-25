# Assignment 4 - Practicing Classes, Special Functions, Memory Management and Function Overloading.

## Program Brief

This program builds on the object-oriented programming concepts used in assignment 3's program by introducing proper memory management, special functions (Rule of 0/3/5), and operator overloading. The program;
- Creates Particle objects, with associated name, type and four momenta.
- Creates Momentum objects, with four momenta components [p0,p1,p2,p3].
- Implements dynamic memory allocation for four-momenta using heap-allocated vectors to practice manual memory management.
- Demonstrates special function usage such as, copy and move constructors and assignment operators and destructor. Allowing for deep copying and resource stealing. Correctly states every time a special function is used.
- Overloads functions for arithmetic operations such as; vector addition, subtraction, dot product and scalar multiplication.
- Uses utility functions for relativistic calculations such as; invariant mass, relativistic velocity and Lorentz factor.
- Validates particle names against the Standard Model (electron, muon ,tau )and associates the valid type (lepton).
- Displays particle information and four-momenta.

## Compilation code

For Windows;
- ```g++ main.cpp particle.cpp momentum.cpp -o assignment-4.exe -std=gnu++17 -Wall```   
- Then run ```assignment-4.exe```

For Mac/Linux;
- ```g++-11 main.cpp particle.cpp momentum.cpp -o assignment-4.o -std=gnu++17 -Wall```  
- Then run ```assignment-4.o```

## UML Class Diagram

<img width="481" height="330" alt="UML_Class_Diagram drawio" src="https://github.com/user-attachments/assets/467b4b96-0fa9-40c8-8228-38f3c1e57cd4" />

The filled diamond arrow indicates "Composition"

## Program Structure

This program is split into 5 files,  

Main.cpp;
- Entry point of program.  
- Creates Particle objects (electron, muon, tau) with four-momenta
  - Valid cases are demonstrated, invalid cases are ```// commented``` (uncomment to test validation) 
- Creates Momentum objects (p0,p1,p2,p3)
  - Valid cases are demonstrated, invalid cases are also ```// commented``` (uncomment to test validation)
- Tests special functions (copy constructor, move constructor, copy assignment operator, move assignment operator)
- Test operator overloading.
- Display results of all operations.

Momentum.h; 
- Defines Momentum class, with private members; ```std::vector<double>* four_momentum``` and ```bool valid_flag```.
- Declares public methods; default constructor, parameterised constructor, getters and setters (for each member respectively).
- Declares the special functions; copy constructor, move constructor copy assignment operator and destructor.
- Declares arithmetic operators; addition ```+```, subtraction ```-```, dot product and scalar multiplication ```*```.
- Declares utility functions; invariant_mass, calculate_beta and calculate_gamma.
- Declares display function.

Momentum.cpp;
- Implements a valid default constructor. 
- Implements parameterised constructor with validation (p0 > 0). 
- Implements getters for all four-momentum components.
- Implements setters and validates each member of the momentum class.
- Implements Rule of 5 functions with print statements.
  - Call Move constructor.
  - Call Copy constructor.
  - Call Move assignment operator.
  - Call Copy assignment operator.
  - Call Destructor.  
- Implements operator overloading functions.
- Implements display function.

Particle.h;
- Defines particle class with private members, ```std::string particle_name```, ```std::string particle_type```, ```Momentum* momentum``` and ```bool valid_flag```.
- Uses pointer to the dynamically allocated Momentum object.
- Declares public methods; default constructor, parameterised constructor, getters and setters (for each member respectively).
- Declares the special functions; copy constructor, move constructor, copy assignment operator, move assignment operator and destructor.
- Declares display function.


Particle.cpp;
- Implements a valid default constructor. 
- Implements parameterised constructor with validation. 
- Implements getters for all private members (delegates getters to the Momentum class).
- Implements setters with validation for particle name (electron, muon, tau) (delegates setters to the Momentum class).
- Implements Rule of 5 functions with print statements.
  - Call Move constructor.
  - Call Copy constructor.
  - Call Move assignment operator.
  - Call Copy assignment operator.
  - Call Destructor.  
- Implements display function.

## Development Process

This code was developed in 6 phases,  

Phase 1 – Class Skeletons and Dynamic Memory Management; 

- Created class skeletons for the Momentum and Particle Classes with header guards
- Implemented their respective private members
  - With Momentum containing ```std::vector<double>*``` for heap allocation.
  - With Particle containing ```Momentum*``` pointer member.
- Implemented valid default and parameterised constructors.
- Implemented getters and setters, with validation (p0>0)
- Set up a destructor to free heap memory and practice dynamic memory management (this was later placed in the special functions section)

Phase 2 – Rule of 5 Implementation for Momentum Class; 

- Implemented copy constructor with deep copying, (new vector created with same values)
- Implemented move constructor with pointer stealing and nullptr resetting.
- Implemented copy assignment operator with self-assignment checking and deep copying.
- Implemented move assignment operator with pointer stealing and nullptr resetting.
- Added print statements to all special functions (including destructor) for debugging.

Phase 3 – Particle Class with Momentum Composition; 

- Implemented parameterised constructor with dynamic allocation using Momentum.
- Implemented getters and setters that delegate straight to Momentum class using ```->```.
- Implemented particle name validation against the Standard Model (electron, muon ,tau) which then associates the particle type as Lepton

Phase 4 – Rule of 5 Implementation for Particle Class; 

- Implemented copy constructor with deep copying, (creates a new Momentum object)
- Accounted for additional complexity of managing a pointer to the dynamically allocated Momentum object.
- Implemented move constructor with pointer stealing and nullptr resetting.
- Implemented copy assignment operator with self-assignment checking and deep copying.
- Implemented move assignment operator with pointer stealing and nullptr resetting.
- Added print statements to all special functions (including destructor) for debugging.

Phase 5 – Operator Overloading and Utility Functions; 

- Implemented arithmetic operators for Momentum class using four-vector mechanics;
  - Addition ```+```
  - Subtraction ```-```
  - Scalar Multiplication ```*```
  - Dot product using the Minkowski Metric (+, -, -, -) i.e. ```a0*b0 - a1*b1 - a2*b2 - a3*b3```.
- Implemented utility functions for Momentum class using relativistic four vector mechanics;
  - Invariant mass, ```M = sqrt(a dot a)```.
  - Beta ( Relativistic Velocity ), ```Beta = |p| / E```.
  - Gamma ( Lorentz Factor ), ```Gamma = 1/sqrt(1-Beta^2)```.

Phase 6 - Testing and Refining;

- Created comprehensive tests in main()
  - Particle creation with valid and invalid particles (invalids are commented), error messages are generated flagging the specific invalid particle.
  - Momentum creation with valid and invalid momenta (invalids are also commented)
  - Copy/move operation demonstrated with print statements.
  - Operator overloading demonstrated with print statements.
  - Display of all results.
  - Verified no memory leaks.
  - Verified no further issues after using ```-Wall```.

## User Guide

To implement a new particle;

-  Use the format ```name("Electron/Muon/Tau",p0 (> 0),p1,p2,p3)```.
-  Pushback the particle into the vector ```std::vector<Particle> particles```.

To implement a new momentum;

-  Use the format ```name(p0 (> 0),p1,p2,p3)```.
-  Pushback the momentum into the vector ```std::vector<Momentum> momenta```.

To modify existing particle / momenta;

- Use setters, e.g. ```muon4.set_p1_component(67)```.

To add a new particle type;

- Find ```set_particle_name()``` in particle.cpp.
- Add new particle name to ```valid_particle_list```.
- Implement a corresponding type assignment.

Adding new arithmetic operations;

- Declare new operator in momentum.h (ensure const set).
- Implement in momentum.cpp using same format as previous examples.

## Declaration of AI usage

AI tools were utilized in this coding process to;
- Debug and provide solutions to code errors.
- Provide feedback to code quality, and suggestions for improvement.

The core program logic, structures and algorithms were developed independently by the student (11022726). With AI tools serving as an invaluable tool for debugging and review purposes.
