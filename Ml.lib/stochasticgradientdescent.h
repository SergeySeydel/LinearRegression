#pragma once
#include <vector>

#include "multipoint.h"
#include "definitions.h"
#include "randomgenerator.h" 

///Second gradient descent, this one is unnecessary, it is faster but less accurate
class EXPORT StochasticGradientDescent 
{
    static std::vector<double> calculateGradients(const std::vector<double>& thetas, const MultiPoint& point, double learningRate);
    static double computeError(const std::vector<double>& thetas, const MultiPoint& point);
    static double partialDiff(const MultiPoint& point, const std::vector<double>& thetas, int countOfPoints, int withRespectToThetaIndex);
public:
    static std::vector<double> calculateParameters(const std::vector<MultiPoint>& points, double learningRate);
};

