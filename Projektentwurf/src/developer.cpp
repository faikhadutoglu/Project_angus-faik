#include "developer.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

// Constructor of the base class Developer, initializes name and alias
Developer::Developer(const std::string& name, const std::string& alias) : name(name), alias(alias) {}

// Getter method to get the name
std::string Developer::getName() const {
    return name;
}

// Getter method to get the alias
std::string Developer::getAlias() const {
    return alias;
}

// Static method that outputs a message
void Developer::drink_coffee() {
    std::cout << "Ahhhh, I needed that coffee!!!" << std::endl;
}

// Method to load a logo from a file
void Developer::load_logo_from_file(const std::string& filename) {
    std::ifstream file(filename); // Open the file
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename); // Throw an error if the file cannot be opened
    }
      std::cout << "the logo file cannot be opened";
//    std::getline(file, logo, '\0'); // Read the entire contents of the file into the variable logo
}

// Overloaded output operator to use a Developer object with std::cout
std::ostream& operator<<(std::ostream& os, const Developer& dev) {
    os << "Name: " << dev.getName() << "\nAlias: " << dev.getAlias();
    if (!dev.logo.empty()) { // If the logo is not empty, add it to the output
        os << "\nLogo: " << dev.logo;
    }
    return os;
}
// Constructor of the JuniorDeveloper class, calls the constructor of the base class
JuniorDeveloper::JuniorDeveloper(const std::string& name, const std::string& alias) 
    : Developer(name, alias) {}

// Implementation of the solve_problem method for JuniorDeveloper
void JuniorDeveloper::solve_problem() const {
    std::cout << *this << "\nPuh, that was tough" << std::endl; // Output the Developer information and a message
    drink_coffee(); // Call the drink_coffee method
}

// Constructor of the SeniorDeveloper class, calls the constructor of the base class
SeniorDeveloper::SeniorDeveloper(const std::string& name, const std::string& alias) 
    : Developer(name, alias) {}

// Implementation of the solve_problem method for SeniorDeveloper
void SeniorDeveloper::solve_problem() const {
    std::cout << *this << "\nHa, that was EZ!" << std::endl; // Output the Developer information and a message
    drink_coffee(); // Call the drink_coffee method
}