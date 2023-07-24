#include "test_car.hpp"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv); //per iniziallizare i test
  return RUN_ALL_TESTS();
}
