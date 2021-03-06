#pragma once
#include <random>
#include "definitions.h"
///This is a random number generator with a given range
class EXPORT std::random_device;
class EXPORT std::mt19937;

class EXPORT RandomGenerator
{
    std::random_device _rd;
    std::mt19937 _mt;
public:
    RandomGenerator();

    double generateRandomInRange(double from, double to);
    unsigned generateRandomInRange(unsigned from, unsigned to);
};

