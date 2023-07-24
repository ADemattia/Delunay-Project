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

  Surfer surfer(server);
  MatrixXd adjacencyMatrix = surfer.computeAdjacencyMatrix();

  unsigned int numPages = server.pages.size();
  MatrixXd test_adjacencyMatrix(numPages, numPages);
  test_adjacencyMatrix << 0, 1, 1, 1, 0, 0,
      0, 0, 0, 0, 0, 0,
      1, 1, 0, 0, 0, 0,
      0, 1, 0, 0, 1, 1,
      1, 0, 0, 0, 0, 0,
      0, 1, 0, 1, 0, 0;

  EXPECT_EQ(adjacencyMatrix, test_adjacencyMatrix);


  MatrixXd googleMatrix = MatrixXd::Zero(numPages, numPages);

  VectorXd degree = adjacencyMatrix.rowwise().sum();
  for(unsigned int i = 0; i < numPages; i++)
    googleMatrix.row(i) = (degree(i) == 0) ? VectorXd::Constant(numPages, 1.0 / numPages) : VectorXd(adjacencyMatrix.row(i)/degree(i));


  double dampingFactor = 0.85;
  VectorXd personalizationVector = VectorXd::Constant(numPages, 1.0 / numPages);
  googleMatrix = dampingFactor * googleMatrix + (1.0 -  dampingFactor) * VectorXd::Ones(numPages) * personalizationVector.transpose();

  EigenSolver<MatrixXd> eig(googleMatrix.transpose());
  VectorXcd eigenvalues = eig.eigenvalues();
  int index_pr = -1;
  unsigned int count_eig_less = 0;
  for (unsigned int i = 0; i < numPages; i++)
  {
    double modulus = abs(eigenvalues[i]);
    if (abs(modulus - 1.0) <= 1.0e-12)
      index_pr = i;
    else if (modulus <= dampingFactor)
      count_eig_less++;
    else
      throw runtime_error("The generalized google matrix is wrong");
  }

  EXPECT_NE(index_pr, -1);
  EXPECT_EQ(count_eig_less, numPages - 1);

  VectorXd pagerank = eig.eigenvectors().col(index_pr).real();

  EXPECT_LE(eig.eigenvectors().col(index_pr).imag().norm(), 1.0e-12);

  for(unsigned int i = 0; i < numPages; i++)
    server.pages[i].rank = pagerank[i];

  vector<Page> rank = SelectionSort<Page>(server.pages);
  EXPECT_EQ(rank[0].url, "https://www.polito.it/themes/custom/polito/logo_meta.png");
}


#endif // __TEST_PAGERANK_H
