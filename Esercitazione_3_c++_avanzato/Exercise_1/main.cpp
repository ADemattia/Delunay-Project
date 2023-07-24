#include <iostream>
#include "Eigen/Eigen"


using namespace std;
using namespace Eigen;


/// \brief shape(n) is the n-by-n matrix with elements from 1 to n * n.
MatrixXd Shape(const unsigned int& n);

/// \brief rand(n) is the n-by-n matrix with random elements.
MatrixXd Rand(const unsigned int& n);

/// \brief hilb(n) is the n-by-n matrix with elements 1/(i+j-1).
MatrixXd Hilb(const unsigned int& n);
///
/// \brief solveSystem(A) solve the linear system Ax=b with x ones.
/// \param detA the determinant of A
/// \param condA the condition number of A
/// \param errRel the realtive error
/// \return true if the matrix A is invertible, else it returns false
bool SolveSystem(const MatrixXd& A,
                 double& detA,
                 double& condA,
                 double& errRel);

int main()
{
  int n = 4;

  double detAS, condAS, errRelS;
  if(SolveSystem(Shape(n), detAS, condAS, errRelS))
    cout<< scientific<< "shape - DetA: "<< detAS<< ", RCondA: "<< 1.0 / condAS << ", Relative Error: "<< errRelS<< endl;
  else
    cout<< scientific<< "shape - DetA: "<< detAS<< ", RCondA: "<< 1.0 / condAS << " (Matrix is singular)"<< endl;

  double detAR, condAR, errRelR;
  if(SolveSystem(Rand(n), detAR, condAR, errRelR))
    cout<< scientific<< "rand - DetA: "<< detAR<< ", RCondA: "<< 1.0 / condAR<< ", Relative Error: "<< errRelR<< endl;
  else
    cout<< scientific<< "rand - DetA: "<< detAR<< ", RCondA: "<< 1.0 / condAR << " (Matrix is singular)"<< endl;

  double detAH, condAH, errRelH;
  if(SolveSystem(Hilb(n), detAH, condAH, errRelH))
    cout<< scientific<< "hilb - DetA: "<< detAH<< ", RCondA: "<< 1.0 / condAH<< ", Relative Error: "<< errRelH<< endl;
  else
    cout<< scientific<< "hilb - DetA: "<< detAH<< ", RCondA: "<< 1.0 / condAH << " (Matrix is singular)"<< endl;

  return 0;
}


MatrixXd Shape(const unsigned int& n)
{
  return MatrixXd();
}

MatrixXd Rand(const unsigned int& n)
{
  return MatrixXd();
}


MatrixXd Hilb(const unsigned int& n)
{
  return MatrixXd();
}

bool SolveSystem(const MatrixXd& A,
                 double& detA,
                 double& condA,
                 double& errRel)
{
  return false;
}
