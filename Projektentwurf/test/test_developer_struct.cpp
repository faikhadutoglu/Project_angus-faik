#include "gtest/gtest.h" // Include the Google Test framework header file
#include "../include/developer.hpp" // Include the header file for the Developer classes

// Test case for SeniorDeveloper class
TEST(DeveloperTest, TestSeniorDeveloper) {
    // Create a SeniorDeveloper object with name "Diana Prince" and alias "Wonder Woman"
    SeniorDeveloper sd("Diana Prince", "Wonder Woman");
    // Check if the getName() method returns the correct name
    EXPECT_EQ(sd.getName(), "Diana Prince");
    // Check if the getAlias() method returns the correct alias
    EXPECT_EQ(sd.getAlias(), "Wonder Woman");
}

// Test case for JuniorDeveloper class
TEST(DeveloperTest, TestJuniorDeveloper) {
    // Create a JuniorDeveloper object with name "Peter Parker" and alias "Spiderman"
    JuniorDeveloper jd("Peter Parker", "Spiderman");
    // Check if the getName() method returns the correct name
    EXPECT_EQ(jd.getName(), "Peter Parker");
    // Check if the getAlias() method returns the correct alias
    EXPECT_EQ(jd.getAlias(), "Spiderman");
}

// Test case to check the logo loading functionality for JuniorDeveloper
TEST(DeveloperTest, sdTestLoadLogo) {
    // Create a JuniorDeveloper object with name "Peter Parker" and alias "Spiderman"
    JuniorDeveloper jd("Peter Parker", "Spiderman");
    // Check if the initial logo is an empty string
    EXPECT_EQ(jd.getLogo(), "");
    // Load a logo from a specified file path
    jd.load_logo_from_file("/workspaces/Project_angus-faik/Projektentwurf/logos/test_logo");
    // Check if the logo was loaded correctly (assuming the content of the logo is "test test test")
    EXPECT_EQ(jd.getLogo(), "test test test");
}

// Test case to check handling of invalid file paths for logo loading in SeniorDeveloper
TEST(DeveloperTest, sdTestLoadLogoInvalidPath) {
    // Create a SeniorDeveloper object with name "Diana Prince" and alias "Wonder Woman"
    SeniorDeveloper sd("Diana Prince", "Wonder Woman");
    // Check if loading a logo from an invalid path throws a runtime error
    EXPECT_THROW(sd.load_logo_from_file("invalid_path"), std::runtime_error);
}