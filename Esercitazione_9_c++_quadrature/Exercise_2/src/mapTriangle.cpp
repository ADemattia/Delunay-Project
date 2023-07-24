#include "mapTriangle.hpp"

namespace QuadratureLibrary {

  Triangle::MapTriangleData Triangle::Compute() const
  {
    MapTriangleData result;

    result.B = B();
    result.BInv = result.B.inverse();
    result.b = b();
    result.DetB = result.B.determinant();
    result.DetBInv = result.BInv.determinant();

    return result;
  }

  MatrixXd Triangle::J(const MapTriangleData& mapData,
                       const MatrixXd& x) const
  {
    const unsigned int numPoints = x.cols();
    MatrixXd jacb(3, 3 * numPoints);

    return jacb;
  }

  vector<Triangle> PolygonTriangulationByFirstVertex(const Eigen::MatrixXd& polygonVertices)
  {
    vector<Triangle> triangleList;

    return triangleList;
  }

}
