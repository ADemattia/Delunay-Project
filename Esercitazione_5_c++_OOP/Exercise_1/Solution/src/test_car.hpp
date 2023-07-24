#ifndef __TEST_CAR_H
#define __TEST_CAR_H

#include <gtest/gtest.h>

#include "car.hpp" //libreria

using namespace testing;


TEST(TestCar, TestShow)
{
  CarLibrary::Car car = CarLibrary::Car("Fiat", "Mustang", "Red"); //usiamo costruttore//
  EXPECT_EQ(car.Show(), "Mustang (Fiat): color Red"); //controlla che i due value (string) siano uguali  car show ritorna stringa
}

TEST(TestCarFactory, TestCreateFord)
{
  CarLibrary::CarFactory::StartProduction(CarLibrary::CarProducer::FORD); //inizializziamo con scoope entriamo in libreria specifica
  CarLibrary::Car* car = CarLibrary::CarFactory::Create("Red");
  EXPECT_TRUE(car != nullptr);
  EXPECT_EQ(car != nullptr ? car->Show() : "", "Mustang (Ford): color Red"); //value 1 e value 2, il value 1 è ottenuto tramite una struttura if
  delete car;
}

TEST(TestCarFactory, TestCreateToyota)
{
  CarLibrary::CarFactory::StartProduction(CarLibrary::CarProducer::TOYOTA); //memorizzata TOYOTA in unica valore preso da producer Car Factory poichè è static
  CarLibrary::Car* car = CarLibrary::CarFactory::Create("Red");
  EXPECT_TRUE(car != nullptr);
  EXPECT_EQ(car != nullptr ? car->Show() : "", "Prius (Toyota): color Red");
  delete car;
}

TEST(TestCarFactory, TestCreateVolkswagen)
{
  CarLibrary::CarFactory::StartProduction(CarLibrary::CarProducer::VOLKSWAGEN);
  CarLibrary::Car* car = CarLibrary::CarFactory::Create("Red");
  EXPECT_TRUE(car != nullptr);
  EXPECT_EQ(car != nullptr ? car->Show() : "", "Golf (Volkswagen): color Red");
  delete car;
}

#endif // __TEST_CAR_H
