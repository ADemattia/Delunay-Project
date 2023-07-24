#include "empty_class.hpp" //<iostream> incluso qui
#include <fstream>
#include <sstream>
#include <string>

using namespace ProjectLibrary;



int main()
{
  vector<class Point> V;
  string nome_file = "C:/Users/aless/Desktop/PCS2023_Exercises-main/Projects/Delaunay/Dataset/Test2.csv";
  importDataVec(nome_file, V); //modifica funzione
  cout<<V[1].id<<endl;


  int a=0,b=0,c=0;
  bpoint(V,a,b,c);
  cout<<"sono qui"<<endl;
  cout<<V[1].id<<endl;
  unsigned int s=V.size();
  Triangle* head=new Triangle(V[a],V[b],V[c]); //id coincide con la posizione fino ad ora
  cout<<V[a].x<<"//"<<V[a].y<<endl;
  cout<<V[b].x<<"//"<<V[b].y<<endl;
  cout<<V[c].x<<"//"<<V[c].y<<endl;
  V[a]=V[s-1]; V[b]=V[s-2]; V[c]=V[s-3];
  V.pop_back(); V.pop_back(); V.pop_back();
  cout<<V[0].x<<"//"<<V[0].y<<endl;
  cout<<V[1].x<<"//"<<V[1].y<<endl;
  cout<<V[2].x<<"//"<<V[2].y<<endl;
  cout<<V[3].x<<"//"<<V[4].y<<endl;
  cout<<V[4].x<<"//"<<V[5].y<<endl;
  cout<<V[5].x<<"//"<<V[6].y<<endl;

  int h=0;
  miniVerifica(&head,1,h);
  cout<<"head: "<<head->index;


  for(int i=0; i<3; i++)
  {
      //break;
      class Point Q;
      Q=V[i];
      cout<<endl<<"numero iterazione: "<<Q.id<<endl<<endl;
      bool boo=interno(V[i],&head);
      if(boo)
      {
        cout<<"interno"<<endl;
        stampaTriangoli(&head);
        verificaDelunay1(&head);

        //stampaTriangoli(&head,i);
      }
      else
      {
        cout<<"ESTERNO"<<endl<<endl;
        puntoEsterno(&head,Q);
        verificaDelunay1(&head);

      }
cout<<"-------------"<<endl;

  }











 return 0;
}
