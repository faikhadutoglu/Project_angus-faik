#ifndef DEVELOPER_HPP
#define DEVELOPER_HPP

#include <cstdint>

class Developer
{
   protected:
    uint8_t num_of_feet_ = 0;

   public:
    auto get_num_of_feet() -> uint8_t;
};

class SeniorDeveloper : public Developer
{
   public:
    SeniorDeveloper();
};

class JuniorDeveloper : public Developer
{
   public:
    explicit JuniorDeveloper(uint8_t);
};

#endif /* DEVELOPER_HPP */