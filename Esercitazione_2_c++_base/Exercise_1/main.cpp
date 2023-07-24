#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <sstream>

using namespace std;

/// \brief Quake3's FastInvSqrt() (reference: https://www.beyond3d.com/content/articles/8/)
/// \param x: a float number
/// \return the inverse square root of x
float fastInvSqrt(const float& x);

/// \brief Compute the inverse square root with a standard procedure
/// \param x: a float number
/// \return the inverse square root of x
float standardInvSqrt(const float& x);


/// \brief Compute the elapsed time to compute numTests calls to the invSqrt function
/// \param invSqrt: a function which evalutes the square root of its argument
/// \param numTests: number of tests
/// \param x: a vector containing numTests float number
/// \param y: the resulting inverse square root values
/// \return the elapsed time
double speedTest(float invSqrt(const float&),
                 const unsigned int& numTests,
                 const float* const & x,
                 float* const & y);

/// \brief Compare results of fastInvSqrt and standardInvSqrt by computing the relative error
/// (by assuming correct the results of standardInvSqrt)
/// \param numTests: number of tests
/// \param y_fast: inverse square root values related to the application of fastInvSqrt
/// \param y_standard: inverse square root values related to the application of standardInvSqrt
void compareResults(const unsigned int& numTests,
                    const float* const & y_fast,
                    const float* const & y_standard);


int main(int argc, char** argv)
{

  if (argc < 2)
  {
    cerr<< "Number of tests shall passed to the program"<< endl;
    return -1;
  }

  istringstream convertNumTests;
  convertNumTests.str(argv[1]);

  unsigned int numTests;
  if(!(convertNumTests >> numTests))
  {
    cerr << "Number of tests shall be an unsigned int" << endl;
    return -2;
  }

  cout << "The number of tests is : " << numTests << endl;

  // set seed in order to make the result reproducible for a given numTests value
  srand(5);

  // generate numTests float random numbers
  float *x = new float[numTests];
  for(unsigned int i = 0; i < numTests; i++)
    x[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) + 1.0e-05f;

  float *y_fast = new float[numTests];

  // Tests for fastInvSqrt
  float (*pf)(const float&) = fastInvSqrt;
  double elapsedTime_fast = speedTest(pf,
                                      numTests,
                                      x,
                                      y_fast);

  cout << "Elapsed time to realize " << numTests <<
          " calls to fastInvSqrt: " << elapsedTime_fast << "[s]" << endl;

  // Tests for standardInvSqrt
  float *y_standard = new float[numTests];

  pf = standardInvSqrt;
  double elapsedTime_standard = speedTest(pf,
                                          numTests,
                                          x,
                                          y_standard);

  cout << "Elapsed time to realize " << numTests <<
          " calls to standardInvSqrt: " << elapsedTime_standard << "[s]" << endl;


  // Compare results
  string fastAlgorithm = (elapsedTime_fast - elapsedTime_standard > 0) ?
                         "standardInvSqrt" : "fastInvSqrt";

  cout << "Time difference (fastInvSqrt - standardInvSqrt) : "
       << elapsedTime_fast - elapsedTime_standard  << "[s]" << endl;

  cout << "The fastest algorithm is the " << fastAlgorithm << endl;

  compareResults(numTests, y_fast, y_standard);

  delete [] y_standard;
  delete [] y_fast;
  delete [] x;

  return 0;
}


float standardInvSqrt(const float& x)
{
  return 0.f;
}

float fastInvSqrt(const float& x)
{
  return 0.f;
}


void compareResults(const unsigned int& numTests,
                    const float* const & y_fast,
                    const float* const & y_standard)
{
}


double speedTest(float invSqrt(const float&),
                 const unsigned int& numTests,
                 const float* const & x,
                 float* const & y)
{
  return 0.0;
}
