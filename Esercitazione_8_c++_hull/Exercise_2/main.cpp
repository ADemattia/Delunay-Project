#include "test_convexHull.hpp"

#include <gtest/gtest.h>

int main(int argc, char *argv[])
{
    //::testing::InitGoogleTest(&argc, argv);
    //return RUN_ALL_TESTS();
    unsigned int numPoints = 0;
    vector<Point> points = {Point(2, 2, numPoints++),
                            Point(2.8, 1.7, numPoints++),
                            Point(3, 5, numPoints++),
                            Point(7, 3, numPoints++),
                            Point(7.2, 5, numPoints++),
                            Point(11, 4.3, numPoints++),

                            };

    unsigned int a=0;
    unsigned int b=numPoints-1;
    vector<Point> convexHull =ConvexHull(points,a,b);
    cout<<endl;
    Point A=convexHull[0];
    cout<<endl;
    cout<<"SUCC:"<<endl;
    cout<<"**"<<points[1].succ->id<<endl;
    for(unsigned int i=0; i<convexHull.size();i++)
    {
        if(convexHull[i].succ!=nullptr){
            cout<<i<<"--succ:"<<convexHull[i].succ->id<<endl;

        }
    }





return 0;

}
