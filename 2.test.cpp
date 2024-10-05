/*
    как запустить и сколько потоков запускать
    работает
 */ 


#define BOOST_TEST_MODULE MyTestModule
#include <iostream>
#include <gmock/gmock.h>
#include "boost/test/included/unit_test.hpp"

#include "./include/1.factory.h"

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

BOOST_AUTO_TEST_SUITE_END()