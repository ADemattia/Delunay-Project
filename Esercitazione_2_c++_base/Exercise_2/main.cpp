#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

/// \brief ImportText import the text for encryption
/// \param inputFilePath: the input file path
/// \param text: the resulting text
/// \return the result of the operation, true is success, false is error
bool ImportText(const string& inputFilePath,
                string& text);

/// \brief Encrypt encrypt the text
/// \param text: the text to encrypt
/// \param password: the password for encryption
/// \param encryptedText: the resulting encrypted text
/// \return the result of the operation, true is success, false is error
bool Encrypt(const string& text,
             const string& password,
             string& encryptedText);

/// \brief Decrypt decrypt the text
/// \param text: the text to decrypt
/// \param password: the password for decryption
/// \param decryptedText: the resulting decrypted text
/// \return the result of the operation, true is success, false is error
bool Decrypt(const string& text,
             const string& password,
             string& decryptedText);

int main(int argc, char** argv)
{
  if (argc < 2)
  {
    cerr<< "Password shall passed to the program"<< endl;
    return -1;
  }
  string password = argv[1]; // chiave crittografica
  cout<<password<<endl;

  string inputFileName = "./text.txt", text; // text variabile stringa dove inserire il testo
  if (!ImportText(inputFileName, text)) // chiama una fuznione in una condizione
  {
    cerr<< "Something goes wrong with import"<< endl;
    return -1;
  }
  else
    cout<< "Import successful: result= "<< text<< endl;

  string encryptedText;
  if (!Encrypt(text, password, encryptedText))
  {
    cerr<< "Something goes wrong with encryption"<< endl;
    return -1;
  }
  else
    cout<< "Encryption successful: result= "<< encryptedText<< endl;

  string decryptedText;
  if (!Decrypt(encryptedText, password, decryptedText) || text != decryptedText)
  {
    cerr<< "Something goes wrong with decryption"<< endl;
    return -1;
  }
  else
    cout<< "Decryption successful: result= "<< decryptedText<< endl;

  return 0;
}

bool ImportText(const string& inputFilePath,
                string& text)
{
    ifstream file; // creiamo un oggetto ifstream per aprire qui il file .txt ed estrarre i dati
    file.open(inputFilePath);
    if(file.fail()){
        //cerr<<"C'è stato n'errore"; c'è gia sopra
        return false;
    }
    getline(file,text);
    file.close();
  return true;
}

bool Encrypt(const string& text,
             const string& password,
             string& encryptedText)
{
  int n=text.length();
  int m=password.length();// sintassi per lunghezza stringa
  encryptedText=""; // stringa vuota
  int i;// dichiariamo i contatori
  int An1; // ASCII number
  int j=0;
  char A;
  for(i=0;i<n;i++)
  {
      A=text[i];
      if(A!=' ')
      {
          An1=((int(A)-65)+(int(password[j])-65))%26 +65; // normalizziamo con A=0 e Z=25
          A=An1;
          j=(j+1)%m;
          encryptedText=encryptedText+A;
          }
      else {
          encryptedText=encryptedText+text[i];
      }

  }


  return true;
}

bool Decrypt(const string& text,
             const string& password,
             string& decryptedText)
{
    int n=text.length();
    int m=password.length();// sintassi per lunghezza stringa
    decryptedText=""; // stringa vuota
    int i;// dichiariamo i contatori
    int An1; // ASCII number
    int j=0;
    char A;
    for(i=0;i<n;i++)
    {
        A=text[i];
        if(A!=' ')
        {
            An1=((int(A)-65)-(int(password[j])-65)+26)%26 +65; // vedere teoria dietro sul quaderno, +26 per fare calcoli con positivi
            A=An1;
            j=(j+1)%m;
            decryptedText=decryptedText+A;
            }
        else {
            decryptedText=decryptedText+text[i];
        }

     }
  return  true;
}
