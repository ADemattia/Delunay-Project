#ifndef __SORTING_H
#define __SORTING_H

#include "iostream"
#include "list"
#include "Eigen/Eigen"
#include "map"

using namespace std;
using namespace Eigen;

namespace SortLibrary {

  template<typename T>
  void Merge(vector<T>& v,
             const unsigned int& sx, //posizioni
             const unsigned int& cx,
             const unsigned int& dx)
  {
      size_t n1,n2;
      n1=(cx-sx)+1; n2=(dx-cx); //numero elemnti vettori
     //  cout<<n1<<"//"<<n2<<endl;
      vector<T> L; //vettori destro e sinistro
      vector<T> R;
      L.resize(n1); //size_t è un type che si usa per
      R.resize(n2);
      for(size_t i=0; i<n1;i++)
      {
          L[i]=v[i+sx];
          //così si accede a vettore
      }
     // for(size_t i=0; i<n1;i++)
      //{
        //  cout<<L[i]<<",";
          //così si accede a vettore
      // }
    //  cout<<endl<<"***************"<<endl;

      for(size_t k=0; k<R.size();k++)
      {
          R[k]=v[cx+1+k];
         // cout<<R[k]<<endl<<"prova"<<endl;
          //così si accede a vettore
      }

      // cout<<endl<<"***************";


      size_t r,l;
      r=0;
      l=0;
      cout<<endl;
      for(size_t h=sx; h<dx+1; h++)

      { // cout<<l<<"(("<<r<<endl;
          if(l==n1)
          {
            v[h]=R[r];
            r++;
          }
          else if(r==n2)
                    {
                      v[h]=L[l];
                      l++;
                    }

        if(r!=n2 && l!=n1)
          {
              if(R[r]>L[l])
              {
            v[h]=L[l];
            l++;
            }
            else
            {
             v[h]=R[r];
             r++;
            }
          }

       // for(size_t m=0;m<v.size();m++){
         //   cout<<v[m]<<",";
       // }
        // cout<<endl;

      }

     // for(size_t m=0;m<v.size();m++){
       //   cout<<v[m]<<",";
      // }
      // cout<<endl;
      return;


  }



  template<typename T>
  void MergeSort(vector<T>& v,
                 const unsigned int& sx,
                 const unsigned int& dx){
      if(sx<dx){
          unsigned int q=(sx+dx)/2;
          // cout<<q<<" PPPP"<<endl;
          MergeSort(v,sx,q);
          MergeSort(v,q+1,dx);
          Merge(v,sx,q,dx);
}

      return;

}


}

#endif // __SORTING_H
