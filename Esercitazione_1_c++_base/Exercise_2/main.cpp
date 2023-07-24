#include <iostream>
#include <fstream>
#include <sstream>

#include <iomanip>

using namespace std;

/// \brief ImporData reads the input data from the data file
/// \param inputFilePath: path name of the input file
/// \param S: the resulting initial wealth
/// \param n: the resulting number of assets
/// \param w: the resulting vector of the weights of assets in the portfolio
/// \param r: the resulting vector of the rates of return of assets
/// \return the result of the reading: true is success, false is error
bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r);

/// \brief ComputeRateOfReturn computes the rate of return of the portfolio and the final amount of wealth
/// \param S: the initial wealth
/// \param n: the number of assets
/// \param w: the vector of the weights of assets in the portfolio
/// \param r: the vector of the rates of return of assets
/// \param rateOfReturn: the resulting rate of return of the portfolio
/// \param V: the resulting final wealth
void ComputeRateOfReturn(const double& S,
                         const size_t& n,
                         const double* const& w,
                         const double* const& r,
                         double& rateOfReturn,
                         double& V);

/// \brief ExportData prints data on an output stream
/// \param out: object of type ostream
/// \param S: the initial wealth
/// \param n: the number of assets
/// \param w: the vector of the weights of assets in the portfolio
/// \param r: the vector of the rates of return of assets
/// \param rateOfReturn: the rate of return of the portfolio
/// \param V: the final wealth
void ExportData(ostream& out,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                const double& rateOfReturn,
                const double& V);

/// \brief Export a vector in a string
/// \param n: size of the vector
/// \param v: vector
/// \return the resulting string
string ArrayToString(const size_t& n,
                     const double* const& v)
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
  string inputFileName = "./data.csv";
  double S = 0.0;
  size_t n = 0;
  double* w = nullptr;
  double* r = nullptr;

  if (!ImportData(inputFileName, S, n, w, r))
  {
    cerr<< "Something goes wrong with import"<< endl;
    return -1;
  }

  // Compute the rate of return of the portfolio and the final wealth V
  double rateOfReturn;
  double V;
  ComputeRateOfReturn(S, n, w, r, rateOfReturn, V);


  // Export data on the standard output
  ExportData(cout, S, n, w, r, rateOfReturn, V);


  // Write data to a file
  string outputFileName = "./result.txt";
  ofstream file;
  file.open(outputFileName);

  if (!file.fail())
  {
    ExportData(file, S, n, w, r, rateOfReturn, V);
  }

  file.close();

  delete[] w;
  delete[] r;

  return 0;
}

bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r)
{
    ifstream file; /// creiamo un oggetto
    file.open(inputFilePath);
    if(file.fail()){
        cerr<<"Errore in apertura file"<<endl;
        return false;
    }
    char c;
    string line;
    istringstream convertS;
    getline(file,line); /// comando per memorizzare in variabile stringa line la riga successiva a quella del puntatore
    convertS.str(line);
    convertS>>c;
    convertS>>c;
    convertS>>S;
    istringstream convertN;
    getline(file,line);
    convertN.str(line);
    convertN>>c;
    convertN>>c;
    convertN>>n;
    getline(file,line);

    w=new double[n]; //creiamo di fatto un array
    r=new double[n];

    istringstream convertWR;
    unsigned int i;
    for(i=0;i<n;i++){
        getline(file,line);
        convertWR.str(line);
        convertWR>>w[i];
        cout<<w[i]<<endl;
        convertWR>>c;
        convertWR>>r[i];
        convertWR.clear(); /// svuota l'oggetto istringstream per poterlo riutilizzare
    }

    file.close();

  return true;
}


void ComputeRateOfReturn(const double& S,
                         const size_t& n,
                         const double* const& w,
                         const double* const& r,
                         double& rateOfReturn,
                         double& V)
{
    double v=0;
    double ror;
    unsigned int i;
    for(i=0;i<n;i++)
    {
        v += S*(w[i])*(1+r[i]);
    }

    ror=(v-S)/S;
    V=v;
    rateOfReturn=ror;

    return;

}


void ExportData(ostream& out,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                const double& rateOfReturn,
                const double& V)
{


    out<<"S =" << S << ", n =" << n << endl; // usiamo out poichè abbiamo già la referenza ad ofstream

    out<<"w =[ ";

    unsigned int i;
    for(i=0;i<n;i++){
        out<< w[i] << " ";
    }
    out<< "]"<<endl;

    out<<"r =[ ";

    for(i=0;i<n;i++){
        out<< r[i] << " ";
    }
    out<< "]"<<endl;

    out<<"Rate of return of the portfolio: "<< rateOfReturn<<endl;
    out<<"V: "<< V<<endl;

    //out.close();

    return;

}
