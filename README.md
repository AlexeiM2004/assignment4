# Assignment 4 - Practicing Classes, Special Functions, Memory Management and Function Overloading.

## Program Brief

This program builds on the object-oriented programming concepts used in assignment 3's program by introducing proper memory management, special functions (Rule of 0/3/5), and operator overloading. The program;
- Creates Particle objects, with associated name, type and four momenta.
- Implements dynamic memory allocation for four-momenta using heap-allocated vectors.
- Demonstrates special function usage such as, copy and move constructors and assignment operators and destructor. Allowing for deep copying and resource stealing. Correctly states every time a special function is used.
- Overloads functions for arithmetic operations such as; vector addition, subtraction, dot product and scalar multiplication.
- Uses utility functions for relativistic calculations such as; invariant mass, relativistic velocity and Lorentz factor.
- Validates particle names against the Standard Model (electron, muon ,tau )and associates the valid type (lepton).
- Displays particle information and four-momenta.

## Compilation code

For Windows;
- ```g++ main.cpp particle.cpp momentum.cpp -o assignment-4.exe -std=gnu++17```   
- Then run ```assignment-4.exe```

For Mac/Linux;
- ```g++-11 main.cpp particle.cpp momentum.cpp -o assignment-4.o -std=gnu++17```  
- Then run ```assignment-4.o```

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
- Defines Momentum class, with private members; ```std::vector/<double>* four_momentum``` abd ```bool valid_flag```.
- Declares public methods; default constructor, parameterised constructor, getters and setters (for each member respectively).
- Declares the special functions; copy constructor, move constructor copy assignment operator and destructor.
- Declares arithmetic operators; addition ```+```, subtraction ```-```, dot product and scalar multiplication ```*```.
- Declares utility operators; invariant_mass, calculate_beta and calculate_gamma.
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
- Defines source class with private members, ```std::string particle_name```, ```std::string particle_type```, ```Momentum* momentum``` and ```bool valid_flag```.
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

This code was developed in x phases,  

Phase 1 –  ; 

Phase 2 – ; 

Phase 3 – ; 

Phase 4 – ; 

Phase 5 – ; 

## Decleration of AI usage

AI tools were utilized in this coding process to;
- Debug and provide solutions to code errors.
- Provide feedback to code quality, and suggestions for improvement.

The core program logic, strutures and algorithms were developed independently by the student (11022726). With AI tools serving as an invaluable tool for debugging and review purposes.
