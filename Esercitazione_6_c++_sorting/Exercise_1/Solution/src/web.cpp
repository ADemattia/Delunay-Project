#include "web.hpp"

namespace WebLibrary {

  Server::Server(vector<string> urls)
  {
    this->pages.reserve(urls.size()); //accede a variabile di tale oggetto creato (this puntatore a se stesso) e riserva spazio a vettore di cui non si conosce a priori dimensione e si assegna a partire dai dati
    for(auto it = urls.begin(); it != urls.end(); it++) // fa scorrere iteratore su numero elementi vettore senza conoscere il numero di elementi con .begin() e .end()
    {
      Page page(*it); //inseriamo indirizzi, derefenzia it che è un indicatore (puntatore) al vettore ottenendo l'url così si va a riempire server con delle pagine inizializzate con il costruttore di page con il solo dato url (che è una stringa)
      this->pages.push_back(page); //inserimento in fondo in vettore
    }
  }


  void Server::CreateHtmlContent(const string& url,
                         const string& content) //diamo url e html content
  {
    Page page(url);
    auto it = find(pages.begin(), pages.end(), page); //cerca nel vettore con un inizio e una fine, lo facciamo perchè non sappiamo a priori il numero di elementi nel vettore
    if( it != pages.end() ) //it != pages.end() vuol dire che è stato trovata una pagina, inizializzata con il costruttore page(url)
      it -> htmlContent = content; //entriamo nella pagina e modifichiamo l'htmlContent
  }

  Surfer::Surfer(const Server& server): //usiamo sempre sintassi con scope "::" per andare ad accedere alle function o variabili specifiche della struct o della classe (quando è esterno o quando c'è ambiguità con classi Base) ser invece istanziamo un oggetto (classe) e vogliamo accedere ad una sua varibile/funzione pubblica usiamo il punto . oppure se andiamo tramite puntatore utilizziamo ->
    server(server) //inizializziamo Surfer riempiendo solo la variabile di Server
  {
  }

  MatrixXd Surfer::computeAdjacencyMatrix()
  {
      unsigned int numPages = server.pages.size(); //entriamo in vettore del server chiamato pages e calcoliamo la dimensione
      MatrixXd adjacencyMatrix = MatrixXd::Zero(numPages, numPages); //inizializziamo la matrice con i comandi appositi dandogli una dimensione

      for(unsigned int i = 0; i < numPages; i++)
      {
        istringstream split(server.pages[i].htmlContent);
        string neighbor;
        while(split >> neighbor) //finchè ciò che è preso da split non è nullo, ogni presa di token si ferma allo spazio
        {
          Page page(neighbor);
          auto it = find(server.pages.begin(), server.pages.end(), page); //cerca i link tra le pagine
          if (it ==  server.pages.end())
            throw runtime_error("Not a valid page"); //se url di htmlcontent non si trova in nessuna pagina

          unsigned int index = it - server.pages.begin();
          adjacencyMatrix(i, index) = 1;
        }
      }

      return adjacencyMatrix;
  }


}
