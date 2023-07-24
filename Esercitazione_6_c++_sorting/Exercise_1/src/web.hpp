#ifndef __WEB_H
#define __WEB_H

#include "iostream"
#include "list"
#include "Eigen/Eigen"
#include "map"

using namespace std;
using namespace Eigen;

namespace WebLibrary {

  struct Page
  {
      string url;
      string htmlContent;
      double rank;

      Page(const string& url):
        url(url){};
  };


  struct Server
  {
      vector<Page> pages;
      Server(vector<string> urls);

      void CreateHtmlContent(const string& url,
                             const string& content);
  };

  struct Surfer
  {
      Server server;

      Surfer(const Server& server);

      MatrixXd computeAdiacencyMatrix();

  };

}

#endif // __WEB_H
