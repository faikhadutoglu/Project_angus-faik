#include "gtest/gtest.h"
#include "../include/developer.hpp"

TEST(DeveloperTest, TestSeniorDeveloper) {
    SeniorDeveloper sd("Diana Prince", "Wonder Woman");
    EXPECT_EQ(sd.getName(), "Diana Prince");
    EXPECT_EQ(sd.getAlias(), "Wonder Woman");
}

TEST(DeveloperTest, TestJuniorDeveloper) {
    JuniorDeveloper jd("Peter Parker", "Spiderman");
    EXPECT_EQ(jd.getName(), "Peter Parker");
    EXPECT_EQ(jd.getAlias(), "Spiderman");
}

TEST(DeveloperTest, sdTestLoadLogo) {
    JuniorDeveloper jd("Peter Parker", "Spiderman");
    EXPECT_THROW(jd.load_logo_from_file("invalid_path"), std::runtime_error);
}
TEST(DeveloperTest, sdTestLoadLogoInvalidPath) {
    SeniorDeveloper sd("Diana Prince", "Wonder Woman");
    EXPECT_THROW(sd.load_logo_from_file("invalid_path"), std::runtime_error);
}