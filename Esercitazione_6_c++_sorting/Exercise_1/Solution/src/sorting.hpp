#ifndef __SORTING_H
#define __SORTING_H

#include "iostream"
#include "list"
#include "Eigen/Eigen"
#include "map"

using namespace std;
using namespace Eigen;

namespace SortLibrary {

  template<typename T> //creiamo una funzione template che vale per tutti i tipi di variabile
  vector<T> SelectionSort(const vector<T>& v){
    unsigned int n = v.size(); //.size() abbiamo dimensione
    vector<T> sortedV = v; //inizializziamo vettore dove mettere elementi e non modifichiamo quello che già abbiamo, modificando quello che avevamo avremmo risparmiato memoria
    for(unsigned int i = 0; i < n-1; i++) //scorriamo tutto ed evitiamo l'ultimo, i si dichiara e si inizializza come variable
    {
      T min = sortedV[i]; //il minimo da confrontare ad iterazione successiva diventa l'i+1-esimo elemento
      unsigned int id_min = i; //id elemnto minimo

      for(unsigned int j = i+1 ; j < n; j++) //si scorre da elemento successivo a i
      {
        if (sortedV[j] < min){
          min = sortedV[j];
          id_min = j;
        }
      }
      sortedV[id_min] = sortedV[i]; //scambiamo elementi di id_min e i, in min abbiamo salvato l'elemento minimo
      sortedV[i] = min;
    }

    return sortedV;
  }

  template<typename T>
  vector<T> InsertionSort(const vector<T>& v){
    unsigned int n = v.size();
    vector<T> sortedV = v; //come prima creiamo un nuovo vettore e lo inizializziamolo uguale a v
    for(unsigned int i = 0; i < n; i++)
    {
      T next = sortedV[i]; //si può inizializzare e dichiarare in ciclo for, ogni volta che finisce il ciclo la variabile viene eliminata
      unsigned int j = i;

      while((j > 0 ) && (sortedV[j-1] > next)) //j-1
      {
        sortedV[j] = sortedV[j-1]; // va in profondità il next, sortedV[j] prende elemento precedente e ora analizziamo se next può stare in posizione j-1 vedendo se è maggiore di valore in j-2
        j--;
      }
      sortedV[j] = next;
    }

    return sortedV;
  }

   /// ... and other

}




#endif // __SORTING_H
