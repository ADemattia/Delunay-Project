#ifndef __TEST_SHAPE_H
#define __TEST_SHAPE_H

#include <gtest/gtest.h>

#include "shape.hpp"
#include "Eigen/Eigen"

using namespace testing;
using namespace Eigen;
using namespace ShapeLibrary;

TEST(TestShape, TestPolygon)
{
  Eigen::MatrixXd coordinates = MatrixXd::Zero(2,3);
  coordinates << 2.8, 3.9, 3.1,
                  3.9, 1.8, 2.7;

  Polygon polygon = Polygon(coordinates);

  EXPECT_EQ(polygon.Show(), "Polygon: 0.345000");
}

TEST(TestShape, TestTriangleAsPolygon)
{
  Eigen::MatrixXd coordinates = MatrixXd::Zero(2,3);
  coordinates << 2.8, 3.9, 3.1,
                  3.9, 1.8, 2.7;

  Triangle triangle = Triangle(coordinates);

  EXPECT_EQ(triangle.Show(), "Triangle As Polygon: 0.345000");
}

TEST(TestShape, TestTriangle)
{
  double base = 0.5;
  double height = 0.6;
  Triangle triangle = Triangle(base, height);

  EXPECT_EQ(triangle.Show(), "Triangle: 0.150000");
}


TEST(TestShape, TestTriangleEquilateralAsTraingle)
{
  double base = 2;
  double height = sqrt(3);
  TriangleEquilateral triangle = TriangleEquilateral(base, height);

  EXPECT_EQ(triangle.Show(), "TriangleEquilateral As Triangle: 1.732051");
}


TEST(TestShape, TestTriangleEquilateral)
{
  double edgeLength = 0.6;
  TriangleEquilateral triangle = TriangleEquilateral(edgeLength);

  EXPECT_EQ(triangle.Show(), "TriangleEquilateral: 0.155885");
}

TEST(TestShape, TestQuadrilateralAsPolygon)
{
  Eigen::MatrixXd coordinates = MatrixXd::Zero(2, 4);
  coordinates << 0.0, 1.0, 1.0, 0.0,
                  0.0, 0.0, 1.0, 1.0;
  Quadrilateral quadrilateral = Quadrilateral(coordinates);

  EXPECT_EQ(quadrilateral.Show(), "Quadrilateral As Polygon: 1.000000");
}

TEST(TestShape, TestQuadrilateral)
{
  Eigen::MatrixXd coordinates1 = MatrixXd::Zero(2,3);
  coordinates1 << 0.0, 1.0, 1.0,
                  0.0, 0.0, 1.0;

  Eigen::MatrixXd coordinates2 = MatrixXd::Zero(2,3);
  coordinates2 << 1.0, 0.0, 0.0,
                  1.0, 1.0, 0.0;

  Triangle t1 = Triangle(coordinates1);
  Triangle t2 = Triangle(coordinates2);

  Quadrilateral quadrilateral = Quadrilateral(t1, t2);

  EXPECT_EQ(quadrilateral.Show(), "Quadrilateral: 1.000000");
}


TEST(TestShape, TestRectangleAsPolygon)
{
  Eigen::MatrixXd coordinates = MatrixXd::Zero(2, 4);
  coordinates << 0.0, 1.0, 1.0, 0.0,
                  0.0, 0.0, 1.0, 1.0;
  Rectangle rectangle = Rectangle(coordinates);

  EXPECT_EQ(rectangle.Show(), "Rectangle As Polygon: 1.000000");
}

TEST(TestShape, TestRectangleAsQuadrilateral)
{
  Eigen::MatrixXd coordinates1 = MatrixXd::Zero(2,3);
  coordinates1 << 0.0, 1.0, 1.0,
                  0.0, 0.0, 1.0;

  Eigen::MatrixXd coordinates2 = MatrixXd::Zero(2,3);
  coordinates2 << 1.0, 0.0, 0.0,
                  1.0, 1.0, 0.0;

  Triangle t1 = Triangle(coordinates1);
  Triangle t2 = Triangle(coordinates2);

  Rectangle rectangle = Rectangle(t1, t2);

  EXPECT_EQ(rectangle.Show(), "Rectangle As Quadrilateral: 1.000000");
}

TEST(TestShape, TestRectangle)
{
  double base = 0.5;
  double height = 0.6;
  Rectangle rectangle = Rectangle(base, height);

  EXPECT_EQ(rectangle.Show(), "Rectangle: 0.300000");
}


TEST(TestShape, TestSquareAsPolygon)
{
  Eigen::MatrixXd coordinates = MatrixXd::Zero(2, 4);
  coordinates << 0.0, 1.0, 1.0, 0.0,
                  0.0, 0.0, 1.0, 1.0;
  Square rectangle = Square(coordinates);

  EXPECT_EQ(rectangle.Show(), "Square As Polygon: 1.000000");
}

TEST(TestShape, TestSquareAsQuadrilateral)
{
  Eigen::MatrixXd coordinates1 = MatrixXd::Zero(2,3);
  coordinates1 << 0.0, 1.0, 1.0,
                  0.0, 0.0, 1.0;

  Eigen::MatrixXd coordinates2 = MatrixXd::Zero(2,3);
  coordinates2 << 1.0, 0.0, 0.0,
                  1.0, 1.0, 0.0;

  Triangle t1 = Triangle(coordinates1);
  Triangle t2 = Triangle(coordinates2);

  Square square = Square(t1, t2);

  EXPECT_EQ(square.Show(), "Square As Quadrilateral: 1.000000");
}

TEST(TestShape, TestSquareAsRectangle)
{
  double base = 0.5;
  double height = 0.5;
  Square square = Square(base, height);

  EXPECT_EQ(square.Show(), "Square As Rectangle: 0.250000");
}

TEST(TestShape, TestSquare)
{
  double edgeLength = 0.5;
  Square square = Square(edgeLength);

  EXPECT_EQ(square.Show(), "Square: 0.250000");
}


#endif // __TEST_SHAPE_H
