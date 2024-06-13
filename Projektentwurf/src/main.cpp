#include "../include/developer.hpp"
#include <memory>
#include <vector>
#include <iostream>
#include <fstream>

// Helper function to check if a file exists
bool file_exists(const std::string& path) {
    std::ifstream file(path);
    return file.good(); // Check if the file can be opened
}

int main() {

    // Vector of shared_ptr to Developer objects
    std::vector<std::shared_ptr<Developer>> developers;

    // Create JuniorDeveloper and SeniorDeveloper objects
    auto junior = std::make_shared<JuniorDeveloper>("Peter Parker", "Spiderman");
    auto senior = std::make_shared<SeniorDeveloper>("Diana Prince", "Wonder Woman");

    // Load the logos from the files
    junior->load_logo_from_file("/workspaces/Project_angus-faik/Projektentwurf/logos/spiderman.txt");
    senior->load_logo_from_file("/workspaces/Project_angus-faik/Projektentwurf/logos/wonderwoman.txt");
    

    // Add the Developer objects to the vector
    developers.push_back(junior);
    developers.push_back(senior);

    // Iterate over the vector and call the solve_problem method for each Developer object
    for (const auto& dev : developers) {
        dev->solve_problem();
    }

    return 0; // Exit the program successfully
}
