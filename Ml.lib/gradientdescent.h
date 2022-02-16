#pragma once
#include "multipoint.h"
#include "definitions.h"

/// Class GradientDescent
///
/// Class used to calculate the gradient descent method, here are definition
class EXPORT GradientDescent {
    ///The calculation of the partial derivative, we take partial derivatives from thetas
    static double partialDiffWithRespectToTheta(const MultiPoint& point, const std::vector<double>& thetas, int countOfPoints, int thetaIndex); 
    ///computeError error calculation
    static double computeError(const std::vector<double>& thetas, const std::vector<MultiPoint>& points); 
    /// calculateGradients calculation of gradients (vectors) of each point
    static std::vector<double> calculateGradients(const std::vector<double>& thetas, const std::vector<MultiPoint>& points, double learningRate); 
public:
    ///calculateParameters The function that we call from the main application that set the LearningRate and the Experimental points
    static std::vector<double> calculateParameters(const std::vector<MultiPoint>& points, double learningRate); 
};

