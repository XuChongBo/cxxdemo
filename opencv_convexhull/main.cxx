#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <fstream>
#include <iostream>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
    Mat img(500, 500, CV_8UC3);
    RNG& rng = theRNG();

    for(;;)
    {
        char key;
        int i, count = (unsigned)rng%100 + 1;

        vector<Point> points;

        for( i = 0; i < count; i++ )
        {
            Point pt;
            pt.x = rng.uniform(img.cols/4, img.cols*3/4);
            pt.y = rng.uniform(img.rows/4, img.rows*3/4);

            points.push_back(pt);
        }

        vector<int> hull;
        /*
        convexHull
        第一个参数是要求凸包的点集，
        第二个参数是输出的凸包点，
        第三个参数是一个bool变量，表示求得的凸包是顺时针方向还是逆时针方向，true是顺时针方向。

        注意：第二个参数可以为vector<int>，此时返回的是凸包点在原轮廓点集中的索引，
                        也可以为vector<Point>，此时存放的是凸包点的位置。 

        OpenCV中求凸包的算法参见paper： Sklansky, J., Finding the Convex Hull of a Simple Polygon. PRL 1 $number, pp 79-83 (1982)
        */
        convexHull(Mat(points), hull, true);

        img = Scalar::all(0);
        for( i = 0; i < count; i++ )
            circle(img, points[i], 3, Scalar(0, 0, 255), CV_FILLED, CV_AA);

        int hullcount = (int)hull.size();
        Point pt0 = points[hull[hullcount-1]];

        for( i = 0; i < hullcount; i++ )
        {
            Point pt = points[hull[i]];
            line(img, pt0, pt, Scalar(0, 255, 0), 1, 8);
            pt0 = pt;
        }

        imshow("hull", img);

        key = (char)waitKey();

        // fill hull
        vector<vector<Point> > contours(1);
        for( i = 0; i < hullcount; i++ ) {
            Point pt = points[hull[i]];
            contours[0].push_back(pt);
        }
        
        drawContours(img, contours, 0, Scalar(255), CV_FILLED);

        imshow("fill", img);
        key = (char)waitKey();

        if( key == 27 || key == 'q' || key == 'Q' ) // 'ESC'
            break;
    }

    return 0;
}



