#include <iostream>
#include "Eigen/Eigen"
#include <fstream>
#include "map"

using namespace std;
using namespace Eigen;

// 0D ci sono memorizzati i vertici
// 1D ci sono memorizzati gli edges
// 2D ci sono memorizzati i poligoni

struct TriangularMesh // definiamo la struct
{
    unsigned int NumberCell0D = 0; ///< number of Cell0D
    std::vector<unsigned int> Cell0DId = {}; ///< Cell0D id, size 1 x NumberCell0D
    std::vector<Vector2d> Cell0DCoordinates = {}; ///< Cell0D coordinates, size 2 x NumberCell0D (x,y)
    std::map<unsigned int, list<unsigned int>> Cell0DMarkers = {}; ///< Cell0D markers, size 1 x NumberCell0D (marker)

    unsigned int NumberCell1D = 0; ///< number of Cell1D
    std::vector<unsigned int> Cell1DId = {}; ///< Cell1D id, size 1 x NumberCell1D
    std::vector<Vector2i> Cell1DVertices = {}; ///< Cell1D vertices indices, size 2 x NumberCell1D (fromId,toId)
    std::map<unsigned int, list<unsigned int>> Cell1DMarkers = {}; ///< Cell1D propertoes, size 1 x NumberCell1D (marker)

    unsigned int NumberCell2D = 0; ///< number of Cell2D
    std::vector<unsigned int> Cell2DId = {}; ///< Cell2D id, size 1 x NumberCell2D
    std::vector<array<unsigned int, 3>> Cell2DVertices = {}; ///< Cell2D Vertices indices, size 1 x NumberCell2DVertices[NumberCell2D]
    std::vector<array<unsigned int, 3>> Cell2DEdges = {}; ///< Cell2D Cell1D indices, size 1 x NumberCell2DEdges[NumberCell2D] // vettore di array
};

///\brief Import the triangular mesh and test if the mesh is correct
///\param mesh: a TriangularMesh struct
///\return the result of the reading, true if is success, false otherwise
bool ImportMesh(TriangularMesh& mesh);

///\brief Import the Cell0D properties from Cell0Ds.csv file
///\param mesh: a TriangularMesh struct
///\return the result of the reading, true if is success, false otherwise
bool ImportCell0Ds(TriangularMesh& mesh);

///\brief Import the Cell1D properties from Cell1Ds.csv file
///\param mesh: a TriangularMesh struct
///\return the result of the reading, true if is success, false otherwise
bool ImportCell1Ds(TriangularMesh& mesh);

///\brief Import the Cell2D properties from Cell2Ds.csv file
///\param mesh: a TriangularMesh struct
///\return the result of the reading, true if is success, false otherwise
bool ImportCell2Ds(TriangularMesh& mesh);

// ***************************************************************************
int main()
{

  TriangularMesh mesh;

  if(!ImportMesh(mesh))
  {
    return 1;
  }

  return 0;
}
// ***************************************************************************
bool ImportMesh(TriangularMesh& mesh)
{

  if(!ImportCell0Ds(mesh))
  {
    return false;
  }
  else
  {
    cout << "Cell0D marker:" << endl;
    for(auto it = mesh.Cell0DMarkers.begin(); it != mesh.Cell0DMarkers.end(); it++) // mesh. accediamo al dato specifico nella struct
    {                                                                              // auto (riconosce autonomamente iteratore map che parte da Cell0Markers.begin()
      cout << "key:\t" << it -> first << "\t values:"; // accediamo alla key dell'elemento di map corrente (creiamo una mappa in cui ogni elemento è identificato da una key di un certo type
      for(const unsigned int id : it -> second) // for fatto sulla lista it->second indica la lista, il contatore è l'elemento
        cout << "\t" << id;

      cout << endl;
    }
  }

  if(!ImportCell1Ds(mesh))
  {
    return false;
  }
  else
  {
    cout << "Cell1D marker:" << endl;
    for(auto it = mesh.Cell1DMarkers.begin(); it != mesh.Cell1DMarkers.end(); it++) // fa stessa cosa fatta sopra
    {
      cout << "key:\t" << it -> first << "\t values:";
      for(const unsigned int id : it -> second)
        cout << "\t" << id;

      cout << endl;
    }
  }

  if(!ImportCell2Ds(mesh))
  {
    return false;
  }
  else
  {
    // Test: // verifichiamo che i dati siano coerenti tra loro (di file C0,C1,C3) controlliamo gli edges
    for(unsigned int c = 0; c < mesh.NumberCell2D; c++) // iterazione su numero di celle identificatori, sui triangoli
    {
      array<unsigned int, 3> edges = mesh.Cell2DEdges[c]; // prende gli edges (lati dei trienagoli) ovvero gli identificatori degli edeges

      for(unsigned int e = 0; e < 3; e++) // prende
      {
         const unsigned int origin = mesh.Cell1DVertices[edges[e]][0]; // edges[e] indica l'id del vertice in questione, prendiamo l'origine , prende i vertici da entrambi i lati dell'edges
         const unsigned int end = mesh.Cell1DVertices[edges[e]][1];

         auto findOrigin = find(mesh.Cell2DVertices[c].begin(), mesh.Cell2DVertices[c].end(), origin); // find cerca nell'array dall'inizio alla fine, controlla nell'array di punti del triangolo specifico c, che ci siano i vettori di origine e fine dell'edges
         if(findOrigin == mesh.Cell2DVertices[c].end()) // vuol dire che findOrigin ha valore 0 quindi non è stato trovato
         {
           cerr << "Wrong mesh" << endl;
           return 2;
         }

         auto findEnd = find(mesh.Cell2DVertices[c].begin(), mesh.Cell2DVertices[c].end(), end); // prima abbiamo cercato l'origine ora cerchiamo l'end
         if(findEnd == mesh.Cell2DVertices[c].end())
         {
           cerr << "Wrong mesh" << endl;
           return 3;
         }

         cout << "c: " << c << ", origin: " << *findOrigin << ", end: " << *findEnd << endl; // stampa gli edges

      }
    }
  }

  return true;

}
// ***************************************************************************
bool ImportCell0Ds(TriangularMesh& mesh) // Cell0D dà gli assi X e Y
{

  ifstream file;  /// come in esercitazione 1
  file.open("./Cell0Ds.csv");

  if(file.fail())
    return false;

  list<string> listLines; // lista di stringhe
  string line;
  while (getline(file, line)) // quando getline è pieno viene interpretato, come booleano, come un 1, quando invece è vuoto viene interpretato come uno 0
    listLines.push_back(line); // poniamo l'elemento line alla fine

  file.close();

  listLines.pop_front(); //togliamo la prima stringa della lista fatta dalle notazione (vedere file specifico)

  mesh.NumberCell0D = listLines.size();

  if (mesh.NumberCell0D == 0)
  {
    cerr << "There is no cell 0D" << endl;
    return false;
  }

  mesh.Cell0DId.reserve(mesh.NumberCell0D);
  mesh.Cell0DCoordinates.reserve(mesh.NumberCell0D);

  for (const string& line : listLines) // contatore sulla lista di stringhe
  {
    istringstream converter(line);

    unsigned int id;
    unsigned int marker;
    Vector2d coord;

    converter >>  id >> marker >> coord(0) >> coord(1); // è equivalente a converter>>id converter>>marker converter>>coord(0) converter>>coord(1)

    mesh.Cell0DId.push_back(id); // possiamo usare push_back anche per i vettori
    mesh.Cell0DCoordinates.push_back(coord); // possiamo usare push_back per i vettori

    if( marker != 0) // marker indicano posizione su assi vedere figura in cartella, va ad inserire in Cell0D solo i marker che stanno sui bordi e non quelli interni
    {
      if (mesh.Cell0DMarkers.find(marker) == mesh.Cell0DMarkers.end())
        mesh.Cell0DMarkers.insert({marker, {id}}); //inseriamo gli id (identificativi dei punti, tramite i marker che identificano posizione, i marker sono usati come key e gli identificatori laegati a quella key (stessa caratteristica) sono messi in una stessa lista
      else
        mesh.Cell0DMarkers[marker].push_back(id); // inserito in lista associata alla key marker per questo usiamo push_back
    }

  }
  file.close(); // file già chiuso prima
  return true;
}
// ***************************************************************************
bool ImportCell1Ds(TriangularMesh& mesh) // indica gli edges (vettori) tra punti ottenuti tramite id
{

  ifstream file;
  file.open("./Cell1Ds.csv");

  if(file.fail())
    return false;

  list<string> listLines;
  string line;
  while (getline(file, line))
    listLines.push_back(line); // elimina linea di identificatori notazionali ID Origin End

  listLines.pop_front();

  mesh.NumberCell1D = listLines.size();

  if (mesh.NumberCell1D == 0)
  {
    cerr << "There is no cell 1D" << endl;
    return false;
  }

  mesh.Cell1DId.reserve(mesh.NumberCell1D); // riserva spazio paria a quel numero non è detto che venga riempito tutto
  mesh.Cell1DVertices.reserve(mesh.NumberCell1D);

  for (const string& line : listLines) // scorre la lista di stringhe
  {
    istringstream converter(line);

    unsigned int id; // ogni arco (edges) ha un id
    unsigned int marker; // marker =0 se è coinvolto un nodo centrale, =n se sono coinvolti due nodi (vertici) che stanno sulla linea denotata da n, vedere immagine per capire meglio
    Vector2i vertices;

    converter >>  id >> marker >> vertices(0) >> vertices(1); // come prima, vedere sopra
    cout<<vertices(0)<<","<<vertices(1)<<endl;

    mesh.Cell1DId.push_back(id);
    mesh.Cell1DVertices.push_back(vertices);
    cout<<mesh.Cell1DVertices[8][1]<<endl;

    if( marker != 0) // si fa stessa cosa fatta prima, evitiamo di memorizzare quelli in 0 per questioni di memoria?
    {
      if (mesh.Cell1DMarkers.find(marker) == mesh.Cell1DMarkers.end())
        mesh.Cell1DMarkers.insert({marker, {id}});
      else
        mesh.Cell1DMarkers[marker].push_back(id);
    }
  }

  file.close();

  return true;
}
// ***************************************************************************
bool ImportCell2Ds(TriangularMesh& mesh)
{

  ifstream file;
  file.open("./Cell2Ds.csv");

  if(file.fail())
    return false;

  list<string> listLines;
  string line;
  while (getline(file, line))
    listLines.push_back(line);

  listLines.pop_front(); //solita eliminazione di elementi identificatori notazionali contenuti nel file

  mesh.NumberCell2D = listLines.size();

  if (mesh.NumberCell2D == 0)
  {
    cerr << "There is no cell 2D" << endl;
    return false;
  }

  mesh.Cell2DId.reserve(mesh.NumberCell2D); //riserviamo come prima spazio all'array
  mesh.Cell2DVertices.reserve(mesh.NumberCell2D);
  mesh.Cell2DEdges.reserve(mesh.NumberCell2D);

  for (const string& line : listLines)
  {
    istringstream converter(line);

    unsigned int id;
    array<unsigned int, 3> vertices;
    array<unsigned int, 3> edges;

    converter >>  id; // id del triangolo della mesh specifico
    for(unsigned int i = 0; i < 3; i++)
      converter >> vertices[i];
    for(unsigned int i = 0; i < 3; i++)
      converter >> edges[i];

    mesh.Cell2DId.push_back(id);
    mesh.Cell2DVertices.push_back(vertices);
    mesh.Cell2DEdges.push_back(edges);
  }
  file.close();
  return true;
}
