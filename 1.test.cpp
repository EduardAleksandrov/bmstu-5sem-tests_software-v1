/*
    Комментарии преподавателя:
        Assert error Что ошибка возникает(проверка на возврат ошибок) - готово
        Тест с погрешностью eps [-2, 3], [-2+eps, 3-eps] - готово
        как запустить и сколько потоков запускать - готово 2.test
*/


#define BOOST_TEST_MODULE MyTestModule
#include <iostream>
#include <gmock/gmock.h>
#include "boost/test/included/unit_test.hpp"

#include "./include/1.integral_v1.h"
#include "./include/1.integral_v2.h"
#include "./include/1.factory.h"

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

BOOST_AUTO_TEST_CASE(test_case_2_1_integral_true)
{
    // Arrange
    double f1, f2, f3;
    double eps {0.01};

    // Act
    integral_three_cases(0.1, (-2+eps), (2-eps), f1, f2, f3);

    // Assert
    BOOST_TEST(f1 == 5.26, boost::test_tools::tolerance(1e-2)); // Left Riemann sum  // "(Метод левых прямоугольников): Площадь равна: "
    BOOST_TEST(f2 == 5.26, boost::test_tools::tolerance(1e-2)); // "(Метод правых прямоугольников): Площадь равна: "
    BOOST_TEST(f3 == 5.26, boost::test_tools::tolerance(1e-2)); // "(Метод трапеций): Площадь равна: "
    std::cout << "test2.1" << std::endl;
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

class F_integral_except: public FunY_interface
{
    double functionY(double x) override
    {
        double y;
        y = 0;
        if(x)
            return y = 1/x;
        throw std::runtime_error("division by zero");;
    }
};

BOOST_AUTO_TEST_CASE(test_case_4_1_exception)
{
    // Arrange
    F_integral_except integral;
    Integral_cases int_f{&integral, &FunY_interface::functionY};
    double f1, f2, f3;

    // Act // Assert
    BOOST_CHECK_THROW(int_f.integral_three_cases(0.1, 0, 2, f1, f2, f3), std::runtime_error);

    std::cout << "test4.1" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(TestSuite_factory)

BOOST_AUTO_TEST_CASE(test_create_circle) {
    // Arrange
    ShapeFactory factory;
    // Act
    auto shape = factory.createShape("Circle");
    // Assert
    BOOST_REQUIRE(shape != nullptr); // Проверяем, что объект не нулевой
    BOOST_CHECK_EQUAL(shape->draw(), "Drawing a Circle"); // Проверяем, что метод draw() возвращает правильное значение
    std::cout << "test5" << std::endl;
}

BOOST_AUTO_TEST_CASE(test_create_square) {
    // Arrange
    ShapeFactory factory;
    // Act
    auto shape = factory.createShape("Square");
    // Assert
    BOOST_REQUIRE(shape != nullptr); // Проверяем, что объект не нулевой
    BOOST_CHECK_EQUAL(shape->draw(), "Drawing a Square"); // Проверяем, что метод draw() возвращает правильное значение
    std::cout << "test6" << std::endl;
}

BOOST_AUTO_TEST_CASE(test_create_invalid_shape) {
    // Arrange
    ShapeFactory factory;
    // Act
    auto shape = factory.createShape("Triangle"); // Неверный тип
    // Assert
    BOOST_CHECK(shape == nullptr); // Проверяем, что объект равен нулю
    std::cout << "test7" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()