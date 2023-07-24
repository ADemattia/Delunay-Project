#include "web.hpp"

namespace WebLibrary {

  Server::Server(vector<string> urls)
  {

  }


  void Server::CreateHtmlContent(const string& url,
                           const string& content)
  {

  }

  Surfer::Surfer(const Server& server):
    server(server)
  {
  }

  MatrixXd Surfer::computeAdiacencyMatrix()
  {

    return MatrixXd();
  }


}
