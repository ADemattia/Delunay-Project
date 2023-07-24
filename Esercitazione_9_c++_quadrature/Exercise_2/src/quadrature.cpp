#include "quadrature.hpp"
#include "mapTriangle.hpp"

namespace QuadratureLibrary {

  void MapQuadrature1D(const Eigen::MatrixXd& referenceSegmentPoints,
                       const Eigen::VectorXd& referenceSegmentWeight,
                       const double& a,
                       const double& b,
                       Eigen::MatrixXd& segmentPoints,
                       Eigen::VectorXd& segmentWeight)
  {

  }


  void ReferenceSquareQuadrature2D(const unsigned int& orderX,
                                   const unsigned int& orderY,
                                   Eigen::MatrixXd& points,
                                   Eigen::VectorXd& weights)
  {

  }


  void ReferenceTriangleQuadrature2D(const unsigned int& orderX,
                                     const unsigned int& orderY,
                                     Eigen::MatrixXd& points,
                                     Eigen::VectorXd& weights)
  {

  }

  void PolygonQuadrature2D(const MatrixXd& polygonVertices,
                           const unsigned int& orderX,
                           const unsigned int& orderY,
                           Eigen::MatrixXd& points,
                           Eigen::VectorXd& weights)
  {

  }


}
