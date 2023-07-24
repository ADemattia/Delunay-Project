#include "convexHull.hpp"
#include "sorting.hpp"
#include <iostream>
#include <Eigen/Dense>

namespace ConvexHullLibrary {

  bool UpperLine(const Point& p1,
                 const Point& p2,
                 const Point& p3) //vediamo se il punto p3 sta sopra la linea che congiunge p1 e p2
  {
   double m=(p1.y-p2.y)/(p1.x-p2.x);
   bool b;
   b=(p3.y>m*(p3.x-p1.x)+p1.y);
   return b;
  }

 void MergeHulls(vector<Point>& sortedV, //cx sarà il punto con x più avanzata della prima convexHull e cx+1 il punto con x più arretrata della seconda convex hull
                  const unsigned int& cx)
  {
    if(cx==0){
        cout<<"bastrraa"<<endl;
    return; }

      cout<<endl;
      cout<<"prova"<<endl;
      for(unsigned int i=0; i<sortedV.size();i++)
      {
          if(sortedV[i].prec!=nullptr){
              cout<<i<<"--succ:"<<sortedV[i].prec->id<<endl;
              cout<<"coordinate"<<sortedV[i].prec->x<<" e "<<sortedV[i].prec->y<<endl;

          }
      }
      cout<<"centro:  "<<cx<<endl;
      cout<<"centro: "<<cx<<endl;

      //cout<<a.x<<"//"<<a.y<<endl;
      // cout<<(v.succ==nullptr)<<endl;
      // cout<<(sortedV[cx].succ==nullptr)<<endl;
      unsigned int  c(cx);
      unsigned int  k(cx+1);
      //cout<<"central: "<<c<<endl;


      //cout<<(UpperLine(A[c],A[k],*(A[c].succ)) || UpperLine(A[c],A[k],*(A[k].prec)))<<endl;
      //cout<<UpperLine(A[c],A[k],*(A[c].succ))<<endl;
      cout<<"bala: "<<(UpperLine(sortedV[c],sortedV[k],*(sortedV[c].succ)))<<endl;
      while(UpperLine(sortedV[c],sortedV[k],*(sortedV[c].succ)) || UpperLine(sortedV[c],sortedV[k],*(sortedV[k].prec))) //* per dereferenziare
      {
          if(UpperLine(sortedV[c],sortedV[k],*(sortedV[c].succ)))
          {
              // (sortedV[c].succ)->prec=nullptr;
              Point a(*(sortedV[c].succ)); //v->succ è indirizzo in memoria che punta ad una struct puntatore
             // A[c].succ=nullptr;
              for(unsigned int o=0; o<sortedV.size();o++)
              {
                 if(sortedV[o].id==a.id)
                 {
                  c=o;
                  cout<<"central: "<<c<<endl;
                  o=2*sortedV.size();
                 }
              }
          }
          else
          {
              //(sortedV[k].prec)->succ=NULL;
              Point a(*(sortedV[k].prec));
              // (sortedV[k].prec)=NULL;
              for(unsigned int o=0; o<sortedV.size();o++)
              {
                 if(sortedV[o].id==a.id)
                 {
                  k=o;
                  o=2*sortedV.size();
                 }

          }
          }

       }

      cout<<endl;
      unsigned int u1,u2;
      u1=c;
      u2=k;
      cout<<" "<<u1<<" \\"<<u2<<endl;
      //Point b(sortedV[k]);  //si dà indirizzo
      // sortedV[k].succ=&sortedV[c];
      //sortedV[c].prec=&b;


      cout<<"Indicatori u1 e u2"<<endl;


      c=cx;
      k=cx+1;
      cout<<k<<endl;
      //cout<<(UpperLine(sortedV[2],sortedV[3],sortedV[1]))<<endl;
      cout<<"balaa: "<<(UpperLine(sortedV[c],sortedV[k],*(sortedV[k].succ)))<<endl;
      cout<<"prova"<<sortedV[c].id<<":::::"<<sortedV[k].id<<"::::::::::"<<(sortedV[c].prec)->id<<":::::::::::::"<<(sortedV[k].succ)->id<<endl;
      cout<<"boool:"<< (UpperLine(sortedV[c],sortedV[k],*(sortedV[c].prec)))<<endl;
      int n=0;
      cout<<"Coordinate primo punto"<<(sortedV[c].prec)->x<<" e "<<(sortedV[0].prec)->y<<endl;
      if((sortedV[c].prec)->x==sortedV[0].x){
          cout<<"ecco"<<endl;
      }

 while(!(UpperLine(sortedV[c],sortedV[k],*(sortedV[c].prec))) || !(UpperLine(sortedV[c],sortedV[k],*(sortedV[k].succ)))) //* per dereferenziare
      { if(!(UpperLine(sortedV[c],sortedV[k],*(sortedV[c].prec))))
          {
         if(n==0 || n==1){
         cout<<"identificatore"<<sortedV[c].id<<"::::::: "<<(sortedV[c].prec)->id<<endl;
         cout<<"x:"<<sortedV[c].x<<"::::::: "<<(sortedV[c].prec)->x<<endl;
         cout<<"y:"<<sortedV[c].y<<"::::::: "<<(sortedV[c].prec)->y<<endl;
         cout<<"Vettore destro: "<<sortedV[k].x<<"::::::: "<<sortedV[k].y<<endl;

         }
              // (sortedV[c].prec)->succ=nullptr;
              Point a(*(sortedV[c].prec)); //v->succ è indirizzo in memoria che punta ad una struct puntatore
              // sortedV[c].prec=nullptr;
              //cout<<"ehila"<<endl;
              for(unsigned int o=0; o<sortedV.size();o++)
              {
                 if(sortedV[o].id==a.id)
                 {
                  c=o;
                  o=2*sortedV.size();
                 }
                 if(n==1){
                     cout<<"Neeee sinistro 1: "<<sortedV[c].x<<endl;
                     n++;
                 }

          }



          }
          //cout<<"ci sono"<<endl;
          if(!(UpperLine(sortedV[c],sortedV[k],*(sortedV[k].succ))))
          {
               // (sortedV[k].succ)->prec=nullptr;
              Point a(*(sortedV[k].succ));
              // (sortedV[k].succ)=nullptr;
              for(unsigned int o=0; o<sortedV.size();o++)
              {
                 if(sortedV[o].id==a.id)
                 {
                  k=o;
                  o=2*sortedV.size();

                 }
          }
              if(n==0){
                  cout<<"Neeee destro: "<<sortedV[k].id<<endl;
                  n++;
              }
              }


       }

      // Point s(sortedV[k]);
      //sortedV[k].prec=&sortedV[c];
      // sortedV[c].succ=&s;
      unsigned int l1,l2;
      l1=c;
      l2=k;
      cout<<"%%  "<<l1<<"%%  "<<l2<<endl;
      unsigned int aux; //ausiliaria
      aux=u1; //così ci spostiamo su questo

     while(sortedV[aux].prec->id!=sortedV[l1].id) //diversi allora c'è un altro punto in mezzo
     {
       for(unsigned int o=0; o<sortedV.size();o++)
         {
            if(sortedV[o].id==sortedV[aux].prec->id)
            {
             aux=o;
             o=2*sortedV.size();
            }
     }

       (sortedV[aux].succ)->prec=nullptr;
         sortedV[aux].succ=nullptr;


    }


     for(unsigned int o=0; o<sortedV.size();o++)
       {
          if(sortedV[o].id==sortedV[aux].prec->id)
          {
           aux=o;
           o=2*sortedV.size(); //rompe il ciclo
          }
   }
     if(sortedV[aux].prec->id!=sortedV[aux].succ->id){
       (sortedV[aux].succ)->prec=nullptr;
       sortedV[aux].succ=nullptr;}
       sortedV[u1].prec=&sortedV[u2];
       sortedV[l1].succ=&sortedV[l2];

      aux=u2;
      // cout<<
       while(sortedV[aux].succ->id!=sortedV[l2].id) //diversi allora c'è un altro punto in mezzo
       {
         for(unsigned int o=0; o<sortedV.size();o++)
           {
              if(sortedV[o].id==sortedV[aux].succ->id)
              {
               aux=o;
               o=2*sortedV.size();
              }
       }

         if(sortedV[aux].prec->id!=sortedV[aux].succ->id)
         (sortedV[aux].prec)->succ=nullptr;
           sortedV[aux].prec=nullptr;

      }


       for(unsigned int o=0; o<sortedV.size();o++)
         {
            if(sortedV[o].id==sortedV[aux].succ->id)
            {
             aux=o;
             o=2*sortedV.size(); //rompe il ciclo
            }
     }
       if(sortedV[aux].prec->id!=sortedV[aux].succ->id){
         (sortedV[aux].prec)->succ=nullptr;
         sortedV[aux].prec=nullptr;}
         sortedV[u2].succ=&sortedV[u1];
         sortedV[l2].prec=&sortedV[l1];

         cout<<"Risultato convex Hulls"<<endl;

         for(unsigned int i=0; i<sortedV.size();i++)
         {
             if(sortedV[i].succ!=nullptr){
                 cout<<i<<"--succ:"<<sortedV[i].succ->id<<endl;

             }
         }







      return;



  }


  void MergeHull(vector<Point>& sortedV,
                 const unsigned int& sx,
                 const unsigned int& dx)
  {

      unsigned int cx=(dx+sx)/2;

      sortedV=ConvexHull(sortedV,sx,cx);
      cout<<"merge hull"<<endl;
      for(unsigned int i=0; i<sortedV.size();i++)
      {
          if(sortedV[i].prec!=nullptr){
              cout<<i<<"--succ:"<<sortedV[i].prec->id<<endl;
              cout<<"coordinate"<<sortedV[i].prec->x<<" e "<<sortedV[i].prec->y<<endl;

          }
      }
      unsigned int o=cx+1;
      sortedV=ConvexHull(sortedV,o,dx);
      cout<<"dopo destra: "<<endl;
      for(unsigned int i=0; i<sortedV.size();i++)
      {
          if(sortedV[i].prec!=nullptr){
              cout<<i<<"--succ:"<<sortedV[i].prec->id<<endl;
              cout<<"coordinate"<<sortedV[i].prec->x<<" e "<<sortedV[i].prec->y<<endl;

          }
      }

      MergeHulls(sortedV,cx);
      cout<<"Merge4 totalissimo"<<endl;
      for(unsigned int i=0; i<sortedV.size();i++)
           {
               if(sortedV[i].succ!=nullptr){
                   cout<<i<<"--succ:"<<sortedV[i].succ->id<<endl;

               }
      }


      return;

  }

  vector<Point> ConvexHull(vector<Point> points,const unsigned int s,const unsigned int e) //s star e end
  {
      //ordina i punti in base alle ascisse (coordinate su x), accediamo tramite lobreira
      if(e-s==0)
      {
         points[s].succ=&points[s];
         points[s].prec=&points[s];

          return points;


      }
      SortLibrary::MergeSort<Point>(points,0,points.size()-1);

      if(e-s==1) //possiamo sostituire tutto con switch e case
      {
       points[s].succ=&points[e];
       points[s].prec=&points[e];
       points[e].succ=&points[s];
       points[e].prec=&points[s];
       return points;
      }

      if(e-s==2) //(x3 * (y2 - y1) + x2 * (y1 - y3) + x1 * (y3 - y2))
      {
        double area;
        area=0.5*((points[e-1].x-points[e].x)*(points[s].y-points[e].y)-(points[s].x-points[e].x)*(points[e-1].y-points[e].y));

        if(area>0)   // A(x1, y1) 2, B(x2, y2) 1 e C(x3, y3) 0 può essere calcolata come segue:

            // area = 0.5 * ((x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1))

           // Se l'area del triangolo è positiva, i punti sono già orientati in senso antiorario.
        {
            points[e].succ=&points[e-1]; //successivo è anti clockwise
            points[e].prec=&points[s];
            points[e-1].succ=&points[s];
            points[e-1].prec=&points[e];
            points[s].succ=&points[e];
            points[s].prec=&points[e-1];
            for(unsigned int i=0; i<points.size();i++)
                 {
                     if(points[i].succ!=nullptr){
                         cout<<i<<"--succ:"<<points[i].succ->id<<endl;

                     }
            }

            // cout<<points[0].succ->id<<endl;

        }
        else
        {
            points[e].succ=&points[s];
            points[e].prec=&points[e-1];
            points[e-1].succ=&points[e];
            points[e-1].prec=&points[s];
            points[s].succ=&points[e-1];
            points[s].prec=&points[e];
            for(unsigned int i=0; i<points.size();i++)
                 {
                     if(points[i].succ!=nullptr){
                         cout<<i<<"--succ:"<<points[i].succ->id<<endl;

                     }
            }

          }
        return points;

        }

        if(points.size()>3)
        {
         unsigned int sx,dx;
         sx=s;
         dx=e;
         MergeHull(points,sx,dx);
         for(unsigned int i=0; i<points.size();i++)
              {
                  if(points[i].succ!=nullptr){
                      cout<<i<<"--succ:"<<points[i].succ->id<<endl;

                  }
         }
         return points;

        }
        return points;


        }











}

