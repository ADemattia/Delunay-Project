#ifndef __TEST_PAGERANK_H
#define __TEST_PAGERANK_H

#include <gtest/gtest.h>
#include "iostream"
#include "sorting.hpp"
#include "web.hpp"
#include "complex"

using namespace testing;
using namespace std;
using namespace SortLibrary;
using namespace WebLibrary;


TEST(TestSorting, TestSelectionSort)
{
  vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
  vector<int> ssV = SelectionSort<int>(v);
  vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
  EXPECT_EQ(ssV, sortedV);
}

TEST(TestSorting, TestInsertionSort)
{
  vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
  vector<int> ssV = InsertionSort<int>(v);
  vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
  EXPECT_EQ(ssV, sortedV);
}

TEST(TestPageRank, TestPageRank)
{

  vector<string> urls = { "https://www.polito.it",
                          "https://www.polito.it/themes/custom/polito/logo_meta.png",
                          "https://www.polito.it/en",
                          "https://www.polito.it/ateneo/qualita",
                          "https://www.coronavirus.polito.it/it",
                          "https://www.polito.it/impatto-sociale/masterplan"
                        };

  Server server(urls);

  server.CreateHtmlContent("https://www.polito.it",
                "https://www.polito.it/themes/custom/polito/logo_meta.png https://www.polito.it/en https://www.polito.it/ateneo/qualita");
  server.CreateHtmlContent("https://www.polito.it/themes/custom/polito/logo_meta.png","");
  server.CreateHtmlContent("https://www.polito.it/en",
                "https://www.polito.it https://www.polito.it/themes/custom/polito/logo_meta.png");
  server.CreateHtmlContent("https://www.polito.it/ateneo/qualita",
                "https://www.polito.it/themes/custom/polito/logo_meta.png https://www.coronavirus.polito.it/it https://www.polito.it/impatto-sociale/masterplan");
  server.CreateHtmlContent("https://www.coronavirus.polito.it/it","https://www.polito.it");
  server.CreateHtmlContent("https://www.polito.it/impatto-sociale/masterplan",
                "https://www.polito.it/themes/custom/polito/logo_meta.png https://www.polito.it/ateneo/qualita");

  unsigned int numPages = 6;
  MatrixXd test_adjacencyMatrix(numPages,numPages);
  test_adjacencyMatrix << 0, 1, 1, 1, 0, 0,
      0,0,0,0,0,0,
      1,1,0,0,0,0,
      0,1,0,0,1,1,
      1,0,0,0,0,0,
      0,1,0,1,0,0;

  MatrixXd adjacencyMatrix = MatrixXd::Zero(numPages,numPages);

  EXPECT_EQ(adjacencyMatrix, test_adjacencyMatrix);

}


#endif // __TEST_PAGERANK_H
