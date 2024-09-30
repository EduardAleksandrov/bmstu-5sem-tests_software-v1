#define BOOST_TEST_MODULE MyTestModule
#include <iostream>
#include <gmock/gmock.h>
#include "boost/test/included/unit_test.hpp"

#include "./include/1.integral_v1.h"
#include "./include/1.integral_v2.h"

BOOST_AUTO_TEST_SUITE(TestSuite_integral)

// BOOST_AUTO_TEST_CASE(test_case_1)
// {
//     BOOST_TEST(true);
//     std::cout << "test1" << std::endl;
// }

BOOST_AUTO_TEST_CASE(test_case_2_integral_true)
{
    // Arrange
    double f1, f2, f3;

    // Act
    integral_three_cases(0.1, -2, 2, f1, f2, f3);

    // Assert
    BOOST_TEST(f1 == 5.34, boost::test_tools::tolerance(1e-2)); // Left Riemann sum  // "(Метод левых прямоугольников): Площадь равна: "
    BOOST_TEST(f2 == 5.34, boost::test_tools::tolerance(1e-2)); // "(Метод правых прямоугольников): Площадь равна: "
    BOOST_TEST(f3 == 5.34, boost::test_tools::tolerance(1e-2)); // "(Метод трапеций): Площадь равна: "
    std::cout << "test2" << std::endl;
}

BOOST_AUTO_TEST_CASE(test_case_3_integral_false)
{
    // Arrange
    double f1, f2, f3;

    // Act
    integral_three_cases(0.1, -2, 2, f1, f2, f3);
    bool check1 = f1 > 5.349;
    bool check2 = f2 > 5.349;
    bool check3 = f3 > 5.349;

    // Assert
    BOOST_TEST(check1 == false); // "(Метод левых прямоугольников): Площадь равна: "
    BOOST_TEST(check2 == false); // "(Метод правых прямоугольников): Площадь равна: "
    BOOST_TEST(check3 == false); // "(Метод трапеций): Площадь равна: "
    std::cout << "test3" << std::endl;
}

class F_integral: public FunY_interface
{
    double functionY(double x) override
    {
        double y;
        y = 0;
        // if(x)
            return y = x*x/2;
        throw "division by zero";
    }
};

BOOST_AUTO_TEST_CASE(test_case_4_integral_mock)
{
    // Arrange
    F_integral integral;
    Integral_cases int_funct{&integral, &FunY_interface::functionY};
    double f1, f2, f3;

    // Act
    int_funct.integral_three_cases(0.1, -2, 2, f1, f2, f3);

    // Assert
    BOOST_TEST(f1 == 2.67, boost::test_tools::tolerance(1e-2)); // Left Riemann sum  // "(Метод левых прямоугольников): Площадь равна: "
    BOOST_TEST(f2 == 2.67, boost::test_tools::tolerance(1e-2)); // "(Метод правых прямоугольников): Площадь равна: "
    BOOST_TEST(f3 == 2.67, boost::test_tools::tolerance(1e-2)); // "(Метод трапеций): Площадь равна: "
    std::cout << "test4" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()