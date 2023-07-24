#ifndef __WEB_H
#define __WEB_H

#include "iostream"
#include "list"
#include "Eigen/Eigen"
#include "map"

using namespace std;
using namespace Eigen;

namespace WebLibrary {

  struct Page //struct, page è una struct
  {
      string url;
      string htmlContent; //html content sono le pagine (identificate da url) a cui punta
      double rank;

      Page(const string& url):
        url(url){}; //costruttore, attenzione a sintassi, assegna valore solo a url
  };

  inline bool operator==(const Page &page1, const Page &page2) //operatore booleano di ugualianza  che viene usato come funzione inline, ovvero non richiamta nel codice ma copiata dove serve, si usa solitamente quando la funzione è breve
  {
    return page1.url == page2.url; //confrontiamo la variabile stringa url presente nelle due Page, le Page sono passete tramite referenza
  }

  inline bool operator!=(const Page &page1, const Page &page2) //operatore booleano inline di disugualizanza inizializzat come inline
  {
    return !(page1 == page2); //ritorna il negativo della funzione ugualianza bool definita prima
  }

  inline bool operator<(const Page &page1, const Page &page2) //definizione operatore booleano di disugualianza fatto tra Page, confrontiamo i rank variabili dobule tenute nel Page, la funzione è dichiarata come inline
  {
    return page1.rank < page2.rank;
  }

  inline bool operator>(const Page &page1, const Page &page2) //stessa cosa di sopra, questa volta operatore maggiore
  {
    return page1.rank > page2.rank;
  }

  struct Server //definiamo una struct (struct==classe senza metodi e senza specificatore di acesso, server:= insieme di pagine
  {
      vector<Page> pages; //vettore di classi Page
      Server(vector<string> urls); //costruttore di Server che prende di parametri solo un vettore di stringhe

      void CreateHtmlContent(const string& url,
                             const string& content); //metodo funzionale di struct
  };

  struct Surfer //altra struttura surferr
  {
      Server server; //server

      Surfer(const Server& server); // costruttore della struct  che prende in input il parametro di server

      MatrixXd computeAdjacencyMatrix(); //metodo funzionale di struttura per creare la matrice di adiacenza

  };

}

#endif // __WEB_H
