# Quadrature formula

In numerical analysis, a quadrature rule is used to approximate definite integral of a function.

## Requirements

It is required to write a program which allows to compute integrals on convex polygons.

More precisely, given the Gauss-Legendre quadrature formula on [-1,1], it is required to implement

- A method "MapQuadrature1D" which allows to compute integrals on a generic interval [a,b];
- A method "ReferenceSquareQuadrature2D" which allows to compute integrals on the reference square [0,1]x[0,1];
- A method "ReferenceTriangleQuadrature2D" which allows to compute integrals on the reference triangle of vertices (0,0), (1,0) and (0,1);
- A method "PolygonTriangulationByFirstVertex" which allows to triangulate convex polygons in such a way to generate the smallest number of triangles;
- A method "PolygonQuadrature2D" which allows to compute integrals on convex polygons;

and to define 

- A class "Triangle" which defines methods to map the reference triangle of vertices (0,0), (1,0) and (0,1) into a generic triangle.

