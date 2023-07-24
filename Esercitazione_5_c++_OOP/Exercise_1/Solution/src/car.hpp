#ifndef __CAR_H
#define __CAR_H

#include <iostream>

using namespace std;

namespace CarLibrary { //creiamo un namespace di variabili utilizzabili

  class Car //classe car
  {
    private: // variabili della classe
      string producer;
      string model;
      string color;

    public:
      Car(const string& producer, //costruttore, dichiarato ma non inizializzato
          const string& model,
          const string& color);

      string Show() { return model + " (" + producer + "): color " + color; } //dichiarazione stringa, metodo (function) pubblico che ritorna stringa

  };


  enum struct CarProducer: char
  {
    UNKNOWN = 'U',
    FORD = 'F',
    TOYOTA = 'T',
    VOLKSWAGEN = 'V'
  };

  class CarFactory
  {
    private: //non accessibile da esterno, ma accessibile da una funzione interna
      static CarProducer producer; // static uguale per ogni istanza, enum

    public:
      static void StartProduction(const CarProducer& producer); // funzione dichiarata ma non inizializzata, static dà un metodo che non richiede istanze della classe specifica per essere utilizzata
      static Car* Create(const string& color); //dà puntatore a classe di tipo Car, funzione dichiarata ma non inizializzata
  };
}

#endif // __CAR_H
