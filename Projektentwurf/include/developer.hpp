//declatration class
#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include <string>
#include <iostream>

// Base class Developer
class Developer {
public:
    // Constructor to initialize name and alias
    Developer(const std::string& name, const std::string& alias);
    virtual ~Developer() = default; // Virtual destructor to ensure derived classes are cleaned up correctly

    // Getter methods to get name and alias
    std::string getName() const;
    std::string getAlias() const;

    // Static method that outputs a message
    static void drink_coffee();

    // Method to load a logo from a file
    void load_logo_from_file(const std::string& filename);

    // Pure virtual method to be implemented in derived classes
    virtual void solve_problem() const = 0;

    // Overloaded output operator to use a Developer object with std::cout
    friend std::ostream& operator<<(std::ostream& os, const Developer& dev);

private:
    std::string name;  // Member variable for the name
    std::string alias; // Member variable for the alias name
    std::string logo;  // Member variable for the logo
};