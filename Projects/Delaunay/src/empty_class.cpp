#include "empty_class.hpp"
#include <fstream>
#include <sstream>
#include "Eigen/Eigen"
#include <list>
#define MAX 1000000
int s=0;

namespace ProjectLibrary
{
//INIZIO CALCOLO AREA MASSIMA
double distance(class Point P,class Point Q)
{
    double d;
    class Point Z(P-Q);
    d=dotPoint(Z,Z);
    d=sqrt(d);
    return d;
}

inline double Area(const class Point& P1,const class Point& P2, const class Point& P3)
{
double A;
A=0.5*abs((P1.x)*(P2.y-P3.y)+(P2.x)*(P3.y-P1.y)+(P3.x*(P1.y-P2.y)));
return A;
}

inline double dotPoint(const class Point& P, const class Point& Q)
 {
     double d;
     d=P.x*Q.x + P.y*Q.y;
     return d;
 }

class Point findMin(vector<class Point>& V)
{
unsigned int s=V.size();
class Point P(1e6,1e6,1e6);
int u=0;
for(auto i=0;i<s;i++)
{
    if((P.y)>V[i].y) //aggiungere caso ugualianza
    {
        P=V[i];
        u=i;
    }
    if(((P.y)==V[i].y) && ((P.x)>V[i].x))
    {
           P=V[i];
           u=i;
    }


}

V[u]=V[s-1];
V.pop_back(); //rimuove ultimo elemento vettore
return P;
}

void merge(vector<class Point>& V,const int a,const int b,const int c)
{

auto n1=b-a+1;
auto n2=c-b;
vector<class Point> A;
vector<class Point> B;
class Point P;


for(int i=0;i<n1;i++)
{
    A.push_back(V[a+i]);
    // A[i].polarShow();

}


for(int j=0;j<n2;j++)
{
    B.push_back(V[j+b+1]);
    // B[j].polarShow();

}

auto indA=0; auto indB=0;
auto indV=a;

while(indA<n1 && indB<n2)
{
    if(A[indA].polarOrd(B[indB]))
    {
        V[indV]=A[indA];
        indV=indV+1;
        indA=indA+1;
    }
    else
    {
        V[indV]=B[indB];
        indV=indV+1;
        indB=indB+1;
    }
}

while(indA<n1)
{
    V[indV]=A[indA];
    indV=indV+1;
    indA=indA+1;
}

while(indB<n2)
{
    V[indV]=B[indB];
    indV=indV+1;
    indB=indB+1;
}

}

void mergeSortaux(vector<class Point>& V,const int a,const int b)
{

    if(a<b)
    {
        int q=(b+a)/2; //dà sempre casting a parte intera
        mergeSortaux(V,a,q);
        mergeSortaux(V,q+1,b);
        merge(V,a,q,b);
    }
    return;
}

void polarSort(vector<class Point>& V, class Point P) //punto rispetto al quale calcoliamo gli angoli polari
{
 double epsilon=1e-6;
 unsigned int s=V.size();
 class Point X(1,0); //vettore normalizzato
 cout<<endl;
 for(int i=0;i<s;i++)
 {
     class Point Q=(V[i]-P);
     Q.normalization();
     V[i].asg(-dotPoint(Q,X)); //angolo polare trasformato in cos mantiene l'ordine, cambiamo segno poichè li vogliamo in senso anti orario e il più antiorario ha il massimo cambiando il segno avrà il minimo
     // cout<<"Polar Show: "<<"(id: "<<to_string(V[i].id)<<" )"<<" numero "<<i<<" :";
    // V[i].polarShow();
    // cout<<endl;

 }
 mergeSortaux(V,0,s-1);
 //cout<<endl;
 //for(int i=0;i<s;i++)
 //{
 //cout<<"punto "<<to_string(i)<<" coordx: "<<V[i].x<<"//"<<"coordy: "<<V[i].y<<endl;

 //}
 //for(int i=0;i<s;i++)
 //{
  //   cout<<"Polar Show: "<<"(id: "<<to_string(V[i].id)<<" )"<<" numero "<<i<<" :";
 //    V[i].polarShow();
 //    cout<<endl;

 // }
 class Point H(0,0,100000); //100000 id
 H.aux=10000;
 V.push_back(H);
 vector<class Point> T;
 for(int i=0;i<V.size()-1;i++)
 {
     if(abs(V[i].aux-V[i+1].aux)>epsilon)
     {

         T.push_back(V[i]);
     }
     else{
         class Point K;
         K=V[i];

         while(abs(V[i].aux-V[i+1].aux)<epsilon && i<s-1)
         {
             if(distance(P,V[i])<distance(P,V[i+1]) && !(V[i+1].id==100000))
             {
                 K=V[i+1];
             }

             i=i+1;

         }

            T.push_back(K);
           // for(int j=0;j<T.size();j++)
           // {
           //     cout<<"Polar Show j: "<<"(id: "<<to_string(T[j].id)<<" )"<<" numero "<<j<<" :";
           //     T[j].polarShow();
           //     cout<<endl;

           //}




     }

 }

 V=T;

 cout<<endl<<endl;

// for(int i=0;i<V.size();i++)
// {
//     cout<<"Polar Show: "<<"(id: "<<to_string(V[i].id)<<" )"<<" numero "<<i<<" :";
//     V[i].polarShow();
//     cout<<endl;

//}





 return;
}

std::list<class Point> convexHull(vector<class Point>& V, class Point& P)
{
    auto s=V.size();
    std::list<class Point> convSet;
    convSet.push_front(P); //con il push front usiamo la lista esattamente come uno stack con politca LIFO
    convSet.push_front(V[0]);
    convSet.push_front(V[1]);

    for(auto i=2; i<s;i++)
    {
    std::list<class Point>::iterator it1 = convSet.begin(); //poi prendiamo il next
    std::list<class Point>::iterator it2 = std::next(it1); //pendiamo iteratore successivo ovvero prendiamo
    class Point A;
    class Point B;
    A=*it1; //dereferenziamo per avere il punto memorizzato in lista
    B=*it2;
    class Point G=(V[i]-B)*(B-A);
    while(G.aux<0)
    {
      it1=std::next(it1);
      it2=std::next(it2);
      convSet.pop_front();
      A=*it1;
      B=*it2;
      G=(V[i]-B)*(B-A);
     }
    convSet.push_front(V[i]);
    }
    cout<<endl;
    for (std::list<class Point>::iterator it = convSet.begin(); it != convSet.end(); ++it) //da mettere in debug
   {
    cout<<"punto x: "<<to_string((*it).x)<<"--"<<" punto y: "<<to_string((*it).y)<<endl;
    }
    return convSet;

}

vector<class Point> maxArea(std::list<class Point> S)
{

    for (std::list<class Point>::iterator it = S.begin(); it != S.end(); ++it) //da mettere in debug
   {
   cout<<"punto x: "<<to_string((*it).x)<<"--"<<" punto y: "<<to_string((*it).y)<<endl;
    }

    vector<class Point> V;
    std::list<class Point>::iterator it1 =std::prev(S.end(), 1); //abbiamo bisogno di ordine in senso antiorario, verificata scrittura NON si mette S.end()
    std::list<class Point>::iterator it2 = std::prev(it1);
    std::list<class Point>::iterator it3 = std::prev(it2);
    cout<<(*it1).x<<endl;
    V.push_back(*it1);
    V.push_back(*it2);
    V.push_back(*it3);
    //V[2]=*it1;
    //cout<<V[2].x<<endl;
    it3=std::prev(it3); //andiamo in senso antiorario
    it2=std::prev(it2);
    it1=std::prev(it1);

    while(true){
        while(true){
            while(Area(V[0],V[1],V[2])<Area(V[0],V[1],*it3)){
                  V[2]=*it3;
                  if(it3==S.begin())
                  {
                    it3=std::prev(S.end(),1);
                  }
                  else{
                    it3=std::prev(it3);
                  }

        }
                  if(Area(V[0],V[1],V[2])<Area(V[0],*it2,V[2]))
                  {
                      V[1]=*it2;
                      if(it2==S.begin()){
                          it2=std::prev(S.end(),1);
                      }
                      else{
                         it2=std::prev(it2);
                      }
                   }
                  else{
                      break;
                  }

        }
        if(Area(V[0],V[1],V[2])<Area(*it1,V[1],V[2]))
        {
            V[0]=*it1;
            if(it1==S.begin()){
                it1=std::prev(S.end(),1);
            }
            else
            {it1=std::prev(it1);}
        }
        else{
            break;
        }
    }

    for(int j=0;j<3; j++)
    {
        cout<<"Punto n: "<<to_string(j)<<"// coordx: "<<to_string(V[j].x)<<"// coordy: "<<to_string(V[j].y)<<endl;
    }


    return V;
}

void bpoint(const vector<class Point>& V,int& P1,int& P2, int& P3)
{
  vector<class Point> W=V;
  Point G=findMin(W);
  polarSort(W,G);
  std::list<class Point> List=convexHull(W,G);
  vector<class Point> H=maxArea(List);


  P1=H[0].id;
  P2=H[1].id;
  P3=H[2].id;
  cout<<"Punto 1: "<<P1<<" Punto 2: "<<P2<<" Punto 3: "<<P3<<endl;
  return;

}

//FINE CALCOLO AREA MASSIMA


bool importDataVec(const string name,vector<class Point>& V){

    ifstream file; // creiamo un oggetto file
    file.open(name);
    if(file.fail()){
        cerr<<"Errore in apertura file"<<endl;
        return false;
    }
    string line;
    char c;
    istringstream convertS;
    getline(file,line); //passa linea file a linea stringa
    convertS.str(line);
    convertS>>c>>c>>c>>c;

    while(getline(file,line))
    {
        istringstream iss;
        iss.str(line);
        double X,Y;
        int k;
        iss>>k>>X>>Y;
        // cout<<k<<endl;
        class Point P(X,Y,k);
        V.push_back(P);
        // cout<<"Punto "<<k<<" coordx: "<<V[k].x<<"// coordy: "<<V[k].y<<endl;

    }



    file.close();
    return true;


}

//INIZIO VERIFICA PUNTO INTERNO
bool interTria(class Triangle& T,class Point& Q)
{ //punti triangolo ordinati in senso antiorario;
    double epsilon=1e-6;
    class Point G;
    G=(T.p2-T.p1)*(Q-T.p1);
    bool b; // * fa and
    b=(G.aux>-epsilon);
    G=(T.p3-T.p2)*(Q-T.p2);
    b=b*(G.aux>-epsilon);
    G=(T.p1-T.p3)*(Q-T.p3);
    b=b*(G.aux>-epsilon);
    return b;
}

void creaTriaInn(class Triangle** T,class Point& Q){
    Triangle* A;
    Triangle* B;
    Triangle* C;
    Triangle* D;
    //creiamo tutto in memoria heap
    A=new Triangle((*T)->p1,(*T)->p2,Q);
    B=new Triangle((*T)->p2,(*T)->p3,Q);
    C=new Triangle((*T)->p3,(*T)->p1,Q);

    if(A->p1.id==(*T)->p1.id) //se il primo punto è P1 => necessariamente il secondo sarà P2 e il terzo Q (da ordinamento vedi quaderno)
    {
        A->adj12=(*T)->adj12;
        A->adj23=B; //adiacenza di P2-Q (vedere quaderno) punterà a B
        A->adj31=C; //adiacenza di Q-P1

        if(B->p1.id==Q.id)
        {
            B->adj12=A;
            B->adj23=(*T)->adj23;
            B->adj31=C;

            C->adj12=A;
            C->adj23=B;
            C->adj31=(*T)->adj31;
        }
        if(B->p1.id==(*T)->p2.id)
        {
            B->adj12=(*T)->adj23;
            B->adj23=C;
            B->adj31=A;


            C->adj12=A; //tutto grazie ad ordinamento
            C->adj23=B;
            C->adj31=(*T)->adj31;
        }
        if(B->p1.id==(*T)->p3.id) //avrei potuto usare lo switch
        {
            B->adj12=C;
            B->adj23=A;
            B->adj31=(*T)->adj23;


            C->adj12=A;
            C->adj23=B;
            C->adj31=(*T)->adj31;
        }
    }
    if(A->p1.id==Q.id) //Q punto con norma minima e avremmo tutte gli ordini
    {
        A->adj12=C;
        A->adj23=(*T)->adj12;
        A->adj23=B;

        B->adj12=A;
        B->adj23=(*T)->adj23;
        B->adj31=C;

        C->adj12=B;
        C->adj23=(*T)->adj31;
        C->adj31=A;
    }

    D=(*T)->adj12; //triangolo adiacente tramite punti p1,p2 di T
    if(!(D==nullptr))
    {
        if(D->p1.id==(*T)->p1.id)
        {
         D->adj31=A;
        }
        if(!(D->p1.id==(*T)->p1.id))
        {
            D->adj23=A;
        }
    }

    D=(*T)->adj31;
    if(!(D==nullptr))
    {
      if(D->p1.id==(*T)->p1.id)
       {
        D->adj12=C;
        }
       if(!(D->p1.id==(*T)->p1.id))
        {
           D->adj23=C;
        }
    }

    D=(*T)->adj23;
    if(!(D==nullptr))
    {
      if(D->p1.id==(*T)->p3.id)
       {
        D->adj12=B;
        }
       if(!(D->p2.id==(*T)->p3.id))
        {
           D->adj23=B;
        }
       if(!(D->p3.id==(*T)->p3.id))
        {
           D->adj31=B;
        }
    }


    delete (*T); //elimina memoria in heap
    *T=A;
    return;

}

void insOrd(list<class Triangle*>& lista,Triangle* pT) //lista ordinata in senso crescente di distanza (passiamo una lista ordinata e un punto da ordinare
{   
 int k=0;
 if(lista.empty())
 {
    lista.push_front(pT);
 }
 else
 {
     for (auto it = lista.begin(); it != lista.end(); ++it) {
             if(((*it)->d)>((pT)->d))
             {
                it=std::prev(it); //andiamo al precedente
                lista.insert(it,pT); //inseriamo elemento dopo it;
                k=1;
                break;
             }
         }
     if(k==0)
     {
        lista.push_back(pT);
     }
 }
}

bool interno(class Point& Q,Triangle** head) //head va passato come indirizzo
{

 double epsilon=1e-6;
 list<Triangle*> coda; //creiamo una lista tipo coda priorità che andremo a ordinare in base a priorità (distanza Q da circocentro)
 // verifico prima se il punto è nel triangolo puntato da head
 if((*head)->det(Q)>-epsilon ) //da aggiungere una tolleranza
 {
    if(interTria(**head,Q))
    {
      creaTriaInn(head,Q); //modifichiamo anche l'head, che punterà al nuovo primo triangolo creato;
      return true;
    }
 }

 (*head)->yid=Q.id; //id in base a id dei punti
 if(!((*head)->adj12==nullptr)){
     (*head)->adj12->d=distance((*head)->adj12->centre,Q); coda.push_front((*head)->adj12);
 }
 if(!((*head)->adj23==nullptr)){
     (*head)->adj23->d=distance((*head)->adj23->centre,Q); insOrd(coda,(*head)->adj23);
 }
 if(!((*head)->adj31==nullptr)){
     (*head)->adj31->d=distance((*head)->adj31->centre,Q); insOrd(coda,(*head)->adj31);
 }

 while(!(coda.empty())) // fin quando la lista non è vuota
 {

    class Triangle* pT;
    std::list<class Triangle*>::iterator it = coda.begin(); //coda ordinata
    pT=*it;  //dà puntatore a elemento che è un puntatore a triangolo
    coda.pop_front();
    if(pT->det(Q)>-epsilon) //aggiungere tolleranza
    {
       if(interTria(*pT,Q)) //si dereferenzia con *
       {
           creaTriaInn(&pT,Q);
           return true;
       }
    }
    pT->yid=Q.id; //lo mettiamo come visitato

    if(!((pT)->adj12==nullptr)){
        if(!(pT->adj12->yid==Q.id)){
            (pT)->adj12->d=distance((pT)->adj12->centre,Q); insOrd(coda,(pT)->adj12);
        }

    }

    if(!((pT)->adj23==nullptr)){
        if(!(pT->adj23->yid==Q.id)){
            (pT)->adj23->d=distance((pT)->adj23->centre,Q); insOrd(coda,(pT)->adj23);
        }

    }

    if(!((pT)->adj31==nullptr)){
        if(!(pT->adj31->yid==Q.id)){
            (pT)->adj31->d=distance((pT)->adj31->centre,Q); insOrd(coda,(pT)->adj31);
        }

    }
}


 return false;
}

//FINE VERIFICA PUNTO INTERNO

//INIZIO CALCOLO PUNTO ESTERNO
bool boxInter(class Point& P1,class Point& P2,class Point& P3,class Point& Q) //true se i box non si intersecano, punti allineati danno triangolo degenere
{
    double epsilon=1e-6;
    double maxr1=(P1.y>=P2.y) ? P1.y:P2.y; //P1 e P2 primo triangolo, P3 e Q secondo triangolo
    double maxr2=(Q.y>=P3.y) ? Q.y:P3.y;
    double minr1=(P1.y<=P2.y) ? P1.y:P2.y;
    double minr2=(Q.y<=P3.y) ? Q.y:P3.y;
    double destr1=(P1.x>=P2.x) ? P1.x:P2.x; //destra maggiore x
    double destr2=(Q.x>=P3.x) ? Q.x:P3.x;
    double sinisr1=(P1.x<=P2.x) ? P1.x:P2.x;
    double sinisr2=(Q.x<=P3.x) ? Q.x:P3.x;

    // cout<<"prova"<<endl;

    if(minr1-maxr2>-epsilon)
    {
        //cout<<"vero"<<endl;
        return true;

    }
    if(maxr1-minr2<epsilon)
    {
        //cout<<"vero"<<endl;
        return true;

    }
    if(sinisr1-destr2>-epsilon)
    {
        //cout<<"vero"<<endl;
        return true;

    }
    if(destr1-sinisr2<epsilon)
    {
        //cout<<"vero"<<endl;
        return true;

    }
    // cout<<"falso"<<endl;

    return false;
 }

bool segmentInter(class Point& P1,class Point& P2,class Point& P3,class Point& Q) //true se è si intersecano
{
    class Point T(P1-P2);
    class Point W(Q-P3);
    class Point G;
    double epsilon = 1e-6;

   // cout<<"rrrrr"<<endl;
    G=T*W;
    if(abs(G.aux-0)<epsilon) //verifichiamo che non sono paralleli sappiamo già che non sono uguali e non possono essere allineati
    {
        return false; //ritonra falsa intersezione se combaciano
    }
    double m1,m2;
    double A1,B1,A2,B2,r1,r2;
    double d,Dy,Dx;
    if(!(abs(T.x-0)<epsilon) && !(abs(W.x-0)<epsilon))
    {
        m1=T.y/T.x;
        m2=W.y/W.x;
        A1=1; // equazioni rette Ay+Bx=r
        A2=1;
        B1=-m1;
        B2=-m2;
        r1=P1.y-P1.x*m1;
        r2=Q.y-Q.x*m2;
        d=(A1*B2)-(A2*B1); //determinante (già sappiamo da condizione prima che non è nullo
        Dy=(r1*B2)-(r2*B1); // regola cramer
        Dx=(A1*r2)-(A2*r1);
        class Point I(Dx/d,Dy/d); //facciamolo con le distanze, si dimostra vero facilmente con
        double dist1,dist2;
        dist1=distance(I,P1)+distance(I,P2); //ipotenusa
        dist2=distance(I,Q)+distance(I,P3);
        if(abs(dist1-distance(P1,P2))<epsilon && abs(dist2-distance(Q,P3))<epsilon)
        {
            return true;
        }
        else{
            return false;
        }
    }
    if(abs(T.x-0)<epsilon) //P1 e P2 fanno un segmento verticale
    {
        m2=W.y/W.x;
        double x=P1.x;
        double y=Q.y-Q.x*m2+x*m2;
        class Point I(x,y);
        double dist1,dist2;
        dist1=distance(I,P1)+distance(I,P2); //ipotenusa
        dist2=distance(I,Q)+distance(I,P3);
        if(abs(dist1-distance(P1,P2))<epsilon && abs(dist2-distance(Q,P3))<epsilon) //mettiamo epsilon di errore di macchina (da mettere a tutte le verifiche che facciamo )
        {
            return true;
        }
        else{
            return false;
        }
    }
    if(abs(W.x-0)<epsilon) //Q e P3 fanno un segmento verticale
    {
        m1=T.y/T.x;
        double x=Q.x;
        double y=P1.y-P1.x*m1+x*m1;
        class Point I(x,y);
        double dist1,dist2;
        dist1=distance(I,P1)+distance(I,P2); //ipotenusa
        dist2=distance(I,Q)+distance(I,P3);
        if(abs(dist1-distance(P1,P2))<epsilon && abs(dist2-distance(Q,P3))<epsilon)
        {
            return true;
        }
        else{
            return false;
        }
    }
}

bool segmentValidTriangle(class Triangle** T,class Point& P1,class Point& Q) // true se non si intersecano, false se si intersecano
{
    class Point W;
    class Point Z;
    bool b=true; //impostiamo di base vero, se non è così lo cambiamo dopo in false
    W=(*T)->p1;
    Z=(*T)->p2;
    if(!(boxInter(W,Z,P1,Q)))
    {

     if(segmentInter(W,Z,P1,Q))
     {
         if(!(W.x==P1.x && W.y==P1.y) && !(Z.x==P1.x && Z.y==P1.y))
             {
                b=false; //false se si interseca
             }

     }
    }
    W=(*T)->p2;
    Z=(*T)->p3;
    if(!(boxInter(W,Z,P1,Q)))
    {
     if(segmentInter(W,Z,P1,Q))
     {
             if(!(W.x==P1.x && W.y==P1.y) && !(Z.x==P1.x && Z.y==P1.y))
             {
                b=false;
             }
         }

     }

    W=(*T)->p3;
    Z=(*T)->p1;
    if(!(boxInter(W,Z,P1,Q)))
    {
     if(segmentInter(W,Z,P1,Q))
     {
        // cout<<Z.x<<" //"<<P1.x<<endl;
         if(!(W.x==P1.x && W.y==P1.y) && !(Z.x==P1.x && Z.y==P1.y))
         {
             b=false;
         }
     }
    }
    //cout<<b<<endl;
    return b;
}


Triangle* creaTriaEst12(Triangle** head, class Point& Q)
{
    class Triangle* pT;
    pT=new Triangle((*head)->p1,(*head)->p2,Q); //creiamo nuovo triangolo, sappiamo solo che il lato p1 p2 è percorso in senso antiorario
    if((*head)->p1.id==Q.id || (*head)->p2.id==Q.id)
    {
        cout<<"ERRR"<<endl;
    }
    if(pT->p1.id==(*head)->p1.id)
    {
        pT->adj31=(*head);
    }
    if(pT->p1.id==Q.id)
    {
        pT->adj23=(*head);
    }
    (*head)->adj12=pT;
    return pT;
}

Triangle* creaTriaEst23(Triangle** head, class Point& Q)
{
    class Triangle* pT;
    pT=new Triangle((*head)->p2,(*head)->p3,Q); //creiamo nuovo triangolo, sappiamo solo che il lato p1 p2 è percorso in senso antiorario
    if((*head)->p3.id==Q.id || (*head)->p2.id==Q.id)
    {
        cout<<"ERRR"<<endl;
    }


    if(pT->p2.id==(*head)->p2.id)
    {
        pT->adj31=(*head);
    }
    if(pT->p2.id==(*head)->p2.id)
    {
        pT->adj12=(*head);
    }
    if(pT->p3.id==(*head)->p2.id) //vedere schemi su quaderno
    {
        pT->adj23=(*head);
    }
    (*head)->adj23=pT;
    return pT;
}

Triangle* creaTriaEst31(Triangle** head, class Point& Q)
{
    class Triangle* pT; //sempre usando standard di punto più vicino al centro
    pT=new Triangle((*head)->p1,(*head)->p3,Q); //creiamo nuovo triangolo, sappiamo solo che il lato p1 p2 è percorso in senso antiorario
    if((*head)->p1.id==Q.id || (*head)->p3.id==Q.id)
    {
        cout<<"ERRR"<<endl;
    }



    if(pT->p1.id==(*head)->p1.id)
    {
        pT->adj12=(*head);
    }
    if(pT->p1.id==Q.id)
    {
        pT->adj23=(*head);
    }
    (*head)->adj31=pT;
    return pT;
}

void puntoEsterno(class Triangle** head,class Point& Q) //ogni triangolo nuovo creato non potrà intersecare altri triangoli creati quindi non necessitiamo di controllarlo
{
    int n=0;
   // cout<<"INIZIO PUNTO ESTERNO"<<endl;
    list<Triangle*> coda;
    coda.push_back(*head);
    bool k=0; //partiamo da iteratore k=0;
    while(!(coda.empty()))
    {
        // cout<<"INIZIO while"<<endl;
       // cout<<"AA"<<endl;

        bool b12,b23,b31; //booleani che ci indicano se fare o meno il triangolo
        class Triangle* pT;
        std::list<class Triangle*>::iterator it = coda.begin(); //coda ordinata
        pT=*it;  //dà puntatore a elemento che è un puntatore a triangolo
        coda.pop_front(); //non diamo ordine particolare (aggiungeremo con push_back
        b12=(pT->adj12==nullptr); //true se è vuoto
        b23=(pT->adj23==nullptr);
        b31=(pT->adj31==nullptr);
       // cout<<"b12: "<<b12<<"// b23: "<<b23<<" //b31: "<<b31<<endl;



        bool bQ1=true,bQ2=true,bQ3=true; //valori booleani lati da controllare, li inizializziamo con true così poi iterando con gli e si parte dalla base true

        //1,1,1 valori bool
        if((b12 && b23 && b31) || (b12 && b23 && !(b31)) || (b12 && !(b23) && b31) || (!(b12) && b23 && b31)) //validazione segmenti
        {

            list<Triangle*> queque;
            queque.push_back(pT);
            while(!(queque.empty()))
            {
               // cout<<"IF1"<<endl;
                class Triangle* pointer;
                std::list<class Triangle*>::iterator it = queque.begin();
                pointer=*it;
                pointer->j=!k; //ci serve per identificare quando un triangolo è stato già visitato
                queque.pop_front();
                bQ1=bQ1*segmentValidTriangle(&pointer,pT->p1,Q);
                bQ2=bQ2*segmentValidTriangle(&pointer,pT->p2,Q);
                bQ3=bQ3*segmentValidTriangle(&pointer,pT->p3,Q);
               // cout<<"bQ1: "<<bQ1<<"// bQ2: "<<bQ2<<" //bQ3: "<<bQ3<<endl;



                if(!((pointer)->adj12==nullptr)){
                    if((pointer->adj12->j==k)) //ovvero non visitato
                    {

                        queque.push_back(pointer->adj12);
                    }

                }

                if(!((pointer)->adj23==nullptr)){
                    if((pointer->adj23->j==k)) //id devono essere diversi se sono uguali non è più importante verificare
                    {

                        queque.push_back(pointer->adj23);
                    }

                }

                if(!((pointer)->adj31==nullptr)){
                    if((pointer->adj31->j==k)){

                        queque.push_back(pointer->adj31);
                    }

                }


            } //finito il ciclo tutti quanti avranno j=!k

        }
        else if(b12 && !(b23) && !(b31))
        {

            list<Triangle*> queque;
            queque.push_back(pT);
            while(!(queque.empty()))
            {
                // cout<<"IF2"<<endl;
                class Triangle* pointer;
                std::list<class Triangle*>::iterator it = queque.begin();
                pointer=*it;
                pointer->j=!k; //ci serve per identificare quando un triangolo è stato già visitato
                queque.pop_front();
                bQ1=bQ1*segmentValidTriangle(&pointer,pT->p1,Q);
                bQ2=bQ2*segmentValidTriangle(&pointer,pT->p2,Q);




                if(!((pointer)->adj12==nullptr)){
                    if((pointer->adj12->j==k)) //ovvero non visitato
                    {
                        queque.push_back(pointer->adj12);
                    }

                }

                if(!((pointer)->adj23==nullptr)){
                    if((pointer->adj23->j==k)) //id devono essere diversi se sono uguali non è più importante verificare
                    {
                        queque.push_back(pointer->adj23);
                    }

                }

                if(!((pointer)->adj31==nullptr)){
                    if((pointer->adj31->j==k)){
                        queque.push_back(pointer->adj31);
                    }

                }


            } //finito il ciclo tutti quanti avranno j=!k

        }
        else if(!(b12) && b23 && !(b31))
        {

            list<Triangle*> queque;
            queque.push_back(pT);
            while(!(queque.empty()))
            {
                class Triangle* pointer;
                std::list<class Triangle*>::iterator it = queque.begin();
                //cout<<"valore segno: "<<k<<endl;

                pointer=*it;
                //cout<<"id punto 1: "<<(pointer->p1.id)<<" // id punto 2: "<<(pointer->p2.id)<<" // id punto 3: "<<(pointer->p3.id)<<endl;
                //cout<<"x punto 1: "<<(pointer->p1.x)<<" // x punto 2: "<<(pointer->p2.x)<<" // x punto 3: "<<(pointer->p3.x)<<endl;
                //cout<<"y punto 1: "<<(pointer->p1.y)<<" // y punto 2: "<<(pointer->p2.y)<<" // y punto 3: "<<(pointer->p3.y)<<endl;
                //cout<<"valore pointer: "<<pointer->j<<endl;
                pointer->j=!k; //ci serve per identificare quando un triangolo è stato già visitato
                //cout<<"valore pointer: "<<pointer->j<<endl;
                //cout<<"valore segno: "<<k<<endl;
                queque.pop_front();
                bQ2=bQ2*segmentValidTriangle(&pointer,pT->p2,Q);
                bQ3=bQ3*segmentValidTriangle(&pointer,pT->p3,Q);




                if(!((pointer)->adj12==nullptr)){
                    //cout<<"valore pointer adj12: "<<pointer->adj12->j<<endl;
                    if((pointer->adj12->j==k)) //ovvero non visitato
                    {
                        //cout<<"valore segno: "<<k<<endl;

                        queque.push_back(pointer->adj12);
                    }

                }

                if(!((pointer)->adj23==nullptr)){
                   // cout<<"valore pointer adj23: "<<pointer->adj23->j<<endl;
                    if((pointer->adj23->j==k)) //id devono essere diversi se sono uguali non è più importante verificare
                    {
                     //   cout<<"valore segno: "<<k<<endl;
                        queque.push_back(pointer->adj23);
                    }

                }

                if(!((pointer)->adj31==nullptr)){
                  //  cout<<"valore pointer adj31: "<<pointer->adj31->j<<endl;
                    if((pointer->adj31->j==k)){
                      //  cout<<"valore segno: "<<k<<endl;
                        queque.push_back(pointer->adj31);
                    }

                }

            } //finito il ciclo tutti quanti avranno j=!k


        }
        else if(!(b12) && !(b23) && (b31))
        {
            list<Triangle*> queque;
            queque.push_back(pT);
            while(!(queque.empty()))
            {
               // cout<<"IF4"<<endl;
                class Triangle* pointer;
                std::list<class Triangle*>::iterator it = queque.begin();
                pointer=*it;
                pointer->j=!k; //ci serve per identificare quando un triangolo è stato già visitato
                queque.pop_front(); //politica FIFO
                bQ1=bQ1*segmentValidTriangle(&pointer,pT->p1,Q);
                bQ3=bQ3*segmentValidTriangle(&pointer,pT->p3,Q);


                if(!((pointer)->adj12==nullptr)){
                    if((pointer->adj12->j==k)) //ovvero non visitato
                    {
                        queque.push_back(pointer->adj12);
                    }

                }

                if(!((pointer)->adj23==nullptr)){
                    if((pointer->adj23->j==k)) //id devono essere diversi se sono uguali non è più importante verificare
                    {
                        queque.push_back(pointer->adj23);
                    }

                }

                if(!((pointer)->adj31==nullptr)){
                    if((pointer->adj31->j==k)){
                        queque.push_back(pointer->adj31);
                    }

                }


            }
            }//finito il ciclo tutti quanti avranno j=!k
            else //caso (0,0,0) non si fa nulla
            {
               list<Triangle*> queque;
               queque.push_back(pT);
                while(!(queque.empty()))
               {

                class Triangle* pointer;
                std::list<class Triangle*>::iterator it = queque.begin();
                pointer=*it;
                pointer->j=!k; //ci serve per identificare quando un triangolo è stato già visitato
                queque.pop_front();




                if(!((pointer)->adj12==nullptr)){
                    if((pointer->adj12->j==k)) //ovvero non visitato
                    {
                        queque.push_back(pointer->adj12);
                    }

                }

                if(!((pointer)->adj23==nullptr)){
                    if((pointer->adj23->j==k)) //id devono essere diversi se sono uguali non è più importante verificare
                    {
                        queque.push_back(pointer->adj23);
                    }

                }

                if(!((pointer)->adj31==nullptr)){
                    if((pointer->adj31->j==k)){
                        queque.push_back(pointer->adj31);
                    }

                }


            } //finito il ciclo tutti quanti avranno j=!k

            }

        k=!k;


        if(!(pT->adj12==nullptr)){
            if(!(pT->adj12->eid==Q.id)){
                coda.push_back((pT)->adj12);
            }

        }


        if(!(pT->adj23==nullptr)){
            if(!(pT->adj23->eid==Q.id)){
                coda.push_back((pT)->adj23);
            }

        }


        if(!(pT->adj31==nullptr)){
            if(!(pT->adj31->eid==Q.id)){
                coda.push_back((pT)->adj31);
            }
        }

        if(b12 && bQ1 && bQ2)
        {
         //   cout<<"noo"<<endl;
            class Triangle* puntatore=creaTriaEst12(&pT,Q);
            pT->adj12=puntatore;
        }
        if(b23 && bQ2 && bQ3)
        {

            class Triangle* puntatore=creaTriaEst23(&pT,Q);
            pT->adj23=puntatore;
        }
        if(b31 && bQ1 && bQ3)
        {

            class Triangle* puntatore=creaTriaEst31(&pT,Q);
            pT->adj31=puntatore;
        }

        pT->eid=Q.id;
        // cout<<"eid: "<<pT->eid<<endl;



        }




    //int s=10;
    //stampaTriangoli(head,s);
    return;
}

//FINE PUNTO ESTERNO

//VERFICA CONDIZIONE FLIP DELUNAY

void flip(class Triangle** head,class Triangle** pT,bool b,bool d) //usata quando già sappiamo di dover fare il filp, l booleano che indica la vista
{
    class Triangle* pH;
    class Triangle* ppT;
    class Point A; class Point B;  class Point C; class Point D;
    int param=0;



    //somma indici punti è sempre uguale a 3 quindi conosciuti i primi due abbiamo automaticamente il terzo
    int t11=0, t12=0, t21=0, t22=0, t13=0, t23=0;  //t11, t12,t21,t22 danno punti in comune
    (*head)->pointEqTrian(*pT,t11,t12,t21,t22); //chiamiamo metodo
    t13=6-(t11+t12); //t13 punto che non si interseca
    t23=6-(t21+t22);

    if(t13==1)
    {
        A=(*head)->p1;
    }
    if(t13==2)
    {
        A=(*head)->p2;
    }
    if(t13==3)
    {
        A=(*head)->p3;
    }

    if(t23==1)
    {
        B=(*pT)->p1;
    }
    if(t23==2)
    {
        B=(*pT)->p2;
    }
    if(t23==3)
    {
        B=(*pT)->p3;
    }

    if(t11==1)
    {
        C=(*head)->p1;
    }
    if(t11==2)
    {
        C=(*head)->p2;
    }
    if(t11==3)
    {
        C=(*head)->p3;
    }

    if(t12==1)
    {
        D=(*head)->p1;
    }
    if(t12==2)
    {
        D=(*head)->p2;
    }
    if(t12==3)
    {
        D=(*head)->p3;
    }

    pH=new Triangle(A,B,C);
    ppT=new Triangle(A,B,D); //creiamo i due triangoli dobbiamo sistemare le adiacenze


    (*head)->pointEqTrian(pH,t11,t12,t21,t22); //con head condivide A e C  t21 t22 danno adiacenza di pH (da che lato sta adiacenza) t11 e t12 danno punto di adiacenza
    param=t21+t12;

    if((t11==1 && t12==2) || (t12==1 && t11==2))
    {
        switch(param){
        case 3:
        {
            pH->adj12=(*head)->adj12;
            break;
        }
        case 4:
        {
            pH->adj31=(*head)->adj12;
            break;
        }
        case 5:
        {
            pH->adj23=(*head)->adj12;
            break;
        }
        }
        if(!((*head)->adj12==nullptr)){
        (*head)->adj12->pointEqTrian(pH,t11,t12,t21,t22);
        param=t11+t12;
        switch(param){
        case 3:
        {
            (*head)->adj12->adj12=pH;
            break;
        }
        case 4:
        {
            (*head)->adj12->adj31=pH;
            break;
        }
        case 5:
        {
            (*head)->adj12->adj23=pH;
            break;
        }
        default:
            break;
        }
        }

    }

    if((t11==2 && t12==3) || (t12==2 && t11==3))
    {
        switch(param){
        case 3:
        {
            pH->adj12=(*head)->adj23;
            break;
        }
        case 4:
        {
            pH->adj31=(*head)->adj23;
            break;
        }
        case 5:
        {
            pH->adj23=(*head)->adj23;
            break;
        }
        }

        if(!((*head)->adj23==nullptr)){
        (*head)->adj23->pointEqTrian(pH,t11,t12,t21,t22);
        param=t11+t12;

        switch(param){
        case 3:
        {
            (*head)->adj23->adj12=pH;
            break;
        }
        case 4:
        {
            (*head)->adj23->adj31=pH;
            break;
        }
        case 5:
        {
            (*head)->adj23->adj23=pH;
            break;
        }
        default:
            break;
        }
        }

    }

    if((t11==3 && t12==1) || (t12==3 && t11==1))
    {
        switch(param){
        case 3:
        {
            pH->adj12=(*head)->adj31;
            break;
        }
        case 4:
        {
            pH->adj31=(*head)->adj31;
            break;
        }
        case 5:
        {
            pH->adj23=(*head)->adj31;
            break;
        }
        }
        if(!((*head)->adj31==nullptr)){
        (*head)->adj31->pointEqTrian(pH,t11,t12,t21,t22);
        param=t11+t12;
        switch(param){
        case 3:
        {
            (*head)->adj31->adj12=pH;
            break;
        }
        case 4:
        {
            (*head)->adj31->adj31=pH;
            break;
        }
        case 5:
        {
            (*head)->adj31->adj23=pH;
            break;
        }
        default:
            break;
        }
        }

    }



    (*head)->pointEqTrian(ppT,t11,t12,t21,t22); //con head condivide A e C  t21 t22 danno adiacenza di pH (da che lato sta adiacenza) t11 e t12 danno punto di adiacenza
    param=t21+t12;

    if((t11==1 && t12==2) || (t12==1 && t11==2))
    {
        switch(param){
        case 3:
        {
            ppT->adj12=(*head)->adj12;
            break;
        }
        case 4:
        {
            ppT->adj31=(*head)->adj12;
            break;
        }
        case 5:
        {
            ppT->adj23=(*head)->adj12;
            break;
        }
        }
        if(!((*head)->adj12==nullptr)){
        (*head)->adj12->pointEqTrian(ppT,t11,t12,t21,t22);
        param=t11+t12;
        switch(param){
        case 3:
        {
            (*head)->adj12->adj12=ppT;
            break;
        }
        case 4:
        {
            (*head)->adj12->adj31=ppT;
            break;
        }
        case 5:
        {
            (*head)->adj12->adj23=ppT;
            break;
        }
        default:
            break;
        }
        }

    }

    if((t11==2 && t12==3) || (t12==2 && t11==3))
    {
        switch(param){
        case 3:
        {
            ppT->adj12=(*head)->adj23;
            break;
        }
        case 4:
        {
            ppT->adj31=(*head)->adj23;
            break;
        }
        case 5:
        {
            ppT->adj23=(*head)->adj23;
            break;
        }
        }

        if(!((*head)->adj23==nullptr)){
        (*head)->adj23->pointEqTrian(ppT,t11,t12,t21,t22);
        param=t11+t12;

        switch(param){
        case 3:
        {
            (*head)->adj23->adj12=ppT;
            break;
        }
        case 4:
        {
            (*head)->adj23->adj31=ppT;
            break;
        }
        case 5:
        {
            (*head)->adj23->adj23=ppT;
            break;
        }
        default:
            break;
        }
        }

    }

    if((t11==3 && t12==1) || (t12==3 && t11==1))
    {
        switch(param){
        case 3:
        {
            ppT->adj12=(*head)->adj31;
            break;
        }
        case 4:
        {
            ppT->adj31=(*head)->adj31;
            break;
        }
        case 5:
        {
            ppT->adj23=(*head)->adj31;
            break;
        }
        }

        if(!((*head)->adj31==nullptr)){
        (*head)->adj31->pointEqTrian(ppT,t11,t12,t21,t22);
        param=t11+t12;
        switch(param){
        case 3:
        {
            (*head)->adj31->adj12=ppT;
            break;
        }
        case 4:
        {
            (*head)->adj31->adj31=ppT;
            break;
        }
        case 5:
        {
            (*head)->adj31->adj23=ppT;
            break;
        }
        default:
            break;
        }
        }

    }


    (*pT)->pointEqTrian(pH,t11,t12,t21,t22); //con head condivide A e C  t21 t22 danno adiacenza di pH (da che lato sta adiacenza) t11 e t12 danno punto di adiacenza
    param=t21+t12;

    if((t11==1 && t12==2) || (t12==1 && t11==2))
    {
        switch(param){
        case 3:
        {
            pH->adj12=(*pT)->adj12;
            break;
        }
        case 4:
        {
            pH->adj31=(*pT)->adj12;
            break;
        }
        case 5:
        {
            pH->adj23=(*pT)->adj12;
            break;
        }
        }
        if(!((*pT)->adj12==nullptr)){
        (*pT)->adj12->pointEqTrian(pH,t11,t12,t21,t22);
        param=t11+t12;
        switch(param){
        case 3:
        {
            (*pT)->adj12->adj12=pH;
            break;
        }
        case 4:
        {
            (*pT)->adj12->adj31=pH;
            break;
        }
        case 5:
        {
            (*pT)->adj12->adj23=pH;
            break;
        }
        default:
            break;
        }
        }

    }

    if((t11==2 && t12==3) || (t12==2 && t11==3))
    {
        switch(param){
        case 3:
        {
            pH->adj12=(*pT)->adj23;
            break;
        }
        case 4:
        {
            pH->adj31=(*pT)->adj23;
            break;
        }
        case 5:
        {
            pH->adj23=(*pT)->adj23;
            break;
        }
        }
        if(!((*head)->adj23==nullptr)){
        (*pT)->adj23->pointEqTrian(pH,t11,t12,t21,t22);
        param=t11+t12;

        switch(param){
        case 3:
        {
            (*pT)->adj23->adj12=pH;
            break;
        }
        case 4:
        {
            (*pT)->adj23->adj31=pH;
            break;
        }
        case 5:
        {
            (*pT)->adj23->adj23=pH;
            break;
        }
        default:
            break;
        }
        }
    }

    if((t11==3 && t12==1) || (t12==3 && t11==1))
    {
        switch(param){
        case 3:
        {
            pH->adj12=(*pT)->adj31;
            break;
        }
        case 4:
        {
            pH->adj31=(*pT)->adj31;
            break;
        }
        case 5:
        {
            pH->adj23=(*pT)->adj31;
            break;
        }
        }
        if(!((*pT)->adj31==nullptr)){
        (*pT)->adj31->pointEqTrian(pH,t11,t12,t21,t22);
        param=t11+t12;
        switch(param){
        case 3:
        {
            (*pT)->adj31->adj12=pH;
            break;
        }
        case 4:
        {
            (*pT)->adj31->adj31=pH;
            break;
        }
        case 5:
        {
            (*pT)->adj31->adj23=pH;
            break;
        }
        default:
            break;
        }
        }

    }


    (*pT)->pointEqTrian(ppT,t11,t12,t21,t22); //con head condivide A e C  t21 t22 danno adiacenza di pH (da che lato sta adiacenza) t11 e t12 danno punto di adiacenza
    param=t21+t12;

    if((t11==1 && t12==2) || (t12==1 && t11==2))
    {
        switch(param){
        case 3:
        {
            ppT->adj12=(*pT)->adj12;
            break;
        }
        case 4:
        {
            ppT->adj31=(*pT)->adj12;
            break;
        }
        case 5:
        {
            ppT->adj23=(*pT)->adj12;
            break;
        }
        }
        if(!((*pT)->adj12==nullptr)){
        (*pT)->adj12->pointEqTrian(ppT,t11,t12,t21,t22);
        param=t11+t12;
        switch(param){
        case 3:
        {
            (*pT)->adj12->adj12=ppT;
            break;
        }
        case 4:
        {
            (*pT)->adj12->adj31=ppT;
            break;
        }
        case 5:
        {
            (*pT)->adj12->adj23=ppT;
            break;
        }
        default:
            break;
        }
        }

    }

    if((t11==2 && t12==3) || (t12==2 && t11==3))
    {
        switch(param){
        case 3:
        {
            ppT->adj12=(*pT)->adj23;
            break;
        }
        case 4:
        {
            ppT->adj31=(*pT)->adj23;
            break;
        }
        case 5:
        {
            ppT->adj23=(*pT)->adj23;
            break;
        }
        }

        if(!((*pT)->adj23==nullptr)){
        (*pT)->adj23->pointEqTrian(ppT,t11,t12,t21,t22);
        param=t11+t12;

        switch(param){
        case 3:
        {
            (*pT)->adj23->adj12=ppT;
            break;
        }
        case 4:
        {
            (*pT)->adj23->adj31=ppT;
            break;
        }
        case 5:
        {
            (*pT)->adj23->adj23=ppT;
            break;
        }
        default:
            break;
        }
        }


    }

    if((t11==3 && t12==1) || (t12==3 && t11==1))
    {
        switch(param){
        case 3:
        {
            ppT->adj12=(*pT)->adj31;
            break;
        }
        case 4:
        {
            ppT->adj31=(*pT)->adj31;
            break;
        }
        case 5:
        {
            ppT->adj23=(*pT)->adj31;
            break;
        }
        }
        if(!((*pT)->adj31==nullptr)){
        (*pT)->adj31->pointEqTrian(ppT,t11,t12,t21,t22);
        param=t11+t12;
        switch(param){
        case 3:
        {
            (*pT)->adj31->adj12=ppT;
            break;
        }
        case 4:
        {
            (*pT)->adj31->adj31=ppT;
            break;
        }
        case 5:
        {
            (*pT)->adj31->adj23=ppT;
            break;
        }
        default:
            break;
        }
        }

    }


    pH->pointEqTrian(ppT,t11,t12,t21,t22); //mi calcolo punti in cui abbiamo ugulianza


    if((t11==1 && t12==2) || (t12==1 && t11==2))
    {
        pH->adj12=ppT;
    }
    if((t11==1 && t12==3) || (t12==1 && t11==3))
    {
        pH->adj31=ppT;
    }
    if((t11==3 && t12==2) || (t12==3 && t11==2))
    {
        pH->adj23=ppT;
    }

    if((t21==1 && t22==2) || (t22==1 && t21==2))
    {
        ppT->adj12=pH;
    }
    if((t21==1 && t22==3) || (t22==1 && t21==3))
    {
        ppT->adj31=pH;
    }
    if((t21==3 && t22==2) || (t22==3 && 21==2))
    {
        ppT->adj23=pH;
    }


    pH->l=d; //posto come non visitato
    ppT->l=d;

    //delete *pT; //eliminiamo triangoli vecchi
    //delete *head;


    if(b==1)
    {
        (*pT)=ppT;
        (*head)=pH;  //se è la testa del grafo lo facciamo puntare ad ad uno dei nuovi triangoli altrimenti se era un puntatore di adiacenza non c'è ne facciamo più nulla
    }







}

bool delunayCondition(class Point& A, class Point& B, class Point& C, class Point& D, Point &E, Point &F) //false se non è rispettata
{ //A,B lati con cui fare triangolo con lato di vertice C
    double teta1, teta2;
    double epsilon=1e-6;
    class Point P1; class Point P2;
    class Point Q1; class Point Q2;
    P1=A-C; P2=B-C;
    Q1=D-F; Q2=E-F;
    P1.normalization(); P2.normalization(); // angolo starà tra 0 e pi;
    Q1.normalization(); Q2.normalization();
    teta1=dotPoint(P1,P2);
    teta2=dotPoint(Q1,Q2);
    teta1=acos(teta1);
    teta2=acos(teta2);
    if(teta1+teta2-M_PI>-epsilon)
    {
        return false;
    }
    if(teta1+teta2-M_PI<epsilon)
    {
        return true;
    }
}

void verificaDelunay2(class Triangle **head)
{
    cout<<"Delunay"<<endl;
    list<class Triangle*> coda;
    coda.push_back((*head));
    class Triangle* T1;
    class Triangle* T2;
    bool k=0; //inizializziamo l'indice di visita a 0, come iniziallizzato in triangoli con costruttori
    T1=(*head);
    bool c=0,h=1;
    while(h==1){
    h=0;
    coda.push_back((*head));

    if(!(T1->adj12==nullptr))
    {
      T2=T1->adj12;
      int t11=0, t12=0, t21=0, t22=0, t13=0, t23=0;
      T1->pointEqTrian(T2,t11,t12,t21,t22);
      int param1=t11+t12, param2=t21+t22;
      switch(param1)
      {
       case 3: //t11+t12=2
      {
         switch(param2)
         {

         case 3:
        {
            c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p2,T2->p3);
            break;
        }
         case 4:
        {

            c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p3,T2->p2);
            break;
        }
         case 5:
        {
            c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p3,T2->p2,T2->p1);
            break;
        }

         }
         break;
      }

      case 4: //t11+t12=4
     {
        switch(param2)
        {

        case 3:
       {
           c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p2,T2->p3);
           break;
       }
        case 4:
       {
           c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p3,T2->p2);
           break;
       }
        case 5:
       {
           c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p3,T2->p2,T2->p1);
           break;
       }

        }
        break;
     }
      case 5: //t11+t12=5
     {
        switch(param2)
        {

        case 3:
       {
           c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p2,T2->p3);
           break;
       }
        case 4:
       {
           c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p3,T2->p2);
           break;
       }
        case 5:
       {
           c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p3,T2->p2,T2->p1);
           break;
       }

        }
        break;
     }

      }

      if(!c)
      {

        flip(head,&T2,1,!k);
        h=1;
      }

    }


    if(!(T1->adj23==nullptr))
    {
      T2=T1->adj23;
      int t11=0, t12=0, t21=0, t22=0, t13=0, t23=0;
      T1->pointEqTrian(T2,t11,t12,t21,t22);
      int param1=t11+t12, param2=t21+t22;
      switch(param1)
      {
       case 3: //t11+t12=2
      {
         switch(param2)
         {

         case 3:
        {
            c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p2,T2->p3);
            break;
        }
         case 4:
        {
            c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p3,T2->p2);
            break;
        }
         case 5:
        {
            c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p3,T2->p2,T2->p1);
            break;
        }

         }
         break;
      }

      case 4: //t11+t12=4
     {
        switch(param2)
        {

        case 3:
       {
           c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p2,T2->p3);
           break;
       }
        case 4:
       {
           c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p3,T2->p2);
           break;
       }
        case 5:
       {
           c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p3,T2->p2,T2->p1);
           break;
       }

        }
        break;
     }
      case 5: //t11+t12=5
     {
        switch(param2)
        {

        case 3:
       {
           c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p2,T2->p3);
           break;
       }
        case 4:
       {
           c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p3,T2->p2);
           break;
       }
        case 5:
       {
           c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p3,T2->p2,T2->p1);
           break;
       }

        }
        break;
     }

      }

      if(!c)
      {
        flip(head,&T2,1,!k);
        h=1;
      }

    }

    if(!(T1->adj31==nullptr))
    {
      T2=T1->adj31;
      int t11=0, t12=0, t21=0, t22=0, t13=0, t23=0;
      T1->pointEqTrian(T2,t11,t12,t21,t22);
      cout<<t11<<t12;
      int param1=t11+t12, param2=t21+t22;
      switch(param1)
      {
       case 3: //t11+t12=2
      {
         switch(param2)
         {

         case 3:
        {
            c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p2,T2->p3);
            break;
        }
         case 4:
        {
            c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p3,T2->p2);
            break;
        }
         case 5:
        {
            c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p3,T2->p2,T2->p1);
            break;
        }

         }
         break;
      }

      case 4: //t11+t12=4
     {
        switch(param2)
        {

        case 3:
       {
           c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p2,T2->p3);
           break;
       }
        case 4:
       {
           c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p3,T2->p2);
           break;
       }
        case 5:
       {
           c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p3,T2->p2,T2->p1);
           break;
       }

        }
        break;
     }
      case 5: //t11+t12=5
     {
        switch(param2)
        {

        case 3:
       {
           c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p2,T2->p3);
           break;
       }
        case 4:
       {
           c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p3,T2->p2);
           break;
       }
        case 5:
       {
           c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p3,T2->p2,T2->p1);
           break;
       }

        }
        break;
     }

      }

      if(!c)
      {
        flip(head,&T2,1,!k); //continuiamo a controllare i triangoli flippati
        h=1;
      }

    }


    coda.pop_front(); //da push_back segue pop_fronto politica FIFO

    (*head)->l=!k;

    if(!((*head)->adj12==nullptr))
    {
       coda.push_back((*head)->adj12);
    }
    if(!((*head)->adj23==nullptr))
    {
       coda.push_back((*head)->adj23);
    }
    if(!((*head)->adj31==nullptr))
    {
       coda.push_back((*head)->adj31);
    }

    while(!coda.empty())
    {
        std::list<class Triangle*>::iterator it = coda.begin(); //coda ordinata
        T1=*it;
        coda.pop_front();

        if(!(T1->adj12==nullptr))
        {
          T2=T1->adj12;
          int t11=0, t12=0, t21=0, t22=0, t13=0, t23=0;
          T1->pointEqTrian(T2,t11,t12,t21,t22);
          int param1=t11+t12, param2=t21+t22;
          switch(param1)
          {
           case 3: //t11+t12=2
          {
             switch(param2)
             {

             case 3:
            {
                c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p2,T2->p3);
                break;
            }
             case 4:
            {
                c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p3,T2->p2);
                break;
            }
             case 5:
            {
                c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p3,T2->p2,T2->p1);
                break;
            }

             }
             break;
          }

          case 4: //t11+t12=4
         {
            switch(param2)
            {

            case 3:
           {
               c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p2,T2->p3);
               break;
           }
            case 4:
           {
               c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p3,T2->p2);
               break;
           }
            case 5:
           {
               c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p3,T2->p2,T2->p1);
               break;
           }

            }
            break;
         }
          case 5: //t11+t12=5
         {
            switch(param2)
            {

            case 3:
           {
               c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p2,T2->p3);
               break;
           }
            case 4:
           {
               c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p3,T2->p2);
               break;
           }
            case 5:
           {
               c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p3,T2->p2,T2->p1);
               break;
           }

            }
            break;
         }

          }

          if(!c)
          {
            flip(&T1,&T2,0,1);
            h=1;
          }

        }

        if(!(T1->adj23==nullptr))
        {
          T2=T1->adj23;
          int t11=0, t12=0, t21=0, t22=0, t13=0, t23=0;
          T1->pointEqTrian(T2,t11,t12,t21,t22);
          int param1=t11+t12, param2=t21+t22;
          switch(param1)
          {
           case 3: //t11+t12=2
          {
             switch(param2)
             {

             case 3:
            {
                c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p2,T2->p3);
                break;
            }
             case 4:
            {
                c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p3,T2->p2);
                break;
            }
             case 5:
            {
                c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p3,T2->p2,T2->p1);
                break;
            }

             }
             break;
          }

          case 4: //t11+t12=4
         {
            switch(param2)
            {

            case 3:
           {
               c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p2,T2->p3);
               break;
           }
            case 4:
           {
               c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p3,T2->p2);
               break;
           }
            case 5:
           {
               c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p3,T2->p2,T2->p1);
               break;
           }

            }
            break;
         }
          case 5: //t11+t12=5
         {
            switch(param2)
            {

            case 3:
           {
               c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p2,T2->p3);
               break;
           }
            case 4:
           {
               c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p3,T2->p2);
               break;
           }
            case 5:
           {
               c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p3,T2->p2,T2->p1);
               break;
           }

            }
            break;
         }

          }

          if(!c)
          {
            flip(&T1,&T2,0,1);
            h=1;
          }

        }

        if(!(T1->adj31==nullptr))
        {
          T2=T1->adj31;
          int t11=0, t12=0, t21=0, t22=0, t13=0, t23=0;
          T1->pointEqTrian(T2,t11,t12,t21,t22);
          int param1=t11+t12, param2=t21+t22;
          switch(param1)
          {
           case 3: //t11+t12=2
          {
             switch(param2)
             {

             case 3:
            {
                c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p2,T2->p3);
                break;
            }
             case 4:
            {
                c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p1,T2->p3,T2->p2);
                break;
            }
             case 5:
            {
                c=delunayCondition(T1->p1,T1->p2,T1->p3,T2->p3,T2->p2,T2->p1);
                break;
            }

             }
             break;
          }

          case 4: //t11+t12=4
         {
            switch(param2)
            {

            case 3:
           {
               c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p2,T2->p3);
               break;
           }
            case 4:
           {
               c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p1,T2->p3,T2->p2);
               break;
           }
            case 5:
           {
               c=delunayCondition(T1->p1,T1->p3,T1->p2,T2->p3,T2->p2,T2->p1);
               break;
           }

            }
            break;
         }
          case 5: //t11+t12=5
         {
            switch(param2)
            {

            case 3:
           {
               c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p2,T2->p3);
               break;
           }
            case 4:
           {
               c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p1,T2->p3,T2->p2);
               break;
           }
            case 5:
           {
               c=delunayCondition(T1->p3,T1->p2,T1->p1,T2->p3,T2->p2,T2->p1);
               break;
           }

            }
            break;
         }

          }

          if(!c)
          {
            flip(&T1,&T2,0,1);
            h=1;
          }

        }

        if(!(T1->adj12==nullptr))
        {
            if(T1->adj12->l==k){
                coda.push_back(T1->adj12);
            }

        }
        if(!((T1->adj23==nullptr)))
     {

            if(T1->adj23->l==k){
                coda.push_back(T1->adj23);
            }
        }
        if(!((T1->adj31==nullptr)))
        {
            if(T1->adj31->l==k){
                coda.push_back(T1->adj31);
            }
        }T1->l=!k;
    }

    k=!k;
    }




}

void stampaTriangoli(class Triangle** head)
{

    int n=0;
    s++;
    list<class Triangle*> coda;
    class Triangle* T1;
    coda.push_back((*head));
    class Triangle* pointer;
    while(!coda.empty())
    {
        std::list<class Triangle*>::iterator it = coda.begin(); //coda ordinata
        T1=*it;
        coda.pop_front();
        T1->rid=s;
        pointer=T1;

        cout<<"Triangolo numero: "<<n<<endl;
        cout<<"id punto 1: "<<(pointer->p1.id)<<" // x punto 1: "<<(pointer->p1.x)<<" // y punto 1: "<<(pointer->p1.y)<<endl;
        cout<<"id punto 2: "<<(pointer->p2.id)<<" // x punto 2: "<<(pointer->p2.x)<<" // y punto 2: "<<(pointer->p2.y)<<endl;
        cout<<"id punto 3: "<<(pointer->p3.id)<<" // x punto 3: "<<(pointer->p3.x)<<" // y punto 3: "<<(pointer->p3.y)<<endl;
        n++;

        if(!((T1->adj12)==nullptr))
        {

            if(!(T1->adj12->rid==s))
            {

                coda.push_back(T1->adj12);
            }
        }
        if(!((T1->adj23)==nullptr))
        {

            if(!(T1->adj23->rid==s))
            {
                coda.push_back(T1->adj23);
            }
        }
        if(!((T1->adj31)==nullptr))
        {
            if(!(T1->adj31->rid==s))
            {
                coda.push_back(T1->adj31);
            }
        }
    }
}

void miniVerifica(Triangle **head,bool f,int& h)
{
    bool z;
    if(!((*head)->adj12==nullptr))
    {
        int a=0,b=0,c=0,d=0;
        (*head)->pointEqTrian((*head)->adj12,a,b,c,d);
        if(c+d==3)
        {
            if(!delunayCondition((*head)->p1,(*head)->p2,(*head)->p3,(*head)->adj12->p1,(*head)->adj12->p2,(*head)->adj12->p3))
            {
                    flip(head,&((*head)->adj12),1,f);
                    h=1;
            return; }
        }
        if(c+d==4)
        {
            if(!delunayCondition((*head)->p1,(*head)->p2,(*head)->p3,(*head)->adj12->p1,(*head)->adj12->p3,(*head)->adj12->p2))
            {
                    flip(head,&((*head)->adj12),1,f);
                    h=1;
            return; }
        }
        if(c+d==5)
        {
            if(!delunayCondition((*head)->p1,(*head)->p2,(*head)->p3,(*head)->adj12->p3,(*head)->adj12->p2,(*head)->adj12->p1))
            {
                    flip(head,&((*head)->adj12),1,f);
                    h=1;
            return; }
        }
    }
    if(!((*head)->adj23==nullptr))
    {
        int a=0,b=0,c=0,d=0;
        (*head)->pointEqTrian((*head)->adj23,a,b,c,d);
        if(c+d==3)
        {

            if(!delunayCondition((*head)->p3,(*head)->p2,(*head)->p1,(*head)->adj23->p1,(*head)->adj23->p2,(*head)->adj23->p3))
            {
                    flip(head,&((*head)->adj23),1,f);
                    h=1;
            return; }
        }
        if(c+d==4)
        {

            if(!delunayCondition((*head)->p3,(*head)->p2,(*head)->p1,(*head)->adj23->p1,(*head)->adj23->p3,(*head)->adj23->p2))
            {
                    flip(head,&((*head)->adj23),1,f);
                    h=1;
            return; }
        }
        if(c+d==5)
        {
            if(!delunayCondition((*head)->p3,(*head)->p2,(*head)->p1,(*head)->adj23->p3,(*head)->adj23->p2,(*head)->adj23->p1))
            {
                    flip(head,&((*head)->adj23),1,f);
                    h=1;
            return; }
        }
    }
    if(!((*head)->adj31==nullptr))
    {

        int a=0,b=0,c=0,d=0;
        (*head)->pointEqTrian((*head)->adj31,a,b,c,d);
        cout<<c+d;
        if(c+d==3)
        {
            if(!delunayCondition((*head)->p3,(*head)->p1,(*head)->p2,(*head)->adj31->p1,(*head)->adj31->p2,(*head)->adj31->p3))
            {
                    flip(head,&((*head)->adj31),1,f);
                    h=1;
            return; }
        }
        if(c+d==4)
        {
            if(!delunayCondition((*head)->p3,(*head)->p1,(*head)->p2,(*head)->adj31->p1,(*head)->adj31->p3,(*head)->adj31->p2))
            {
                    flip(head,&((*head)->adj31),1,f);
                    h=1;
            return; }
        }
        if(c+d==5)
        {

            if(!delunayCondition((*head)->p3,(*head)->p1,(*head)->p2,(*head)->adj31->p3,(*head)->adj31->p2,(*head)->adj31->p1))
            {

                    flip(head,&((*head)->adj31),1,f);
                    h=1;
            return; }
        }
    }
    (*head)->index=!f;
    return;
}

void verificaDelunay1(Triangle **head)
{

    bool b=0;
    int h=1;
    list<class Triangle*> coda;
    coda.push_front(*head);
    int n=0;
    while(h==1)
    {
        if(n==20){break; }
        h=0;
        class Triangle* pointer;
        std::list<class Triangle*>::iterator it = coda.begin();
        pointer=*it;
        pointer->index=!b;
        cout<<"b: "<<b<<endl;
        cout<<pointer->index<<endl;

        miniVerifica(&pointer,b,h);
        (*head)=pointer;
        cout<<pointer->index<<endl;

        if(!(pointer->adj12==nullptr))
        {
            if(pointer->adj12->index==b)
            {
                coda.push_back(pointer->adj12);
            }
        }
        if(!(pointer->adj23==nullptr))
        {
            if(pointer->adj23->index==b)
            {
                coda.push_back(pointer->adj23);

            }
        }
        if(!(pointer->adj31==nullptr))
        {
            if(pointer->adj31->index==b)
            {
                coda.push_back(pointer->adj31);
            }
        }

        if(coda.empty())
        {
         coda.push_back(*head);
         b=!b;
         cout<<endl<<endl<<endl;
        }


       // stampaTriangoli(head);
        n++;

    }



        return;


    }

}


