#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/// \brief ImportVectors reads the input vectors from file for dot product
/// \param filePath: path name of the input file
/// \param n: resulting size of the vectors
/// \param v1: resulting vector1
/// \param v2: resulting vector2
/// \return the result of the reading, true is success, false is error
bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   unsigned int*& v1,
                   unsigned int*& v2);

/// \brief DotProduct performs the dot product between two vectors
/// \param n: size of the vectors
/// \param v1: the first vector
/// \param v2: the second vector
/// \return the resulting dot product
unsigned int DotProduct(const size_t& n,
                        const unsigned int* const& v1,
                        const unsigned int* const& v2);

/// \brief ExportResult export the result obtained in file
/// \param outputFilePath: path name of the output file
/// \param v1: vector1
/// \param v2: vector2
/// \param dotProduct: the dot product
/// \return the result of the export, true is success, false is error
bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const unsigned int* const& v1,
                  const unsigned int* const& v2,
                  const unsigned int& dotProduct);


/// \brief Export a vector in a string
/// \param n: size of the vector
/// \param v: vector
/// \return the resulting string
string ArrayToString(const size_t& n,
                     const unsigned int* const& v)
{
  ostringstream toString;
  toString << "[ ";
  for (unsigned int i = 0; i < n; i++)
    toString<< v[i]<< " ";
  toString << "]";

  return toString.str();
}

int main()
{
  string inputFileName = "./vectors.txt";
  size_t n = 0;
  unsigned int* v1 = nullptr;
  unsigned int* v2 = nullptr;

  if (!ImportVectors(inputFileName, n, v1, v2))
  {
    cerr<< "Something goes wrong with import"<< endl;
    return -1;
  }
  else
    cout<< "Import successful: n= "<< n<< " v1= "<< ArrayToString(n, v1)<< " v2= "<< ArrayToString(n, v2)<< endl;

  unsigned int dotProduct = DotProduct(n, v1, v2);
  cout<< "dot product: "<< dotProduct << endl;

  string outputFileName = "./dotProduct.txt";
  if (!ExportResult(outputFileName, n, v1, v2, dotProduct))
  {
    cerr<< "Something goes wrong with export"<< endl;
    return -1;
  }
  else
    cout<< "Export successful"<< endl;

  delete[] v1;
  delete[] v2;

  return 0;
}

bool ImportVectors(const string& inputFilePath,
                   size_t& n,
                   unsigned int*& v1,
                   unsigned int*& v2)
{
  /// Open File
  ifstream file;
  file.open(inputFilePath);

  if (file.fail())
  {
    cerr<< "file open failed"<< endl;
    return false;
  }

  /// Get number elements
  string line;
  while (!file.eof())
  {
    getline(file, line);

    // Skip Comment Line
    if(line[0] != '#')
      break;
  }

  istringstream convertN;
  convertN.str(line);
  convertN >> n;

  /// Get first vector
  while (!file.eof())
  {
    getline(file, line);

    // Skip Comment Line
    if(line[0] != '#')
      break;
  }
  istringstream convertV1;
  convertV1.str(line);

  v1 = new unsigned int[n];
  for (unsigned int i = 0; i < n; i++)
    convertV1 >> v1[i];

  /// Get second vector
  while (!file.eof())
  {
    getline(file, line);

    // Skip Comment Line
    if(line[0] != '#')
      break;
  }
  istringstream convertV2;
  convertV2.str(line);

  v2 = new unsigned int[n];
  for (unsigned int i = 0; i < n; i++)
    convertV2 >> v2[i];

  /// Close File
  file.close();

  return true;
}


unsigned int DotProduct(const size_t& n,
                        const unsigned int* const& v1,
                        const unsigned int* const& v2)
{
  unsigned int dotProduct = 0;
  for (unsigned int i = 0; i < n; i++)
    dotProduct += v1[i] * v2[i];

  return dotProduct;
}


bool ExportResult(const string& outputFilePath,
                  const size_t& n,
                  const unsigned int* const& v1,
                  const unsigned int* const& v2,
                  const unsigned int& dotProduct)
{
  /// Open File
  ofstream file;
  file.open(outputFilePath);

  if (file.fail())
  {
    cerr<< "file open failed"<< endl;
    return false;
  }

  file<< "# Size of the two vectors"<< endl;
  file<< n<< endl;

  file<< "# vector 1"<< endl;
  for (unsigned int i = 0; i < n; i++)
    file<< (i != 0 ? " " : "")<< v1[i];
  file<< endl;

  file<< "# vector 2 "<< endl;
  for (unsigned int i = 0; i < n; i++)
    file<< (i != 0 ? " " : "")<< v2[i];
  file<< endl;

  file<< "# dot product"<< endl;
  file<< dotProduct<< endl;

  /// Close File
  file.close();

  return true;
}
