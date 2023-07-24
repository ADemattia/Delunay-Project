#include "shape.hpp"
#include <math.h>

namespace ShapeLibrary {
Polygon::Polygon(Eigen::MatrixXd &points) :
    points(points) {}

double Polygon::Area () {
    double A;
    int n=points.cols();
    int i;
    for(i=0;i!=n;i++)
    {
        A += 0.5*(points(0,i%n)*points(1,(i+1)%n)-points(1,i%n)*points(0,(i+1)%n));
    }

   A=abs(A);
   return A;
}

std::string Polygon::Show ()
{
    string a;
    a="Polygon: "+std::to_string(this->Area());
    return a;
}

Triangle::Triangle(double& base,
                   double& height):
    base(base),
    height(height) {}

Triangle::Triangle(Eigen::MatrixXd& points): Polygon(points) {}

double Triangle::Area()
    {
      double A;
      if(points.rows()>0 && points.cols()>0){
          A=this->Polygon::Area();
          cout<<A<<endl;
      }
      else{
          A=base*height/2;
          }
      std::cout<<A<<endl;
      return A;
     }

std::string Triangle::Show() {
    string a;
    if(points.rows()>0 && points.cols()>0) {
        a="Triangle As Polygon: "+std::to_string(this->Area()); //dà area di classe triangle
    }
    else  {
        a="Triangle: "+std::to_string(this->Area());
    }
    return a;
}

TriangleEquilateral::TriangleEquilateral(double& edgeLength) :
edgeLength(edgeLength),
  i(1) {}
//Triangle::base=0;
// Triangle::height=0;

TriangleEquilateral::TriangleEquilateral(double& base,
                                         double& height)
{
Triangle::base=base; //per accedre a variabile classe base Base::nome_variabile
Triangle::height=height;
i=0;
}

double TriangleEquilateral::Area()
{
    double A;
    if(i==1)
    { A=edgeLength*edgeLength*(sqrt(3)/4); }
   else {
        A=base*(height/2) ;
    }

    return A;
}

std::string TriangleEquilateral::Show() {

    string a;
    if(i==0){
        a="TriangleEquilateral As Triangle: "+std::to_string(this->Area());

    }
    else{
        a="TriangleEquilateral: "+std::to_string(this->Area());
    }
    return a;
}

Quadrilateral::Quadrilateral(Eigen::MatrixXd& points) : Polygon(points)
{

}

Quadrilateral::Quadrilateral(Triangle& t1, Triangle& t2) : t1(t1), t2(t2)
{

}

double Quadrilateral::Area() {
    double A;
    if(points.rows()>0 && points.cols()>0){
        A=this->Polygon::Area();
        }
    else {
        A=t1.Area()+t2.Area();
    }
    return A;
}

std::string Quadrilateral::Show() {
    string a;
    if(points.rows()>0 && points.cols()>0){
        a="Quadrilateral As Polygon: "+std::to_string(this->Area());
        }
    else {
        a="Quadrilateral: "+std::to_string(this->Area());
    }
    return a;

}

Rectangle::Rectangle(Eigen::MatrixXd& points): Polygon(points), j(1)
{

}

Rectangle::Rectangle(Triangle& t1, Triangle& t2): Quadrilateral(t1,t2), j(1)
{

}

Rectangle::Rectangle(double& base, double& height)
{
    basez=base; //forse va in conflitto
    heightz=height;

    j=2;
}

double Rectangle::Area() {
    double A;
    if(j==2){
        A=heightz*basez;

    }
    else{
        A=this->Quadrilateral::Area();
    }

    return A;
}

std::string Rectangle::Show() {
    string a;
    if(points.rows()>0 && points.cols()>0){
        a="Rectangle As Polygon: "+std::to_string(this->Area());
        }
    else if(j==2){
        a="Rectangle: "+std::to_string(this->Area());
    }
    else {
        a="Rectangle As Quadrilateral: "+std::to_string(this->Area());
    }
    return a;

}

Square::Square(Eigen::MatrixXd& points) : Polygon(points), k(0)
{

}

Square::Square(Triangle& t1, Triangle& t2) : Quadrilateral(t1,t2), k(0)
{

}

Square::Square(double& base, double& height): Rectangle(base,height), k(1)
{

}


Square::Square(double& edgeLength) : edgeLengthz(edgeLength), k(2)
{

}

double Square::Area() {
    double A;
    if(k==0){

            A=this->Quadrilateral::Area();
        }

    else if(k==1){
        A=(Rectangle::basez)*(Rectangle::heightz);
    }
    else if (k==2){
        A=edgeLengthz*edgeLengthz;
    }



    return A;
}

std::string Square::Show() {
    string a;
    if(k==0){
            if(points.rows()>0 && points.cols()>0)
            {
                a="Square As Polygon: "+std::to_string(this->Area());
            }
            else {
                a="Square As Quadrilateral: "+std::to_string(this->Area());
            }
        }
        else if(k==2){

            a="Square: "+std::to_string(this->Area());
        }

    else if (k==1){

        a="Square As Rectangle: "+std::to_string(this->Area());
    }

 return a;



}






}
