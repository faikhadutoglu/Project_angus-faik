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

/*
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
