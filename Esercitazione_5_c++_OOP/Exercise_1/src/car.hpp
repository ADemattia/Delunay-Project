#ifndef __CAR_H
#define __CAR_H

#include <iostream>

using namespace std;

namespace CarLibrary {

  class Car
  {
    public:
      Car(const string& producer,
          const string& model,
          const string& color) { }

      string Show() { return ""; }

  };


  enum class CarProducer: char
  {
  };

  class CarFactory
  {
    private:
      static CarProducer producer;

    public:
      static void StartProduction(const CarProducer& producer) { }
      static Car* Create(const string& color) { return nullptr; }
  };
}

#endif // __CAR_H
