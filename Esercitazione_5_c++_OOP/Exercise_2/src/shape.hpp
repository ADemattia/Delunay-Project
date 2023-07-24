#ifndef __SHAPE_H
#define __SHAPE_H

#include <iostream>
#include "Eigen/Eigen"

using namespace std;

namespace ShapeLibrary {

  class Polygon {
    public:
      Polygon() = default; //default vuol dire che viene generato automaticamente da compilatore
      Polygon(Eigen::MatrixXd& points);
      string Show();
      double Area();
  protected:
      Eigen::MatrixXd points;

  };


  class Triangle : virtual public Polygon //virtual possiamo sovrascrvire una funzione della classe base, ad esempio Area(), per accedere ad Area di triangolo unsiamo triangle.area() altrimenti triangle.Polygon::area()
  {
    public:
      Triangle() = default;
      Triangle(double& base,
               double& height);

      Triangle(Eigen::MatrixXd& points);
      string Show();
      double Area();
  protected:
      double base;
      double height;
  };


  class TriangleEquilateral final : virtual public Triangle
  {
    public:
      TriangleEquilateral(double& edgeLength);
      TriangleEquilateral(double& base,
                          double& height);
      string Show();
      double Area();
    protected:
      double edgeLength;
      int i;
  };

  class Quadrilateral : virtual public Polygon
  {
    public:
      Quadrilateral() = default;
      Quadrilateral(Eigen::MatrixXd& points);
      Quadrilateral(Triangle& t1, Triangle& t2);
      string Show();
      double Area();
  protected:
      Triangle t1;
      Triangle t2;
  };

  class Rectangle : virtual public Quadrilateral
  {
    public:
      Rectangle() = default;
      Rectangle(Eigen::MatrixXd& points);
      Rectangle(Triangle& t1, Triangle& t2);
      Rectangle(double& base, double& height);
      string Show();
      double Area();
  protected:
      int j;
      double basez;
      double heightz;
  };

  class Square final: virtual public Rectangle
  {
    public:
      Square(Eigen::MatrixXd& points);
      Square(Triangle& t1, Triangle& t2);
      Square(double& base, double& height);
      Square(double& edgeLength);
      string Show();
      double Area();
  protected:
    int k,l;
    double edgeLengthz;
  };
}

#endif // __SHAPE_H
