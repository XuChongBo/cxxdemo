# file "example_build.py"

# Note: we instantiate the same 'cffi.FFI' class as in the previous
# example, but call the result 'ffibuilder' now instead of 'ffi';
# this is to avoid confusion with the other 'ffi' object you get below

from cffi import FFI
ffibuilder = FFI()
import re

from cffi import FFI


ffi = FFI()

ffibuilder.set_source(
    "_mycv",
    """
    #include "opencv/cv.h"
    #include "opencv/highgui.h"
    #include "opencv2/core/types_c.h"
    """,
    libraries=[
        "opencv_highgui",
    ],
)


ffibuilder.cdef(
           re.sub(
           r"\bCVAPI\(([^)]+)\)",
           r"\1", 
           re.sub( r"\bCV_DEFAULT\([^)]+\)", "",
        
        """
/*
@deprecated CvMat is now obsolete; consider using Mat instead.
 */
typedef unsigned char uchar;
typedef struct CvMat {
    int type;
    int step;

    union
    {
        uchar* ptr;
        short* s;
        int* i;
        float* fl;
        double* db;
    } data;

    int rows;
    int cols;
    ...;
} CvMat;

#define CV_8UC3 ...
typedef void CvArr;
CVAPI(void) cvShowImage( const char* name, const CvArr* image ); 
CVAPI(CvMat*)  cvCreateMat( int rows, int cols, int type );
CVAPI(int) cvWaitKey(int delay CV_DEFAULT(0));

""",),),)

if __name__ == "__main__":
    ffibuilder.compile(verbose=True)
