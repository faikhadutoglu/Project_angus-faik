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
    std::string logo_path = "../logos/"; // Path to the logo files

    // Check if the logo files exist
    if (!file_exists(logo_path + "spiderman.txt")) {
        std::cerr << "Unable to open file: " << logo_path << "spiderman.txt" << std::endl;
        return 1; // Exit the program if the file is not found
    }

    if (!file_exists(logo_path + "wonderwoman.txt")) {
        std::cerr << "Unable to open file: " << logo_path << "wonderwoman.txt" << std::endl;
        return 1; // Exit the program if the file is not found
    }

    // Vector of shared_ptr to Developer objects
    std::vector<std::shared_ptr<Developer>> developers;

    // Create JuniorDeveloper and SeniorDeveloper objects
    auto junior = std::make_shared<JuniorDeveloper>("Peter Parker", "Spiderman");
    auto senior = std::make_shared<SeniorDeveloper>("Diana Prince", "Wonder Woman");

    // Load the logos from the files
    try {
        junior->load_logo_from_file(logo_path + "spiderman.txt");
        senior->load_logo_from_file(logo_path + "wonderwoman.txt");
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return 1; // Exit the program if loading the logos fails
    }

    // Add the Developer objects to the vector
    developers.push_back(junior);
    developers.push_back(senior);

    // Iterate over the vector and call the solve_problem method for each Developer object
    for (const auto& dev : developers) {
        dev->solve_problem();
    }

    return 0; // Exit the program successfully
}
