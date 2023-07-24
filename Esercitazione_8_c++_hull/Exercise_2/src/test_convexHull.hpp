#ifndef __TEST_CONVEXHULL_H
#define __TEST_CONVEXHULL_H

#include <gtest/gtest.h>
#include "iostream"
#include "sorting.hpp"
#include "convexHull.hpp"

using namespace testing;
using namespace std;
using namespace SortLibrary;
using namespace ConvexHullLibrary;


TEST(TestSorting, TestMergeSort)
{
  vector<int> v = {44, 25, 10, 31, 25, 48, 37, 43, 18, 48, 27};
  MergeSort<int>(v, 0, v.size()-1);
  vector<int> sortedV = {10, 18, 25, 25, 27, 31, 37, 43, 44, 48, 48};
  EXPECT_EQ(v, sortedV);
}

TEST(TestConvexHull, Test1Point)
{
  unsigned int numPoints = 0;
  vector<Point> points = { Point(2, 2, numPoints++) };

  vector<Point> convexHull = ConvexHull(points,0,points.size()-1);

  string convexHullToString;
  ostringstream convert(convexHullToString);

  for(unsigned int i = 0; i < convexHull.size(); i++)
    convert << convexHull[i] << " ";

  string rightConveHull = "0 ";

  EXPECT_EQ(convert.str(), rightConveHull);

}

TEST(TestConvexHull, Test2Points)
{
  unsigned int numPoints = 0;
  vector<Point> points = {Point(2, 2, numPoints++),
                          Point(2.8, 1.7, numPoints++)};

  vector<Point> convexHull = ConvexHull(points,0,points.size()-1);

  string convexHullToString;
  ostringstream convert(convexHullToString);

  for(unsigned int i = 0; i < convexHull.size(); i++)
    convert << convexHull[i] << " ";

  string rightConveHull = "0 1 ";

  EXPECT_EQ(convert.str(), rightConveHull);

}

TEST(TestConvexHull, Test3Points)
{
  unsigned int numPoints = 0;
  vector<Point> points = {Point(2, 2, numPoints++),
                          Point(3, 5, numPoints++),
                          Point(2.8, 1.7, numPoints++)};

  vector<Point> convexHull = ConvexHull(points,0,points.size()-1);

  string convexHullToString;
  ostringstream convert(convexHullToString);

  for(unsigned int i = 0; i < convexHull.size(); i++)
    convert << convexHull[i] << " ";

  string rightConveHull = "0 2 1 ";

  EXPECT_EQ(convert.str(), rightConveHull);

}

TEST(TestConvexHull, TestXPoints)
{
  unsigned int numPoints = 0;
  vector<Point> points = {Point(2, 2, numPoints++),
                          Point(2.8, 1.7, numPoints++),
                          Point(3, 5, numPoints++),
                          Point(7, 3, numPoints++),
                          Point(7.2, 5, numPoints++),
                          Point(11, 4.3, numPoints++),
                          Point(12, 5.2, numPoints++),
                          Point(14, 3, numPoints++)
                          };

  vector<Point> convexHull = ConvexHull(points,0,points.size()-1);

  string convexHullToString;
  ostringstream convert(convexHullToString);

  for(unsigned int i = 0; i < convexHull.size(); i++)
    convert << convexHull[i] << " ";

  string rightConveHull = "0 1 7 6 2 ";

  EXPECT_EQ(convert.str(), rightConveHull);

}

TEST(TestConvexHull, TestXFloatingPoints)
{
  unsigned int numPoints = 0;
  vector<Point> points = {Point(0.3215348546593775, 0.03629583077160248, numPoints++),
                          Point(0.02402358131857918, -0.2356728797179394, numPoints++),
                          Point(0.04590851212470659, -0.4156409924995536, numPoints++),
                          Point(0.3218384001607433, 0.1379850698988746, numPoints++),
                          Point(0.11506479756447, -0.1059521474930943, numPoints++),
                          Point(0.2622539999543261, -0.29702873322836, numPoints++),
                          Point(-0.161920957418085, -0.4055339716426413, numPoints++),
                          Point(0.1905378631228002, 0.3698601009043493, numPoints++),
                          Point(0.2387090918968516, -0.01629827079949742, numPoints++),
                          Point(0.07495888748668034, -0.1659825110491202, numPoints++),
                          Point(0.3319341836794598, -0.1821814101954749, numPoints++),
                          Point(0.07703635755650362, -0.2499430638271785, numPoints++),
                          Point(0.2069242999022122, -0.2232970760420869, numPoints++),
                          Point(0.04604079532068295, -0.1923573186549892, numPoints++),
                          Point(0.05054295812784038, 0.4754929463150845, numPoints++),
                          Point(-0.3900589168910486, 0.2797829520700341, numPoints++),
                          Point(0.3120693385713448, -0.0506329867529059, numPoints++),
                          Point(0.01138812723698857, 0.4002504701728471, numPoints++),
                          Point(0.009645149586391732, 0.1060251100976254, numPoints++),
                          Point(-0.03597933197019559, 0.2953639456959105, numPoints++),
                          Point(0.1818290866742182, 0.001454397571696298, numPoints++),
                          Point(0.444056063372694, 0.2502497166863175, numPoints++),
                          Point(-0.05301752458607545, -0.06553921621808712, numPoints++),
                          Point(0.4823896228171788, -0.4776170002088109, numPoints++),
                          Point(-0.3089226845734964, -0.06356112199235814, numPoints++),
                          Point(-0.271780741188471, 0.1810810595574612, numPoints++),
                          Point(0.4293626522918815, 0.2980897964891882, numPoints++),
                          Point(-0.004796652127799228, 0.382663812844701, numPoints++),
                          Point(0.430695573269106, -0.2995073500084759, numPoints++),
                          Point(0.1799668387323309, -0.2973467472915973, numPoints++),
                          Point(0.4932166845474547, 0.4928094162538735, numPoints++),
                          Point(-0.3521487911717489, 0.4352656197131292, numPoints++),
                          Point(-0.4907368011686362, 0.1865826865533206, numPoints++),
                          Point(-0.1047924716070224, -0.247073392148198, numPoints++),
                          Point(0.4374961861758457, -0.001606279519951237, numPoints++),
                          Point(0.003256207800708899, -0.2729194320486108, numPoints++),
                          Point(0.04310378203457577, 0.4452604050238248, numPoints++),
                          Point(0.4916198379282093, -0.345391701297268, numPoints++),
                          Point(0.001675087028811806, 0.1531837672490476, numPoints++),
                          Point(-0.4404289572876217, -0.2894855991839297, numPoints++)};

  vector<Point> convexHull = ConvexHull(points,0,points.size()-1);

  string convexHullToString;
  ostringstream convert(convexHullToString);

  for(unsigned int i = 0; i < convexHull.size(); i++)
    convert << convexHull[i] << " ";

  string rightConveHull = "32 39 6 23 37 30 14 31 ";

  EXPECT_EQ(convert.str(), rightConveHull);

}

#endif // __TEST_CONVEXHULL_H
