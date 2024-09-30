#define BOOST_TEST_MODULE MyTestModule
#include <iostream>
#include "boost/test/included/unit_test.hpp"

BOOST_AUTO_TEST_SUITE(MyTestSuite)

BOOST_AUTO_TEST_CASE(test_case_1)
{
    BOOST_TEST(true);
    std::cout << "test1" << std::endl;
}

BOOST_AUTO_TEST_CASE(test_case_2)
{
    BOOST_TEST(true);
    std::cout << "test2" << std::endl;
}

BOOST_AUTO_TEST_CASE(test_case_3)
{
    BOOST_TEST(true);
    std::cout << "test3" << std::endl;
}

BOOST_AUTO_TEST_SUITE_END()