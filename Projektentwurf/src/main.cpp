#include "developer.hpp"
#include <vector>
#include <memory>
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
