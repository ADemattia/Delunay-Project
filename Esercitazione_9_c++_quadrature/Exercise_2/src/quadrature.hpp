#ifndef __QUADRATURE_H
#define __QUADRATURE_H

#include "Eigen/Eigen"
#include "gauss_quadrature_1D.hpp"

using namespace std;
using namespace Eigen;

namespace QuadratureLibrary
{
  // Map points 1D from [-1,1] to [a,b]
  void MapQuadrature1D(const Eigen::MatrixXd& referenceSegmentPoints,
                       const Eigen::VectorXd& referenceSegmentWeight,
                       const double& a,
                       const double& b,
                       Eigen::MatrixXd& segmentPoints,
                       Eigen::VectorXd& segmentWeight);


  // Quadrature formula on the reference square [0,1] x [0,1]
  void ReferenceSquareQuadrature2D(const unsigned int& orderX,
                                   const unsigned int& orderY,
                                   Eigen::MatrixXd& points,
                                   Eigen::VectorXd& weights);


  // Quadrature formula on the reference triangle of vertices: (0,0) (0,1) (1,0)
  void ReferenceTriangleQuadrature2D(const unsigned int& orderX,
                                     const unsigned int& orderY,
                                     Eigen::MatrixXd& points,
                                     Eigen::VectorXd& weights);

  // Quadrature formula on convex polygon
  void PolygonQuadrature2D(const MatrixXd& polygonVertices,
                           const unsigned int& orderX,
                           const unsigned int& orderY,
                           Eigen::MatrixXd& points,
                           Eigen::VectorXd& weights);


}

#endif // __QUADRATURE_H
