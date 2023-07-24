#ifndef __TEST_SORTING_H
#define __TEST_SORTING_H

#include <gtest/gtest.h>
#include "iostream"
#include "sorting.hpp"

using namespace testing;
using namespace std;
using namespace SortLibrary;

TEST(TestSorting, TestHeapSortIntBuiltIn)
{
  vector<int> v = {9, 13, 5, 10, 2, 7, 9, 4, 6, 12};
  vector<int> ssV = HeapSort<int>(v);
  vector<int> sortedV = {2, 4, 5, 6, 7, 9, 9, 10, 12 ,13};
  EXPECT_EQ(ssV, sortedV);
}

TEST(TestSorting, TestHeapSortDecreasingClass)
{
  vector<DecreasingInt> v = {DecreasingInt(9), DecreasingInt(13), DecreasingInt(5),
                             DecreasingInt(10), DecreasingInt(2), DecreasingInt(7),
                             DecreasingInt(9), DecreasingInt(4), DecreasingInt(6),
                             DecreasingInt(12)};
  vector<DecreasingInt> ssV = HeapSort<DecreasingInt>(v);
  vector<DecreasingInt> sortedV = {DecreasingInt(13), DecreasingInt(12), DecreasingInt(10),
                                 DecreasingInt(9), DecreasingInt(9), DecreasingInt(7),
                                 DecreasingInt(6), DecreasingInt(5), DecreasingInt(4), DecreasingInt(2)};

  EXPECT_EQ(ssV, sortedV);
}

#endif // __TEST_SORTING_H
