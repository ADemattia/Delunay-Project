#include <iostream>
#include "Eigen/Eigen"
#include <fstream>
#include "map"

using namespace std;
using namespace Eigen;

struct TriangularMesh
{

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


  return false;

}
// ***************************************************************************
bool ImportCell0Ds(TriangularMesh& mesh)
{

  return false;
}
// ***************************************************************************
bool ImportCell1Ds(TriangularMesh& mesh)
{

  return false;
}
// ***************************************************************************
bool ImportCell2Ds(TriangularMesh& mesh)
{


  return false;
}
