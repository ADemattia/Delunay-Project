#ifndef __TEST_QUADRATURE_H
#define __TEST_QUADRATURE_H

#include <gtest/gtest.h>
#include "iostream"
#include "quadrature.hpp"

using namespace testing;
using namespace std;


int factorial(const int& n)
{
  if (n > 1)
    return n * factorial(n-1);
  else
    return 1;

}


TEST(TestQuadrature1D, TestQuadratureReferenceSegment_Gauss1D)
{
  double tolerance = 1.0e-14;

  unsigned int minOrder = 0;
  unsigned int maxOrder = 11;

  Eigen::VectorXi quadratureOrders = Eigen::VectorXi::LinSpaced(maxOrder + 1,minOrder,maxOrder);
  Eigen::VectorXi orderMax = Eigen::VectorXi::LinSpaced(maxOrder + 1,minOrder,maxOrder);

  for (unsigned int numOrd = 0; numOrd < orderMax.size(); numOrd++)
  {
    Eigen::MatrixXd points;
    Eigen::VectorXd weights;

    Quadrature_Gauss1D::FillPointsAndWeights(quadratureOrders[numOrd],
                                             points,
                                             weights);

    ASSERT_TRUE(abs(weights.sum() - 2.0) <= tolerance);

    for(int ord = 0; ord <= orderMax[numOrd]; ord++)
    {
      Eigen::VectorXd pointsX = (points.row(0));
      Eigen::VectorXd pointsXPow = (pointsX.array()).pow(ord);
      double result = pointsXPow.dot(weights);
      double expectedResult = 1.0 / (ord + 1.0) - (((ord + 1) % 2 == 0) ? 1.0: -1.0) / (ord + 1.0);

      ASSERT_TRUE(abs(result - expectedResult) <= tolerance);
    }
  }

}

TEST(TestQuadrature1D, TestQuadratureSegment_Gauss1D)
{
  double tolerance = 1.0e-12;

  double a = -2;
  double b = -1;

  unsigned int minOrder = 0;
  unsigned int maxOrder = 11;

  Eigen::VectorXi quadratureOrders = Eigen::VectorXi::LinSpaced(maxOrder + 1,minOrder,maxOrder);
  Eigen::VectorXi orderMax = Eigen::VectorXi::LinSpaced(maxOrder + 1,minOrder,maxOrder);

  for (unsigned int numOrd = 0; numOrd < orderMax.size(); numOrd++)
  {
    Eigen::MatrixXd referencePoints;
    Eigen::VectorXd referenceWeights;

    Quadrature_Gauss1D::FillPointsAndWeights(quadratureOrders[numOrd],
                                             referencePoints,
                                             referenceWeights);

    Eigen::MatrixXd points;
    Eigen::VectorXd weights;

    QuadratureLibrary::MapQuadrature1D(referencePoints,
                                       referenceWeights,
                                       a,
                                       b,
                                       points,
                                       weights);

    ASSERT_TRUE(abs(weights.sum() - abs(b-a)) <= tolerance);

    for(int ord = 0; ord <= orderMax[numOrd]; ord++)
    {
      Eigen::VectorXd pointsX = (points.row(0));
      Eigen::VectorXd pointsXPow = (pointsX.array()).pow(ord);
      double result = pointsXPow.dot(weights);
      double expectedResult = pow(b, ord + 1) / (ord + 1.0)
                              -  pow(a, ord + 1) / (ord + 1.0);

      ASSERT_TRUE(abs(result - expectedResult) <= tolerance);
    }
  }

}

TEST(TestQuadrature2D, TestQuadratureReferenceSquare_Gauss2D)
{
  double tolerance = 1.0e-14;

  unsigned int minOrder = 0;
  unsigned int maxOrder = 11;

  Eigen::VectorXi quadratureOrders = Eigen::VectorXi::LinSpaced(maxOrder + 1,minOrder,maxOrder);
  Eigen::VectorXi orderMax = Eigen::VectorXi::LinSpaced(maxOrder + 1,minOrder,maxOrder);

  for (unsigned int numOrdX = 0; numOrdX < orderMax.size(); numOrdX++)
  {
    for (unsigned int numOrdY = 0; numOrdY < orderMax.size(); numOrdY++)
    {
      Eigen::MatrixXd points;
      Eigen::VectorXd weights;

      QuadratureLibrary::ReferenceSquareQuadrature2D(numOrdX,
                                                     numOrdY,
                                                     points,
                                                     weights);

      ASSERT_TRUE(abs(weights.sum() - 1.0) <= tolerance);

      for(int ordX = 0; ordX <= orderMax[numOrdX]; ordX++)
      {
        for(int ordY = 0; ordY <= orderMax[numOrdY]; ordY++)
        {
          Eigen::VectorXd pointsX = (points.row(0));
          Eigen::VectorXd pointsXPow = (pointsX.array()).pow(ordX);
          Eigen::VectorXd pointsY = (points.row(1));
          Eigen::VectorXd pointsYPow = (pointsY.array()).pow(ordY);
          double result = (pointsXPow.array() * pointsYPow.array()).matrix().dot(weights);
          double expectedResult = 1.0 / ((ordX + 1.0) * (ordY + 1.0));

          ASSERT_TRUE(abs(result - expectedResult) <= tolerance);
        }
      }
    }
  }
}

TEST(TestQuadrature2D, TestQuadratureReferenceTriangle_Gauss2D)
{
  double tolerance = 1.0e-14;

  unsigned int minOrder = 0;
  unsigned int maxOrder = 10;

  Eigen::VectorXi quadratureOrders = Eigen::VectorXi::LinSpaced(maxOrder + 1,minOrder,maxOrder);
  Eigen::VectorXi orderMax = Eigen::VectorXi::LinSpaced(maxOrder + 1,minOrder,maxOrder);

  for (unsigned int numOrdY = 0; numOrdY < orderMax.size(); numOrdY++)
  {
    for (unsigned int numOrdX = 0; numOrdX < orderMax.size() - numOrdY; numOrdX++)
    {
      Eigen::MatrixXd points;
      Eigen::VectorXd weights;

      QuadratureLibrary::ReferenceTriangleQuadrature2D(numOrdX + numOrdY + 1,
                                                       numOrdY,
                                                       points,
                                                       weights);

      ASSERT_TRUE(abs(weights.sum() - 0.5) <= tolerance);

      for(int ordX = 0; ordX <= orderMax[numOrdX]; ordX++)
      {
        for(int ordY = 0; ordY <= orderMax[numOrdY]; ordY++)
        {
          Eigen::VectorXd pointsX = (points.row(0));
          Eigen::VectorXd pointsXPow = (pointsX.array()).pow(ordX);
          Eigen::VectorXd pointsY = (points.row(1));
          Eigen::VectorXd pointsYPow = (pointsY.array()).pow(ordY);
          double result = (pointsXPow.array() * pointsYPow.array()).matrix().dot(weights);
          double expectedResult = static_cast<double>(factorial(ordX) * factorial(ordY)) / factorial(2 + ordX + ordY);

          ASSERT_TRUE(abs(result - expectedResult) <= tolerance);
        }
      }
    }
  }
}

TEST(TestQuadrature2D, TestQuadraturePolygon_Gauss2D)
{
  double tolerance = 1.0e-14;

  for( unsigned int n = 3; n < 10; n++)
  {
    double invN = 1.0 / n;
    double theta_const = 2 * M_PI * invN;

    MatrixXd polygonVertices(3, n);

    for(unsigned int e = 0; e < n; e++)
    {
      polygonVertices(0, e) = cos(e * theta_const);
      polygonVertices(1, e) = sin(e * theta_const);
    }

    Eigen::MatrixXd points;
    Eigen::VectorXd weights;

    QuadratureLibrary::PolygonQuadrature2D(polygonVertices,
                                           1,
                                           0,
                                           points,
                                           weights);

    ASSERT_TRUE(abs(weights.sum() - 0.5 * n * sin(theta_const)) <= tolerance);
  }
}

#endif // __TEST_QUADRATURE_H
