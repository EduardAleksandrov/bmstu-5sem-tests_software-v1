#define BOOST_TEST_MODULE MyTestModule
#include <iostream>
#include <gmock/gmock.h>
#include "boost/test/included/unit_test.hpp"

#include "./include/1.integral.h"

BOOST_AUTO_TEST_SUITE(TestSuite_integral)

BOOST_AUTO_TEST_CASE(test_case_1)
{
    BOOST_TEST(true);
    std::cout << "test1" << std::endl;
}

BOOST_AUTO_TEST_CASE(test_case_2_integral_true)
{
    // Arrange
    double f1, f2, f3;

    // Act
    integral_three_cases(0.1, -2, 2, f1, f2, f3);

    // Assert
    BOOST_TEST(f1 == 5.34, boost::test_tools::tolerance(1e-5)); // Left Riemann sum  // "(Метод левых прямоугольников): Площадь равна: "
    BOOST_TEST(f2 == 5.34, boost::test_tools::tolerance(1e-5)); // "(Метод правых прямоугольников): Площадь равна: "
    BOOST_TEST(f3 == 5.34, boost::test_tools::tolerance(1e-5)); // "(Метод трапеций): Площадь равна: "
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

BOOST_AUTO_TEST_SUITE_END()