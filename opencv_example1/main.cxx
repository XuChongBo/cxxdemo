#include <stdio.h>
#include <opencv2/opencv.hpp>

using namespace cv;
string text = "are we cute?  hahha";
int fontFace = FONT_HERSHEY_SCRIPT_SIMPLEX;
int baseline=0;
double fontScale = 2;
int thickness = 3;
Size textSize = getTextSize(text, fontFace,
fontScale, thickness, &baseline);

int main( int argc, char** argv )
{
  Mat image;
  image = imread( argv[1], 1 );
  imshow("xx", image);
  waitKey(0);
  return 0;
}
