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
    cout << scientific<< "shape - DetA: "<< detAS<< ", RCondA: "<< 1.0 / condAS << " (Matrix is singular)"<< endl;

  double detAR, condAR, errRelR;
  if(SolveSystem(Rand(n), detAR, condAR, errRelR))
    cout<< scientific<< "rand - DetA: "<< detAR<< ", RCondA: "<< 1.0 / condAR<< ", Relative Error: "<< errRelR<< endl;
  else
    cout<< scientific<< "rand - DetA: "<< detAR<< ", RCondA: "<< 1.0 / condAR << " (Matrix is singular)"<< endl; // notazione scientifica

  double detAH, condAH, errRelH;
  if(SolveSystem(Hilb(n), detAH, condAH, errRelH))
    cout<< scientific<< "hilb - DetA: "<< detAH<< ", RCondA: "<< 1.0 / condAH<< ", Relative Error: "<< errRelH<< endl;
  else
    cout<< scientific<< "hilb - DetA: "<< detAH<< ", RCondA: "<< 1.0 / condAH << " (Matrix is singular)"<< endl;

  return 0;
}


MatrixXd Shape(const unsigned int& n)
{

  VectorXd linspaceVector = VectorXd::LinSpaced(n * n, 1, n * n);
  MatrixXd A = linspaceVector.reshaped<RowMajor>(n, n);

  cout << "Shape(n): \n" << A << endl;

  return A;
}

MatrixXd Rand(const unsigned int& n)
{

  srand(5); // inizializzaiamo con seme 5

  MatrixXd A = MatrixXd::Random(n, n) + MatrixXd::Constant(n, n, 1);

  cout << "Rand(n): \n" << A << endl;
  return A;
}


MatrixXd Hilb(const unsigned int& n)
{

  MatrixXd A = MatrixXd::Zero(n, n);

  for(unsigned int i = 0; i < n; i++)
    A.diagonal(i) = VectorXd::LinSpaced(n - i, i + 1, 2 * n - 1 - i);


  MatrixXd H = A + A.transpose() - MatrixXd(A.diagonal().asDiagonal()); // costruzione un pò complicata ma giusta

  H = H.cwiseInverse();

  cout << "Hilb(n): \n" << H << endl;

  return H;
}

bool SolveSystem(const MatrixXd& A,
                 double& detA,
                 double& condA,
                 double& errRel)
{
  JacobiSVD<MatrixXd> svd(A);
  VectorXd singularValuesA = svd.singularValues();
  condA = singularValuesA.maxCoeff() / singularValuesA.minCoeff();

  detA = A.determinant();

  if( singularValuesA.minCoeff() < 1e-16)
  {
    errRel = -1; // verifichiamo che il determinante non sia 0 (ovvero matrice non invertibile) se la matrice non è invertibile allora ha alemeno un autovettore con autovalore nullo quindi un singolar value è 0 (poniamo tolleranza <1e-16)
    return false;
  }

  unsigned int n = A.rows();
  VectorXd exactSolution = VectorXd::Ones(n); // soluzione esatta
  VectorXd b = A.rowwise().sum();

  VectorXd x = A.fullPivLu().solve(b);

  errRel = (exactSolution - x).norm() / exactSolution.norm();

  return true;
}
