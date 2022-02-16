#include "pch.h"
#include "../Ml.lib/linearregression.h"
#include "../Ml.lib/gradientdescent.h"

class LinearRegressionTest : public ::testing::Test {
public:
    ///Example of template class LinearRegression
    LinearRegression<GradientDescent> lr;




};

TEST_F(LinearRegressionTest, testDimension3) {
    std::vector<MultiPoint> points;
    double b = 2.4;
    double k = 3.3;

    for (int i = 0; i < 10; ++i)
    {

        ///sticks ten points, with step one
        points.push_back(MultiPoint(b + k * i,
            { static_cast<double>(i),static_cast<double>(i + 0.1) }));
        /*     points.push_back(MultiPoint(2.4 + 3.3 * i + 3.7 * j + 0.6 * k,
                 { static_cast<double>(i), static_cast<double>(j), static_cast<double>(k) }));*/


    }

    auto th = lr.calculateParameters(points, 0.0001);
    EXPECT_EQ(th.size(), 3);
}

TEST_F(LinearRegressionTest, MySecondTest) {
    std::vector<MultiPoint> points;
    double b = 2.4;
    double k = 3.3;

    for (int i = 0; i < 10; ++i)
    {

        ///sticks ten points, with step one
        points.push_back(MultiPoint(b + k * i,
            { static_cast<double>(i)}));
        /*     points.push_back(MultiPoint(2.4 + 3.3 * i + 3.7 * j + 0.6 * k,
                 { static_cast<double>(i), static_cast<double>(j), static_cast<double>(k) }));*/


    }

    auto th = lr.calculateParameters(points, 0.0001);
  EXPECT_EQ(th.size(),2);
  EXPECT_NEAR(b, th[0], 0.0001);
  EXPECT_NEAR(k, th[1], 0.0001);
}

TEST_F(LinearRegressionTest, testPositiveKNegativeB) {
    std::vector<MultiPoint> points;
    double b = 2.4;
    double k = -3.3;

    for (int i = 0; i < 10; ++i)
    {

        ///sticks ten points, with step one
        points.push_back(MultiPoint(b + k * i,
            { static_cast<double>(i) }));
        /*     points.push_back(MultiPoint(2.4 + 3.3 * i + 3.7 * j + 0.6 * k,
                 { static_cast<double>(i), static_cast<double>(j), static_cast<double>(k) }));*/


    }

    auto th = lr.calculateParameters(points, 0.0001);
    EXPECT_EQ(th.size(), 2);
    EXPECT_NEAR(b, th[0], 0.0001);
    EXPECT_NEAR(k, th[1], 0.0001);
}

TEST_F(LinearRegressionTest, testNegativeKAndB) {
    std::vector<MultiPoint> points;
    double b = -2.4;
    double k = -3.3;

    for (int i = 0; i < 10; ++i)
    {

        ///sticks ten points, with step one
        points.push_back(MultiPoint(b + k * i,
            { static_cast<double>(i) }));
        /*     points.push_back(MultiPoint(2.4 + 3.3 * i + 3.7 * j + 0.6 * k,
                 { static_cast<double>(i), static_cast<double>(j), static_cast<double>(k) }));*/


    }

    auto th = lr.calculateParameters(points, 0.0001);
    EXPECT_EQ(th.size(), 2);
    EXPECT_NEAR(b, th[0], 0.0001);
    EXPECT_NEAR(k, th[1], 0.0001);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);

    /*if (::teamcity::underTeamcity()) {
        ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
        listeners.Append(new jetbrains::teamcity::TeamcityGoogleTestEventListener());
    }

    if (jetbrains::teamcity::underTeamcity()) {
        ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
        listeners.Append(new GTest::TeamCityAdapter());
    }*/

    ::testing::TestEventListeners& listeners = ::testing::UnitTest::GetInstance()->listeners();
    // Add unique flowId parameter if you want to run test processes in parallel
    // See http://confluence.jetbrains.net/display/TCD6/Build+Script+Interaction+with+TeamCity#BuildScriptInteractionwithTeamCity-MessageFlowId
    listeners.Append(new GTest::TeamCityAdapter());



    return RUN_ALL_TESTS();
}
//TEST_F(LinearRegressionTest, testMultipointDimension3) {
//    std::vector<MultiPoint> points;
//    double b = -2.4;
//    double k = -3.3;
//
//    for (int i = 0; i < 30; ++i)
//    {
//        for (int j = 0; j < 30; ++j)
//        {
//
//            ///sticks ten points, with step one
//            points.push_back(MultiPoint(b + k * i + 0.7 * j,
//                { static_cast<double>(i),static_cast<double>(j) }));
//            /*     points.push_back(MultiPoint(2.4 + 3.3 * i + 3.7 * j + 0.6 * k,
//                     { static_cast<double>(i), static_cast<double>(j), static_cast<double>(k) }));*/
//        }
//
//    }
//
//    auto th = lr.calculateParameters(points, 0.000001);
//    EXPECT_EQ(th.size(), 3);
//    EXPECT_NEAR(b, th[0], 0.0001);
//    EXPECT_NEAR(k, th[1], 0.0001);
//}
