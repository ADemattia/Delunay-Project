#ifndef __EMPTY_H
#define __EMPTY_H

#include <iostream>
#include <cmath>
#include "Eigen/Eigen"

using namespace std;

namespace ProjectLibrary
{
class Point
{
public:
    int id;
    double x;
    double y;
    double aux; //variabile ausiliaria
public:
    Point operator-(const Point& other) //creiamo un operatore che ci dà vettore
    {
     class Point q;
     q.x=(this->x)-other.x;  /// INSERIRE CANCELLAZIONE NUMERICA
     q.y=(this->y)-other.y;
     return q;
    }
    Point operator*(const Point& other) //creiamo un operatore che ci dà vettore
    {
     class Point q;
     q.aux=(this->x)*other.y-(this->y)*other.x;
     return q;
    }

    void operator =(const Point& other)
    {
      id=other.id;
      x=other.x;
      y=other.y;
      aux=other.aux;
    }

    double norm() //non dobbiamo dare input perchè funziona internamente
    {
      double n; //ci calcoliamo la norma euclidea
      n=sqrt(pow(x,2)+pow(y,2));
      return n;
    }

    void normalization()
    {
        x=x/(this->norm());
        y=y/(this->norm());
        return;
    }

    bool polarOrd(const class Point& other)
    {
        if(aux<=other.aux)
            return true;
        else
            return  false;
    }

    void polarShow()
    {
        cout<<aux;
    }




public:
    Point(double a=0,double b=0): x(a), y(b) {} //mettiamo anche costruttore di default
    Point(double a,double b,int z): id(z), x(a), y(b) {} //mettiamo anche costruttore di default
    Point(const Point& copy)
    {
      id=copy.id;
      x=copy.x;
      y=copy.y;
      aux=copy.aux;
    }

    void asg(const double d)
    {
      aux=d;
      return;
    }
    string Show() //funzione Show la usiamo per mostrare punti
    {
      return "Coordinata x: "+to_string(x)+", Cordinata y: "+to_string(y);
    }


    friend class Triangle;
};



class Triangle
{
public:
    class Point p1; //punti ordinati in senso antiorario, passiamoli come puntatori poichè li memorizziamo in heap
    class Point p2;
    class Point p3;
    //puntatori che danno adiacenza

    class Triangle *adj12;  //lato da p1 a p2
    class Triangle *adj23;  // lato da p2 a p3
    class Triangle *adj31;  // lato da p3 a p1
    class Point centre; //posizione circocentro
    double d; //distanza
    int yid; // intero riferito ad elementi visitati
    int eid;
    bool j;
    bool l;
    int rid;
    bool index;
  public:
    Triangle(class Point& p,class Point& q,class Point& w)
    {
        rid=-1;
        yid=-1; //inizializziamolo come non visitato, poi lo andremo a
        eid=-1;
        j=0;
        l=0;
        index=0;
        adj12=nullptr;
        adj23=nullptr;
        adj31=nullptr;
        double D=2*(p.x*(q.y-w.y)+q.x*(w.y-p.y)+w.x*(p.y-q.y));
        centre.x=((pow(p.x,2)+pow(p.y,2))*(q.y-w.y)+(pow(q.y,2)+pow(q.x,2))*(w.y-p.y)+(pow(w.x,2)+pow(w.y,2))*(p.y-q.y))/D;  //calcolo circocentro, ci servirà dopo come indicatore per spostarci nel grafo
        centre.y=((pow(p.x,2)+pow(p.y,2))*(-q.x+w.x)+(pow(q.y,2)+pow(q.x,2))*(-w.x+p.x)+(pow(w.x,2)+pow(w.y,2))*(-p.x+q.x))/D;


        if(p.norm()<=q.norm() && p.norm()<=w.norm()) //scegliamo come punto iniziale, il punto di norma minima
        {
          p1=p;
          p2=q;
          p3=w;
        }
        else if(q.norm()<=w.norm())
        {
          p1=q;
          p2=p;
          p3=w;
        }
        else{
            p1=w;
            p2=p;
            p3=q;
        }
        class Point G=(p3-p2)*(p2-p1);

        if((G).aux<0) //<0 è counter clockwise
        {

        }
        else //altrimenti clockwise e invertiamo
        {
          class Point P=p2;
          p2=p3;
          p3=P;
        }




    }
    double det(const class Point& q){
        double det;
        det=(p1.x-q.x)*(p2.y-q.y)*(pow(p3.x-q.x,2)+pow(p3.y-q.y,2))-(p1.x-q.x)*(p3.y-q.y)*(pow(p2.x-q.x,2)+pow(p2.y-q.y,2))-(p2.x-q.x)*(p1.y-q.y)*(pow(p3.x-q.x,2)+pow(p3.y-q.y,2))+(p2.x-q.x)*(p3.y-q.y)*(pow(p1.x-q.x,2)+pow(p1.y-q.y,2))+(p3.x-q.x)*(p1.y-q.y)*(pow(p2.x-q.x,2)+pow(p2.y-q.y,2))-(p3.x-q.x)*(p2.y-q.y)*(pow(p1.x-q.x,2)+pow(p1.y-q.y,2));
        return det;
        cout<<endl<<det<<endl;
    }

    void indexEq(class Triangle* T,int& t11,int& t12,int& t21,int& t22) //standard che t11 e t21 contengano indichino nei rispettivi triangoli allo stesso punto; metodo usato solo con triangoli adiacenti
    {
        vector<class Point> V;
        V.push_back(T->p1);
        V.push_back(T->p2);
        V.push_back(T->p3);

        if(p1.id==T->p1.id)
        {
           if(p2.id==T->p3.id)
           {
              t11=1;
              t21=1;
              t12=2; //secondo punto interessato
              t22=3; //punto interessato nel secondo triangolo
              return;
           }
           if(p3.id==T->p2.id)
           {
               t11=1;
               t21=1;
               t12=3;
               t22=2;
               return;
            }
        }

        if(p2.id==T->p2.id)
        {
            if(p1.id==T->p3.id)
            {
                t11=2;
                t21=2;
                t12=1;
                t22=3;
                return;
            }

            if(p3.id==T->p1.id)
            {
                t11=2;
                t21=2;
                t12=3;
                t22=1;
                return;
            }
        }

        if(p3.id==T->p3.id)
        {
            if(p1.id==T->p2.id)
            {
                t11=3;
                t21=3;
                t12=1;
                t22=2;
                return;
            }
            if(p2.id==T->p1.id)
            {
                t11=3;
                t21=3;
                t12=2;
                t22=1;
                return;
            }
        }
        if(p3.id==T->p2.id)
        {
            if(p2.id==T->p3.id)
            {
                t11=3;
                t21=2;
                t12=2;
                t22=3;
                return;
            }
        }
    }

    void pointEqTrian(class Triangle* T,int& h11,int& h12,int& h21,int& h22)
    {
        vector<class Point> V; //punti triangolo con cui chiamiamo il metodo
        vector<class Point> W; //punti triangolo dato in input
        int k=0;
        V.push_back(p1);
        V.push_back(p2);
        V.push_back(p3);

        W.push_back(T->p1);
        W.push_back(T->p2);
        W.push_back(T->p3);

        for(int i=0;i<V.size();i++)
        {
            for(int j=0; j<W.size();j++)
            {
                if(k==0)
                {
                    if(V[i].id==W[j].id)
                    {
                        h11=i+1;
                        h21=j+1;
                        k=1;
                    }
                }
                else if(k==1){
                    if(V[i].id==W[j].id)
                    {
                        h12=i+1;
                        h22=j+1;

                        return;
                    }

                }
                else{

                }
            }
        }

        return;

    }


};


  double distance(class Point P,class Point Q);
  inline double Area(const class Point& P1,const class Point& P2, const class Point& P3);
  inline double dotPoint(const class Point& P, const class Point& Q);
  class Point findMin(vector<class Point>& V); //passato by reference così lo ordiniamo internamente
  void polarSort(vector<class Point>& V, class Point P);
  void merge(vector<class Point>& V,const int a,const int b,const int c);
  void mergeSortaux(vector<class Point>& V,int a,int b);
  std::list<class Point> convexHull(vector<class Point>& V, class Point& P);
  vector<class Point> maxArea(std::list<class Point> S); //non passiamo referenza
  void bpoint(const vector<class Point>& V,int& P1,int& P2,int& P3);
  bool importDataVec(const string name,vector<class Point>& V);

  bool interTria(class Triangle& T,class Point& Q);
  void insOrd(list<class Triangle*>& lista,class Triangle* pT);
  bool interno(class Point& Q, Triangle **head);
  void creaTriaInn(class Triangle** T,class Point& Q);

  bool boxInter(class Point& P1,class Point& P2,class Point& P3,class Point& Q);
  bool segmentInter(class Point& p1, class Point& p2, class Point& p3, class Point& p4);
  bool segmentValidTriangle(class Triangle** head,class Point& P1,class Point& Q);
  void puntoEsterno(Triangle **head, class Point& Q);

  Triangle* creaTriaEst12(Triangle** head, class Point& Q);
  Triangle* creaTriaEst23(Triangle** head, class Point& Q);
  Triangle* creaTriaEst31(Triangle** head, class Point& Q);

  void flip(class Triangle** head, class Triangle** pT, bool b, bool d); //usata quando già sappiamo di dover fare il filp
  bool delunayCondition(class Point& A,class Point& B,class Point& C,class Point& D,class Point& E,class Point& F);
  void verificaDelunay2(class Triangle** head);
  void verificaDelunay1(class Triangle** head);
  void miniVerifica(Triangle **head, bool f, int &h);

  void stampaTriangoli(class Triangle** head);
}

#endif // __EMPTY_H
