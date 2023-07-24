#include <iostream>
#include "Eigen/Eigen"
#include <fstream>
#include "map"

using namespace std;
using namespace Eigen;

struct PolygonalMesh
{
    unsigned int NumberCell0D=0;
    std::vector<unsigned int> Cell0DId={};
    std::vector<Vector2d> Cell0DCoordinates={};
    std::map<unsigned int,list<unsigned int>> Cell0DMarkers={}; // marcatori posizone punti

    unsigned int NumberCell1D=0;
    std::vector<unsigned int> Cell1DId={};
    std::vector<Vector2i> Cell1DVertices={}; // memorizziamo i vertici di origine e fine degli edges
    std::map<unsigned int,list<unsigned int>> Cell1DMarkers={}; // unsigned int è la key

    unsigned int NumberCell2D=0;
    std::vector<unsigned int> Cell2DId={};
    std::vector<unsigned int> Cell2DVerticesNumber={};
    std::map<unsigned int, list<unsigned int>> Cell2DVertices={};
    std::map<unsigned int, list<unsigned int>> Cell2DEdges={};
};

///\brief Import the Polygonal mesh and test if the mesh is correct
///\param mesh: a PolygonalMesh struct
///\return the result of the reading, true if is success, false otherwise
bool ImportMesh(PolygonalMesh& mesh);

///\brief Import the Cell0D properties from Cell0Ds.csv file
///\param mesh: a PolygonalMesh struct
///\return the result of the reading, true if is success, false otherwise
bool ImportCell0Ds(PolygonalMesh& mesh);

///\brief Import the Cell1D properties from Cell1Ds.csv file
///\param mesh: a PolygonalMesh struct
///\return the result of the reading, true if is success, false otherwise
bool ImportCell1Ds(PolygonalMesh& mesh);

///\brief Import the Cell2D properties from Cell2Ds.csv file
///\param mesh: a PolygonalMesh struct
///\return the result of the reading, true if is success, false otherwise
bool ImportCell2Ds(PolygonalMesh& mesh);

// ***************************************************************************
int main()
{

  PolygonalMesh mesh;

  if(!ImportMesh(mesh))
  {
    return 1;
  }

  return 0;
}
// ***************************************************************************
bool ImportMesh(PolygonalMesh& mesh)
{
    if(!ImportCell0Ds(mesh))
    {
        return false;
    }
    else { // stampiamo i markers
        cout<<"Vertices: "<<endl;
        for(auto it=mesh.Cell0DMarkers.begin(); it!=mesh.Cell0DMarkers.end(); ++it ) // iteriamo sulle key della mappa
        {
             //accede al primo elemento della mappa ovvero alla key
            cout<<"key: "<< it->first << " values: ";
            for(auto i: it->second) //iterare sugli elementi della lista;
               {
                cout<<i<<", ";
            }
            cout<<endl;
        }
    }



    if(!ImportCell1Ds(mesh))
    {
        return false;
    }
    else { // stampiamo i markers
        cout<<"Edges: "<<endl;
        for(auto it=mesh.Cell1DMarkers.begin(); it!=mesh.Cell1DMarkers.end(); ++it ) // iteriamo sulle key della mappa
        {
             //accede al primo elemento della mappa ovvero alla key
            cout<<"key: "<< it->first << " values: ";
            for(auto i: it->second) //iterare sugli elementi della lista;
               {
                cout<<i<<", ";
            }
            cout<<endl;
        }
    }

    if(!ImportCell2Ds(mesh))
    {
      return false;
    }
    else{
        //Test che informazioni siano coerenti
        for( int c=0; c!=mesh.NumberCell2D; c++){ //identificatori vanno da 0 a numbercell2d poligoni
            for(unsigned int  e : mesh.Cell2DEdges[c]){
               // cout<<endl<<e<<endl;
                unsigned int origin=mesh.Cell1DVertices[e][0];

                unsigned int end=mesh.Cell1DVertices[e][1];
               // cout<<end<<endl;

                auto findOrigin = find(mesh.Cell2DVertices[c].begin(), mesh.Cell2DVertices[c].end(), origin); // find cerca nell'array dall'inizio alla fine, controlla nell'array di punti del triangolo specifico c, che ci siano i vettori di origine e fine dell'edges
                if(findOrigin == mesh.Cell2DVertices[c].end()) // vuol dire che findOrigin ha valore 0 quindi non è stato trovato
                {
                  cerr << "Wrong mesh" << endl; // auto diventa puntatore a elemento di lista quindi bisogna dereferenziarlo
                  return false;
                }


                auto  findEnd = find(mesh.Cell2DVertices[c].begin(), mesh.Cell2DVertices[c].end(), end); // find cerca nell'array dall'inizio alla fine, controlla nell'array di punti del triangolo specifico c, che ci siano i vettori di origine e fine dell'edges
                  if(findEnd == mesh.Cell2DVertices[c].end()) // vuol dire che findOrigin ha valore 0 quindi non è stato trovato
                  {
                    cerr << "Wrong mesh" << endl;
                    return false;
                  }

                  cout << "c: "<<c<<", origin: "<<*findOrigin<< ", end: " << *findEnd << endl; // stampa gli edges, dereferenziamo i puntatori
    }
        }
    }

  return true;

}

// ***************************************************************************
bool ImportCell0Ds(PolygonalMesh& mesh)
{

    ifstream file;
    file.open("./Cell0Ds.csv");
    if(file.fail())
        return false;

    string line;
    list<string> listLine;
    while(getline(file,line))
        listLine.push_back(line); //inseriamo gli elementi da dietro

    file.close();

    listLine.pop_front(); // elimino prima stringa che contine parole notazionali

    mesh.NumberCell0D=listLine.size();

    if (mesh.NumberCell0D == 0)
    {
      cerr << "There is no cell 0D" << endl;
      return false;
    }

    mesh.Cell0DId.reserve(mesh.NumberCell0D); // riserva spazio di dimensione indicata
    mesh.Cell0DCoordinates.reserve(mesh.NumberCell0D);


    for(string line : listLine) { // contatore di stringhe sulla lista
        istringstream converter(line);
       // debug  cout<<line<<endl;

    unsigned int id;
    unsigned int marker;
    char c1;
    char c2;
    char c3;
    Vector2d C; // coordinate;

    converter>> id>>c1>>marker>>c2>>C(0)>>c3>> C(1);
    // debug cout<<id<<endl;
   // cout<<marker<<endl;
  //  cout<<C(0)<<endl;
    converter.clear();



    mesh.Cell0DId.push_back(id);  // inseriamo elementi in vettore alla fine
    mesh.Cell0DCoordinates.push_back(C);

    if(marker!=0){

    if(mesh.Cell0DMarkers.find(marker)==mesh.Cell0DMarkers.end())
    {
        mesh.Cell0DMarkers.insert({marker,{id}}); // inserimento in mappa
    }
    else {
        mesh.Cell0DMarkers[marker].push_back(id); // inseriamo id in lista
    }


    }
   }


  return true;
}

// ***************************************************************************
bool ImportCell1Ds(PolygonalMesh& mesh)
{

    ifstream file;
    file.open("./Cell1Ds.csv");
    if(file.fail())
        return false;

    list<string> lineList;
    string line;
    while(getline(file,line))
        lineList.push_back(line);

      //togliamo primo elemento di notazioni
    file.close();
    lineList.pop_front();

    mesh.NumberCell1D=lineList.size();

    if(mesh.NumberCell1D==0){
        cerr << "There is no cell 1D" << endl;
        return false;
    }

    mesh.Cell1DVertices.resize(mesh.NumberCell1D);
    mesh.Cell1DId.resize(mesh.NumberCell1D);
    unsigned int i=0;

    for(const string lin: lineList){
        istringstream converter(lin);

        char c1;
        char c2;
        char c3;
        unsigned int id;
        unsigned int marker;
        Vector2i V; // vettore vertici

        converter>>id>>c1>>marker>>c2>>V(0)>>c3>>V(1);
       // cout<<V(0)<<","<<V(1)<<endl;


        mesh.Cell1DId.push_back(id);
        mesh.Cell1DVertices[i]=V;
        // cout<<mesh.Cell1DVertices[i][1]<<endl;
        i++;


        if(marker!=0) {
            if(mesh.Cell1DMarkers.find(marker)==mesh.Cell1DMarkers.end())
            {
                mesh.Cell1DMarkers.insert({marker,{id}});
            }
            else {
                mesh.Cell1DMarkers[marker].push_back(id); // tutto come sopra
            }
        }

    }


  return true;
}
// ***************************************************************************
bool ImportCell2Ds(PolygonalMesh& mesh)
{
    ifstream file;
    file.open("./Cell2Ds.csv");
    if(file.fail())
        return false;

    list<string> lineList;
    string line;

    while(getline(file,line))
        lineList.push_back(line);

    lineList.pop_front();

    file.close();

    mesh.NumberCell2D=lineList.size();

    if(mesh.NumberCell2D==0){
        return false;
    }

    for (auto lin : lineList) {
       // cout<<line<<endl;
        istringstream converter(lin);
        char c;
        unsigned int id;
        unsigned int marker;  // usigned dovrebbe dare risultati più efficenti di int signed
        unsigned int num;
        list<unsigned int> V;
        list<unsigned int> E;
        unsigned int v,e;


        converter>>id>>c>>marker>>c>>num; //se facciamo ancora >>c allora dovrebbe sovrascrivere il dato
       // cout<<num<<endl;

        for(int i=0;i!=num;i++){
            converter>>c;
            converter>>v;
            V.push_back(v);
        }
        mesh.Cell2DVertices.insert({id,{V}});
        converter>>c>>num; //numero vertici uguale a numero edges
       // cout<<endl;
        for(int i=0;i!=num;i++){
            converter>>c;
            converter>>e;

            //cout<<e<<",";
            E.push_back(e);
        }
        mesh.Cell2DEdges.insert({id,{E}});

        mesh.Cell2DId.push_back(id);

        mesh.Cell2DVerticesNumber.push_back(num);

    }




  return true;
}
