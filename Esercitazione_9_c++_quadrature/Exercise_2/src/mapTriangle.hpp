#ifndef __MAPTRIANGLE_H
#define __MAPTRIANGLE_H

#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;

namespace QuadratureLibrary
{
  class Triangle
  {
    public:
      struct MapTriangleData final
      {
          Eigen::Matrix3d B;
          Eigen::Matrix3d BInv;
          Eigen::Vector3d b;
          double DetB;
          double DetBInv;
      };

    private:

      Eigen::Matrix3d vertices;

      /// Matrix B for linear map x = B * x_r + b from reference triangle [0,1]x[0,1]/2 to triangle with x points
      /// vertices the triangle to map vertices, size 3 x 3
      /// return the resulting value, size 3 x 3
      inline Eigen::Matrix3d B() const
      {
        return Matrix3d();
      }

      /// translation b for linear map x = B * x_r + b from reference triangle [0,1]x[0,1]/2 to triangle with x points
      /// vertices the triangle to map vertices, size 3 x 3
      /// return the resulting value, size 3 x 3
      inline Eigen::Vector3d b() const
      {
        return Vector3d();
      }

    public:
      Triangle() = default;
      Triangle(const Eigen::Matrix3d& vertices): vertices(vertices) {}

      ~Triangle() {}

      /// Map from the triangle reference element [0,1]x[0,1]/2 to the polygon x = F(x_r) = B * x_r + b
      /// \param vertices the triangle 2D to map vertices, size 3 x 3
      /// \return the map data
      MapTriangleData Compute() const;

      /// Map from the triangle reference element [0,1]x[0,1] to the polygon x = F(x_r) = B * x_r + b
      /// \param mapData the map data
      /// \param x points in reference triangle, size 3 x numPoints
      /// \return the mapped polygon points, size 3 x numPoints
      inline Eigen::MatrixXd F(const MapTriangleData& mapData,
                               const Eigen::MatrixXd& x) const
      { return MatrixXd(); }
      /// Map from the polygon x to the triangle reference element [0,1]x[0,1] x_r = F^-1(x_r) = B^-1 * (x - b)
      /// \param mapData the map data
      /// \param x points in polygon, size 3 x numPoints
      /// \return the mapped reference points, size 3 x numPoints
      inline Eigen::MatrixXd FInv(const MapTriangleData& mapData,
                                  const Eigen::MatrixXd& x) const
      { return MatrixXd(); }

      /// Compute the jacobian matrix of the transformation F
      /// \param mapData the map data
      /// \param x points in reference triangle, size 3 x numPoints
      /// \return the B matrix for each points, size 3 x (3 * numPoints)
      Eigen::MatrixXd J(const MapTriangleData& mapData,
                        const Eigen::MatrixXd& x) const;

      /// Compute the determinant of the jacobian matrix of the trasformation
      /// \param mapData the map data
      /// \param x points in reference triangle, size 3 x numPoints
      /// \return the determinant of Jacobian matrix for each points, size 1 x numPoints
      inline Eigen::VectorXd DetJ(const MapTriangleData& mapData,
                                  const Eigen::MatrixXd& x) const
      { return Eigen::VectorXd::Constant(x.cols(), mapData.DetB); }

      /// Compute the determinant of the jacobian matrix of the trasformation
      /// \param mapData the map data
      /// \param x points in reference triangle, size 3 x numPoints
      /// \return the determinant of Jacobian matrix
      inline double DetJ(const MapTriangleData& mapData) const
      {
        return 0.0;
      };
  };

  vector<Triangle> PolygonTriangulationByFirstVertex(const Eigen::MatrixXd& polygonVertices);
}

#endif // __MAPTRIANGLE_H
