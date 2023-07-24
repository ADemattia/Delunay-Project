#ifndef __TEST_EMPTY_H
#define __TEST_EMPTY_H

#include <gtest/gtest.h>

#include "empty_class.hpp"

using namespace testing;

TEST(TestPoint, TestVettore)
{
  ProjectLibrary::Point p1(2,1);
  ProjectLibrary::Point p2(5,3);
  ProjectLibrary::Point p3(p2-p1); //ottenuto con costruttore copia
  EXPECT_EQ(p3.Show(),"Coordinata x: 3.000000, Cordinata y: 2.000000");//EXPECTED_EQ ci dà true se ciò che si aspettava è effettivamente successo
}

TEST(TestTriangle, TestCounterClockwise)
{
  ProjectLibrary::Point A(1,2);
  ProjectLibrary::Point B(0,0);
  ProjectLibrary::Point C(4,4);
  ProjectLibrary::Triangle Try(A,B,C);

  EXPECT_TRUE(Try.p1.x==0 && Try.p1.y==0 && Try.p2.x==4 && Try.p3.x==1);
}

TEST(TestPoint, TestArea) //verifica se funziona funzione area
{
  ProjectLibrary::Point A(1,5);
  ProjectLibrary::Point B(4,5);
  ProjectLibrary::Point C(6,0);

  EXPECT_EQ(ProjectLibrary::Area(A,B,C),7.5);
}

TEST(TestPoint, TestOrdinamento1)
{

  double arrayx[10]={2.5,-1.8,0.0,5.3,3.1,-4.2,1.9,4.0,-2.7,1.2};
  double arrayy[10]={3.7,4.2,-2.1,-0.9,1.6,2.0,-5.5,0.3,3.9,1.5};
  vector<ProjectLibrary::Point> V;
  for(int i=0;i<10;i++)
  {
   ProjectLibrary::Point P(arrayx[i],arrayy[i]);
   V.push_back(P);
  }

  ProjectLibrary::Point G=ProjectLibrary::findMin(V);
  EXPECT_EQ(G.y,-5.5);
}

TEST(TestPoint, TestOrdinamento2)
{

  double arrayx[10]={2.5,-1.8,0.0,5.3,3.1,-4.2,1.9,4.0,-2.7,1.2};
  double arrayy[10]={3.7,4.2,-2.1,-0.9,1.6,2.0,-5.5,0.3,3.9,1.5};
  vector<ProjectLibrary::Point> V;
  for(int i=0;i<10;i++)
  {
   ProjectLibrary::Point P(arrayx[i],arrayy[i]);
   V.push_back(P);
  }

  ProjectLibrary::Point G=ProjectLibrary::findMin(V); //findMin va anche a modificare Array
  ProjectLibrary::polarSort(V,G);
  EXPECT_TRUE(V[0].x==5.3);
}

TEST(TestConvexHull, TestConvx1)
{
   // Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
     //                     {0, 0}, {1, 2}, {3, 1}, {3, 3}};

  double arrayx[8]={0,1,2,4,0,1,3,3}; //(0, 0),(3, 1),(4, 4),(0, 3)
  double arrayy[8]={3,1,2,4,0,2,1,3};
  vector<ProjectLibrary::Point> V;
  for(int i=0;i<8;i++)
  {
   ProjectLibrary::Point P(arrayx[i],arrayy[i]);
   V.push_back(P);
  }

  ProjectLibrary::Point G=ProjectLibrary::findMin(V); //findMin va anche a modificare Array
  ProjectLibrary::polarSort(V,G);
  list<ProjectLibrary::Point> lista=ProjectLibrary::convexHull(V,G);
  cout<<"lista"<<endl;
  cout<<lista.begin()->id<<endl;
  std::list<ProjectLibrary::Point>::iterator it = lista.end();
  for (it = lista.begin(); it != lista.end(); ++it) {
          std::cout << it->id << " ";
      }
  EXPECT_TRUE(lista.begin()->id==0); //da aggiustare il test
}

TEST(TestMaxArea , TestMaxArea1)
{
   // Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4},
     //                     {0, 0}, {1, 2}, {3, 1}, {3, 3}};

  double epsilon=1e-6;
  double arrayx[15]={9,1,8.98,6,7.18,7.76,4.36,4.08,5.48,6.79,7.87,8.17,6.3,6.2,5.26};
  double arrayy[15]={8,1,2.61,4,4.77,3.88,2.5,3.84,4.75,6.05,5.95,4.8,3.5,2.48,2.87};
  vector<ProjectLibrary::Point> V;
  for(int i=0;i<15;i++)
  {
   ProjectLibrary::Point P(arrayx[i],arrayy[i]);
   V.push_back(P);
  }

  ProjectLibrary::Point G=ProjectLibrary::findMin(V); //findMin va anche a modificare Array
  ProjectLibrary::polarSort(V,G);
  std::list<ProjectLibrary::Point> List=ProjectLibrary::convexHull(V,G);
  vector<ProjectLibrary::Point> H=ProjectLibrary::maxArea(List);
  double d=Area(H[0],H[1],H[2]);
  EXPECT_TRUE(abs(d-21.49)<epsilon); //da aggiustare il test come output funzione dovrebbe andare
}

TEST(TestFunzioneTotale, TestFunzioneTotale1)
{

    double arrayx[15]={9,1,8.98,6,7.18,7.76,4.36,4.08,5.48,6.79,7.87,8.17,6.3,6.2,5.26};
    double arrayy[15]={8,1,2.61,4,4.77,3.88,2.5,3.84,4.75,6.05,5.95,4.8,3.5,2.48,2.87};
    int arrayid[15]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    vector<ProjectLibrary::Point> V;
    vector<ProjectLibrary::Point> O;
    for(int i=0;i<15;i++)
    {
     ProjectLibrary::Point P(arrayx[i],arrayy[i],arrayid[i]);
     V.push_back(P);
     O.push_back(P);

    }
    int a=0,b=0,c=0;
   // ProjectLibrary::bpoint(O,a,b,c);

    ProjectLibrary::Point G=ProjectLibrary::findMin(V); //findMin va anche a modificare Array
    ProjectLibrary::polarSort(V,G);
    std::list<ProjectLibrary::Point> List=ProjectLibrary::convexHull(V,G);
    vector<ProjectLibrary::Point> H=ProjectLibrary::maxArea(List);



  EXPECT_TRUE(1==1); //da modificare
}

TEST(Testdet,Testdet1)
{
  ProjectLibrary::Point A(0,0);
  ProjectLibrary::Point B(1.06,2.45);
  ProjectLibrary::Point C(2.32,1.25);
  ProjectLibrary::Point D(1.2,1.43);
  ProjectLibrary::Point E(0.18,2.49);
  ProjectLibrary::Point F(1.84,2.13);
  ProjectLibrary::Triangle T(A,B,C);
  double d;
  d=T.det(D);
  cout<<d<<endl;
  d=T.det(E);
  cout<<d<<endl;
  d=T.det(F);
  cout<<d<<endl;


  EXPECT_TRUE(T.det(D)>0 && T.det(E)<0);

}

TEST(TestTriangle,TestPuntoInterno)
{
  ProjectLibrary::Point A(0,0);
  ProjectLibrary::Point B(1.06,2.45);
  ProjectLibrary::Point C(2.32,1.25);
  ProjectLibrary::Point D(1.2,1.43);
  ProjectLibrary::Point E(0.18,2.49);
  ProjectLibrary::Point F(1.84,2.13);
  ProjectLibrary::Triangle T(A,B,C);

  EXPECT_TRUE(ProjectLibrary::interTria(T,D)==1 && ProjectLibrary::interTria(T,E)==0);
}



TEST(TestBox, TestBox1) //verifica se funziona funzione area
{
  ProjectLibrary::Point A(2,3);
  ProjectLibrary::Point B(6,4);
  ProjectLibrary::Point C(3,5);
  ProjectLibrary::Point D(5,3);
  ProjectLibrary::Point E(9,7);
  ProjectLibrary::Point F(11.18,8.93);
  ProjectLibrary::Point G(2.48,3.51);
  ProjectLibrary::Point H(4.92,4.17);
  ProjectLibrary::Point I(-4.66,5.47);
  ProjectLibrary::Point J(-2.62,3.89);
  ProjectLibrary::Point K(2.18,-2.53);
  ProjectLibrary::Point L(6.2,-0.77);
  ProjectLibrary::Point M(1.74,7.41);
  ProjectLibrary::Point N(4.56,9.17);


  EXPECT_TRUE((!ProjectLibrary::boxInter(A,B,C,D)) && ProjectLibrary::boxInter(A,B,E,F) && (!ProjectLibrary::boxInter(A,B,G,H)) && ProjectLibrary::boxInter(A,B,I,J) && ProjectLibrary::boxInter(A,B,K,L) && ProjectLibrary::boxInter(A,B,I,J));
}

TEST(TestIntersegment, Test1) //verifica se funziona funzione area
{
  ProjectLibrary::Point A(4.82,5.97);
  ProjectLibrary::Point B(10.55,9.17);
  ProjectLibrary::Point C(5.87,7.97);
  ProjectLibrary::Point D(9.8,5.96);
  ProjectLibrary::Point E(1.92,11.7);
  ProjectLibrary::Point F(5.65,12.98);
  ProjectLibrary::Point G(1.84,10.91);
  ProjectLibrary::Point H(4.95,12.19);
  ProjectLibrary::Point I(16,6);
  ProjectLibrary::Point J(16,4);
  ProjectLibrary::Point K(14.7,5.22);
  ProjectLibrary::Point L(7.26,7.26);
  ProjectLibrary::Point M(14.99,4.37);
  ProjectLibrary::Point N(17.24,5.33);

  cout<<"QUUUUUUIiII"<<endl;

  EXPECT_TRUE(!(ProjectLibrary::segmentInter(A,B,B,A)) && ProjectLibrary::segmentInter(A,B,C,D) && (!ProjectLibrary::segmentInter(E,F,G,H)) && (!ProjectLibrary::segmentInter(I,J,K,L)) && ProjectLibrary::segmentInter(N,M,I,J) && (!ProjectLibrary::segmentInter(K,L,I,J)));
}

TEST(TestsegmentValidTriangle, Test1) //verifica se funziona funzione area
{
  ProjectLibrary::Point A(6,4);
  ProjectLibrary::Point B(8.03,6.91);
  ProjectLibrary::Point C(10,4);
  ProjectLibrary::Triangle* pT;
  pT=new ProjectLibrary::Triangle(A,B,C);
  ProjectLibrary::Point D(4.64,7.51);
  ProjectLibrary::Point E(10.07,6.54);
  ProjectLibrary::Point F(8.62,10.9);
  ProjectLibrary::Point G(7.93,2.8);
  ProjectLibrary::Point H(10,10,8);
  ProjectLibrary::Point I(11.76,8.48);


  EXPECT_TRUE(!(ProjectLibrary::segmentValidTriangle(&pT,A,E)) && !(ProjectLibrary::segmentValidTriangle(&pT,C,D)) && !(ProjectLibrary::segmentValidTriangle(&pT,B,G)) && ProjectLibrary::segmentValidTriangle(&pT,B,F) && ProjectLibrary::segmentValidTriangle(&pT,H,I));
}



TEST(TestcreaTriangolo,TestcreaTriangolo12)
{
  ProjectLibrary::Point A(4,0);
  ProjectLibrary::Point B(6.5);
  ProjectLibrary::Point C(8,2);
  ProjectLibrary::Point D(2.84,4.34);
  ProjectLibrary::Point E(9.78,5.66);
  ProjectLibrary::Point F(8.2,-1.64);
  ProjectLibrary::Triangle T(A,B,C); //p1=A,p2=C,p3=B;
  ProjectLibrary::Triangle* head;
  head=&T;
  ProjectLibrary::Triangle* pT=ProjectLibrary::creaTriaEst31(&head,F);
  int i=1;
  ProjectLibrary::stampaTriangoli(&head);
  ProjectLibrary::stampaTriangoli(&pT);

  EXPECT_TRUE(pT->p1.x==4);
}

TEST(TestPuntoEsterno,TestPuntoesterno)
{
  ProjectLibrary::Point A(0.71,0.01,0);
  ProjectLibrary::Point B(0.8,0.89,1);
  ProjectLibrary::Point C(0.03,0.83,2);
  ProjectLibrary::Point D(0.81,0.28,3);
  ProjectLibrary::Point E(0.91,0.68,4);
  ProjectLibrary::Point F(0.13,0.66,5);
  ProjectLibrary::Point G(0.91,0.12,6);
  ProjectLibrary::Point H(0.63,0.5,7);
  ProjectLibrary::Point I(0.1,0.96,8);
  ProjectLibrary::Triangle T(A,B,C); //p1=A,p2=C,p3=B;
  ProjectLibrary::Triangle* head;
  head=&T;
  int s=1;
  bool b=ProjectLibrary::delunayCondition(C,A,F,A,C,B);
  cout<<"ECCO: "<<b<<endl;
  ProjectLibrary::puntoEsterno(&head,D);
  cout<<"aaa"<<endl;
  ProjectLibrary::stampaTriangoli(&head);



  EXPECT_TRUE(A.id==2);
}

TEST(Testflip,Testflip)
{
  ProjectLibrary::Point A(2,5,0);
  ProjectLibrary::Point B(3.3994,3.18715,1);
  ProjectLibrary::Point C(3.31717,4.61784,2);
  ProjectLibrary::Point D(2.03449,3.8285,3);
  ProjectLibrary::Point E(0.91,0.68,4);
  ProjectLibrary::Point F(0.13,0.66,5);
  ProjectLibrary::Point G(0.91,0.12,6);
  ProjectLibrary::Point H(0.63,0.5,7);
  ProjectLibrary::Point I(0.1,0.96,8);
  ProjectLibrary::Triangle T(A,B,C); //p1=B,p2=C,p3=A;
  ProjectLibrary::Triangle L(A,D,B); //p1=D,p2=B,p3=A;
  ProjectLibrary::Triangle* head=&T;
  ProjectLibrary::Triangle* K=&L;
  head->adj31=K;
  K->adj23=head;
  int h=0;
  ProjectLibrary::miniVerifica(&head,1,h);
  int s=1;
  ProjectLibrary::stampaTriangoli(&head);

  bool b=ProjectLibrary::delunayCondition(A,B,D,A,B,C);



  EXPECT_TRUE(b);
}

#endif // __TEST_EMPTY_H
