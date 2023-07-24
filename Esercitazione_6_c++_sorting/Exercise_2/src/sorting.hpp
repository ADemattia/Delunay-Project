#ifndef __SORTING_H
#define __SORTING_H

#include "iostream"
#include "list"
#include "Eigen/Eigen"
#include "map"

using namespace std;
using namespace Eigen;

namespace SortLibrary {


  struct DecreasingInt
  {
    int value;
    DecreasingInt() = default;
    DecreasingInt(const int& value): value(value){}

  };

  inline ostream &operator<<(ostream &os, const DecreasingInt &obj)
  {
    os << obj.value;
    return os;
  }

  inline bool operator==(const DecreasingInt &obj1, const DecreasingInt &obj2)
  {
    return obj1.value == obj2.value;
  }

  inline bool operator!=(const DecreasingInt &obj1, const DecreasingInt &obj2)
  {
    return !(obj1 == obj2);
  }

  inline bool operator<(const DecreasingInt &obj1, const DecreasingInt &obj2)
  {
    return obj1.value > obj2.value;
  }

  inline bool operator>(const DecreasingInt &obj1, const DecreasingInt &obj2)
  {
    return obj1.value < obj2.value;
  }

  template<typename T>
  int MigliorePadreFigli(const vector<T>& v,int m,int k)
  {
      if(v.size()<m || !(k<m))
      {
          cerr<<"le dimensioni del vettore devono essere maggiori uguali a m"<<endl;
          return -1;
      }
      int s,d; //sinistro destro
      s=d=2*k+1; //poniamo indicatore figlio destro e indicatore figlio sinistro uguali a indicatore figlio sinistro
      if(d+1<m)
      {
       d=d+1;
      }
      if(v[d]<v[s]) // confronto figlio destro e figlio sinistro, standard sarà figlio sinistro
      {
          s=d;
      }
      if(v[k]<v[s]) //confronto padre e figlio sinistro
      {
          s=k;
      }

      return s;

  }

  template<typename T>
  vector<T> HeapSort(const vector<T>& v){
    vector<T> SortedV=v;
    unsigned int heapsize=v.size();
    int j,k,i;
    vector<T> preSortedV;
    preSortedV.resize(heapsize);
    cout<<endl;
    for(i=0; i<heapsize; i++) //effettuiamo enqueque heap in maniera tale che a fine di ogni passo abbiamo un heap binario (chiaramente da definizione ordinato)
    {
        preSortedV[i]=SortedV[i];
        T tmp;
        j=(i-1)/2; // cosi considerando che array parte da indice 0, otteniamo sempre il padre, anche soprattutto a come avviene il casting su C++ da double ad  interi ( ci dà parte intera e non fa approssimazione es 3.8->3)
        k=i; // nodo figlio, mentre j è nodo padre
        while(j>=0 && preSortedV[j]>preSortedV[k] ) //riogranizzazione heap binario ordinato partendo da nodo posto in fondo
        {
            tmp=preSortedV[k]; //ci salviamo valore nodo figlio
            preSortedV[k]=preSortedV[j]; //poniamo la posizone del nodo figlio uguale al nodo padre
            preSortedV[j]=tmp; //così abbiamo scambiato figlio e padre;
            k=j;
            j=(j-1)/2; //aggiorniamo gli indicatori in modo tale da poter andare a fare un'altra iterazione su rapporto padre-figlio
        } //qui finisce la riorganizzazione e dovremmo trovarci un heap ordinato

        for(unsigned int h=0; h<heapsize; h++)
        {
            cout<<preSortedV[h]<<",";
        }

        cout<<endl;


     }

    cout<<endl;

    i=0; j=0; k=1;
    int min;
    int m=heapsize; //indicatore che ci servirà per lo scambio
    for(i=0; i<heapsize; i++) //effettuarte dequeque estriamo argomenti dalla priorità maggiore (ovvero elementi minori che si trovano al primo posto) e poi riorganizziamo heap
    {
        T tmp2;
        SortedV[i]=preSortedV[0]; //estriamo elemento priorità massima, manterremo in preSortedV heap da 0 a m (m verrà aggiornato)
        preSortedV[0]=preSortedV[m-1]; //aggiorniamo elemento
        m=m-1; //aggiorniamo la lunghezza del nostro array di heap
        k=0; //j figlio sinistro
        j=2*k+1; //k radice e j è il figlio sinistro, controlliamo il figlio sinistro poichè abbiamo la completezza a sinistra e quindi se non abbiamo il destro non abbiamo informazioni sul sinistro
        while(j<m && k!=MigliorePadreFigli(preSortedV,m,k) ) //riordina heap partendo dall'alto
        {
            min=MigliorePadreFigli(preSortedV,m,k);
            tmp2=preSortedV[min]; //ci salviamo valore nodo figlio
            preSortedV[min]=preSortedV[k]; //poniamo la posizone del nodo figlio uguale al nodo padre
            preSortedV[k]=tmp2;
            k=min; //aggiornare k
            j=2*k+1;
            cout<<k<<","<<endl;
        }
        for(unsigned int h=0; h<heapsize; h++)
        {
            cout<<SortedV[h]<<",";
        }

        cout<<endl;


    }

    return SortedV;
  }

   /// ... and other

}




#endif // __SORTING_H
