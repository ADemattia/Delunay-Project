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
  if(!(convertNumTests >> numTests)){ //assegna a numtest il valore contenuto in argv[1] se non è unsigned dovrebbe dare 0 (da verificare)
    cerr << "Number of tests shall be an unsigned int" << endl;
    return -2;
  }

  cout << "The number of tests is : " << numTests << endl;

  // set seed in order to make the result reproducible for a given numTests value
  srand(5); // inizializza la funzione rand con un valore di base (genera altri numeri pseudo casuali) pari a 5

  // generate numTests float random numbers
  float *x = new float[numTests];
  for(unsigned int i = 0; i < numTests; i++)
    x[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX) + 1.0e-05f;

  float *y_fast = new float[numTests];

  // Tests for fastInvSqrt
  float (*pf)(const float&) = fastInvSqrt; // puntatore a funzione, per specificare il puntatore non serve usare l'ampersand
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
  static unsigned int countCalls = 0;
  countCalls++;

  //cout << "The number of calls to standardInvSqrt is: " << countCalls << "\t";

  float squareRoot = sqrt(x); // sqrt function is defined in cmath

  float y = 1.0f / squareRoot;
  //cout << "x = " << x << "\t y = " << y << "\n";

  return y;
}

float fastInvSqrt(const float& x)
{
  static unsigned int countCalls = 0;
  countCalls++;

  //cout << "The number of calls to fastInvSqrt is: " << countCalls << "\t";

  // compute the integer representation of the bit pattern of x
  int i = *(int*)&x;

  // compute the integer representation of the bit pattern of the square root of x
  i = 0x5f3759df - (i>>1); // condizione da verificare che dà 1 o 0 (T o F)

  // retrieve the float value of the square root of y
  float y = *(float*)&i;

  // perform a Newton's step in order to improve the approximation of the quare root of x
  float xhalf = 0.5f * x;
  y = y * (1.5f - xhalf * y * y);

  //cout << "x = " << x << "\t y = " << y << "\n";
  return y;
}

double speedTest(float invSqrt(const float&),
                 const unsigned int& numTests,
                 const float* const & x,
                 float* const & y)
{
  std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

  for(unsigned int i = 0; i < numTests; i++)
  {
    y[i] = invSqrt(x[i]);
  }

  std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

  double elapsedTime = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();

  return elapsedTime * 1.0e-06;
}

void compareResults(const unsigned int& numTests,
                    const float* const & y_fast,
                    const float* const & y_standard)
{
  float max = numeric_limits<float>::min();
  float min = numeric_limits<float>::max();

  float avg = 0.0;

  for(unsigned int i = 0; i < numTests; i++)
  {
    float err = abs(y_fast[i] - y_standard[i]) / abs(y_standard[i]);

    if(err < min)
      min = err;

    if(err > max)
      max = err;

    avg += err;

  }

  avg /= numTests;

  cout << "min: " << min << ", avg = " << avg << ", max = " << max << endl;
}
