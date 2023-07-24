#ifndef __Quadrature_Gauss1D_H
#define __Quadrature_Gauss1D_H

#include "Eigen/Eigen"


/// Legendre-Gauss quadrature rule for segments (-1,1)
class Quadrature_Gauss1D
{
  public:
    static void FillPointsAndWeights(const unsigned int& order, //ordine quadratura
                                     Eigen::MatrixXd& points, //punti
                                     Eigen::VectorXd& weights) //pesi
    {
      switch(order)
      {
        case 0:
        case 1:
        {
          points.setZero(3,1);
          points(0,0) = 0.0000000000000000e+00;
          weights.resize(1);
          weights[0] = 2.0000000000000000e+00;
        }
          break;
        case 2:
        case 3:
        {
          points.setZero(3,2);
          points(0,0) = -5.7735026918962573e-01;
          points(0,1) = 5.7735026918962573e-01;
          weights.resize(2);
          weights[0] = 9.9999999999999978e-01;
          weights[1] = 9.9999999999999978e-01;
        }
          break;
        case 4:
        case 5:
        {
          points.setZero(3,3);
          points(0,0) = -7.7459666924148340e-01;
          points(0,1) = 0.0000000000000000e+00;
          points(0,2) = 7.7459666924148340e-01;
          weights.resize(3);
          weights[0] = 5.5555555555555436e-01;
          weights[1] = 8.8888888888888884e-01;
          weights[2] = 5.5555555555555436e-01;
        }
          break;
        case 6:
        case 7:
        {
          points.setZero(3,4);
          points(0,0) = -8.6113631159405246e-01;
          points(0,1) = -3.3998104358485626e-01;
          points(0,2) = 3.3998104358485626e-01;
          points(0,3) = 8.6113631159405246e-01;
          weights.resize(4);
          weights[0] = 3.4785484513745440e-01;
          weights[1] = 6.5214515486254598e-01;
          weights[2] = 6.5214515486254598e-01;
          weights[3] = 3.4785484513745440e-01;
        }
          break;
        case 8:
        case 9:
        {
          points.setZero(3,5);
          points(0,0) = -9.0617984593866385e-01;
          points(0,1) = -5.3846931010568300e-01;
          points(0,2) = 0.0000000000000000e+00;
          points(0,3) = 5.3846931010568300e-01;
          points(0,4) = 9.0617984593866385e-01;
          weights.resize(5);
          weights[0] = 2.3692688505618911e-01;
          weights[1] = 4.7862867049936625e-01;
          weights[2] = 5.6888888888888889e-01;
          weights[3] = 4.7862867049936625e-01;
          weights[4] = 2.3692688505618911e-01;
        }
          break;
        case 10:
        case 11:
        {
          points.setZero(3,6);
          points(0,0) = -9.3246951420315205e-01;
          points(0,1) = -6.6120938646626448e-01;
          points(0,2) = -2.3861918608319693e-01;
          points(0,3) = 2.3861918608319693e-01;
          points(0,4) = 6.6120938646626448e-01;
          points(0,5) = 9.3246951420315205e-01;
          weights.resize(6);
          weights[0] = 1.7132449237917050e-01;
          weights[1] = 3.6076157304813866e-01;
          weights[2] = 4.6791393457269098e-01;
          weights[3] = 4.6791393457269098e-01;
          weights[4] = 3.6076157304813866e-01;
          weights[5] = 1.7132449237917050e-01;
        }
          break;
        default:
          throw std::runtime_error("Wrong initialization of 1D Gauss quadrature. Order not supported.");
      }
    }
};


#endif // __Quadrature_Gauss1D_H
