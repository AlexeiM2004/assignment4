# Assignment 4 - Practicing Classes, special functions, memory management and function overloading.

## Program Brief

This program
- 


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
- Creates vectors to store both Particle and Momentum objects. 

Momentum.h; 
- Defines Momentum class, with private members, ```std::vector/?<double>* four_momentum``` abd ```bool valid_flag```.
- Declares public methods; default constructor, parameterised constructor, getters and setters (for each member respectively).
- Declares the special functions; copy constructor, move constructor and copy assignment operator.
- Declares arithmetic operators; addition, subraction, dot product and scalar multiplier.
- Declares utility operators; invariant_mass, calculate_beta and calculate_gamma.
- Declares display function.

Momentum.cpp;
- Implements a valid default constructor. 
- Implements the parameterised constructor. 
- Implements getters for all private members.
- Implements setters and validates each member of the momentum class.
- 

Particle.h;
- Defines source class with private members, ```std::string particle_name```, ```std::string particle_type```, ```Momentum* momentum``` and ```bool valid_flag```. 
- Declares public methods; default constructor, parameterised constructor, getters and setters (for each member respectively).
- Declares the special functions; copy constructor, move constructor, copy assignment operator.
- Declares display function.


Particle.cpp;
- Implements a valid default constructor.
- Implements the parameterised constructor. 
- Implements getters for all private members.
- Implements setters and validates each member of the source class.

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
