#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<cassert>

#include <gradientdescent.h>
#include <stochasticgradientdescent.h>
#include <linearregression.h>



void testLinearRegressionGradientDescent()
{
    LinearRegression<GradientDescent> lr;
    std::vector<MultiPoint> points;

    for (int i = 0; i < 10; ++i)
    {
        
        
                points.push_back(MultiPoint(2.4 + 3.3 * i,
                    { static_cast<double>(i)}));
           /*     points.push_back(MultiPoint(2.4 + 3.3 * i + 3.7 * j + 0.6 * k,
                    { static_cast<double>(i), static_cast<double>(j), static_cast<double>(k) }));*/
        
        
    }

    auto th = lr.calculateParameters(points, 0.0001);

    int thetaIndex{};
    std::cout << "Gradient descent test:" << std::endl;
    std::cout << "Initial values: 2.4 3.3" << std::endl;
    std::cout << "Calculated values:" << std::endl;
    for (const auto& grad : th)
    {
        std::cout << std::setw(14) << "theta #" << thetaIndex++;
    }
    std::cout << std::endl;
    assert( fabs(th[0] - 2.4) < 0.01);
    assert(fabs(th[1] - 3.3) < 0.01);
    for (const auto& grad : th)
    {
        std::cout << std::setw(15) << grad;
    }
    std::cout << std::endl << std::endl;

}

void testLinearRegressionGradientDescent_negative()
{
    LinearRegression<GradientDescent> lr;
    std::vector<MultiPoint> points;

    for (int i = 0; i < 10; ++i)
    {


        points.push_back(MultiPoint(-2.8 - 3.3 * i,
            { static_cast<double>(i) }));
        /*     points.push_back(MultiPoint(2.4 + 3.3 * i + 3.7 * j + 0.6 * k,
                 { static_cast<double>(i), static_cast<double>(j), static_cast<double>(k) }));*/


    }

    auto th = lr.calculateParameters(points, 0.00001);

    int thetaIndex{};
    std::cout << "Gradient descent test:" << std::endl;
    std::cout << "Initial values: -2.8 -3.3" << std::endl;
    std::cout << "Calculated values:" << std::endl;
    for (const auto& grad : th)
    {
        std::cout << std::setw(14) << "theta #" << thetaIndex++;
    }
    std::cout << std::endl;
    assert(fabs(th[0] + 2.8) < 0.02);
    assert(fabs(th[1] + 3.3) < 0.01);
    for (const auto& grad : th)
    {
        std::cout << std::setw(15) << grad;
    }
    std::cout << std::endl << std::endl;

}

void testLinearRegressionGradientDescent_multiple()
{
    LinearRegression<GradientDescent> lr;
    std::vector<MultiPoint> points;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                points.push_back(MultiPoint(2.4 + 3.3 * i + 3.7 * j + 0.6 * k,
                    { static_cast<double>(i), static_cast<double>(j), static_cast<double>(k) }));
            }
        }
    }
    auto th = lr.calculateParameters(points, 0.0001);

    int thetaIndex{};
    std::cout << "Gradient descent test:" << std::endl;
    std::cout << "Initial values: 2.4 3.3 3.7 0.6" << std::endl;
    std::cout << "Calculated values:" << std::endl;
    for (const auto& grad : th)
    {
        std::cout << std::setw(14) << "theta #" << thetaIndex++;
    }
    std::cout << std::endl;
    assert(fabs(th[0] - 2.4) < 0.14);
    assert(fabs(th[1] - 3.3) < 0.2);
    assert(fabs(th[2] - 3.7) < 0.3);
    assert(fabs(th[3] - 0.6) < 0.5);
    
    for (const auto& grad : th)
    {
        std::cout << std::setw(15) << grad;
    }
    std::cout << std::endl << std::endl;

}

void testLinearRegressionStochasticGradientDescent()
{
    LinearRegression<StochasticGradientDescent> lr;
    std::vector<MultiPoint> points;

    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            for (int k = 0; k < 10; ++k)
            {
                points.push_back(MultiPoint(static_cast<double>(2.4 + 3.3 * i + 3.7 * j + 0.6 * k),
                    { static_cast<double>(i), static_cast<double>(j), static_cast<double>(k) }));
            }
        }
    }
    auto th = lr.calculateParameters(points, 0.0001);

    int thetaIndex{};

    std::cout << "Stochastic gradient descent test:" << std::endl;
    std::cout << "Initial values: 2.4 3.3 3.7 0.6" << std::endl;
    std::cout << "Calculated values:" << std::endl;
    for (const auto& grad : th)
    {
        std::cout << std::setw(14) << "theta #" << thetaIndex++;
    }
    std::cout << std::endl;

    for (const auto& grad : th)
    {
        std::cout << std::setw(15) << grad;
    }
    std::cout << std::endl << std::endl;

}

void testDesicionTree()
{
    std::ifstream in("data_banknote_authentication.txt");
    if (in.is_open())
    {
        std::string line;
        while (std::getline(in, line))
        {
            std::istringstream s(line);
            std::string field;
            while (std::getline(s, field, ','))
            {
                
            }
        }
    }
}

int main()
{
    testLinearRegressionGradientDescent();

    testLinearRegressionGradientDescent_multiple();
    testLinearRegressionGradientDescent_negative();
    return 0;
}
