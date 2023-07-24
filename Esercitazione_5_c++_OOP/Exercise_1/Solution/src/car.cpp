#include "car.hpp"

namespace CarLibrary {

  Car::Car(const string& producer, const string& model, const string& color): // inizzializziamo
    producer(producer), // inizializzazione membri costruttore in maniera diversa ma lecita e più utilizzata, vista su quaderno viola
    model(model),
    color(color)
  {
  }

  CarProducer CarFactory::producer = CarProducer::UNKNOWN; //car producer è un enum, inizializziamo il CarFactory producer come variabile static a CarProducer::UNKNOW classe dell'enum

//non abbiamo bisogno di instanziare alcun elmento
  void CarFactory::StartProduction(const CarProducer& producer) //inizializziamo la funzione StartProduction utilizzando lo scope ::
  {
    CarFactory::producer = producer; //variabile static
  }

  Car* CarFactory::Create(const string& color) //car factory è una classe che ha come metodo (funzione) Create a cui si accede tramite scoope
  { //inizializzazione della function
    switch (producer) {
      case CarProducer::FORD: //car producer è un enum
        return new Car("Ford", "Mustang", color); // ritorna indirizzo a memoria heap new
      case CarProducer::TOYOTA:
        return new Car("Toyota", "Prius", color);
      case CarProducer::VOLKSWAGEN:
        return new Car("Volkswagen", "Golf", color);
      default: // condizione di defalut dello switch
        throw runtime_error("Invalid producer");
    }
  }
}
