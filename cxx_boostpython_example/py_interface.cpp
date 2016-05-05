#include <iostream>
#include <string>
#include <opencv2/imgproc/imgproc.hpp>
#include <boost/python.hpp>
#include "doc_ocr_impl.h"
#include "conversion.h"
#include <boost/python.hpp>
#include <boost/python/suite/indexing/map_indexing_suite.hpp>
namespace py = boost::python;

typedef unsigned char uchar_t;

//http://www.boost.org/doc/libs/1_55_0/libs/python/doc/tutorial/doc/html/python/exposing.html



/**
 * Displays an image, passed in from python as an ndarray.
 */
void
display(PyObject *img)
{
    NDArrayConverter cvt;
    cv::Mat mat { cvt.toMat(img) };
    
    cv::namedWindow("display", CV_WINDOW_NORMAL);
    cv::imshow("display", mat);
    cv::waitKey(0);
}


/**
 * Converts a grayscale image to a bilevel image.
 */
PyObject*
binarize(PyObject *grayImg, short threshold)
{
    NDArrayConverter cvt;
    cv::Mat img { cvt.toMat(grayImg) };
    for (int i = 0; i < img.rows; ++i)
    {
        uchar_t *ptr = img.ptr<uchar_t>(i);
        for (int j = 0; j < img.cols; ++j)
        {
            ptr[j] = ptr[j] < threshold ? 0 : 255;
        }
    }
    return cvt.toNDArray(img);
}

/**
 * Multiplies two ndarrays by first converting them to cv::Mat and returns
 * an ndarray containing the result back.
 */
PyObject*
mul(PyObject *left, PyObject *right)
{
    NDArrayConverter cvt;
    cv::Mat leftMat, rightMat;
    leftMat = cvt.toMat(left);
    rightMat = cvt.toMat(right);
    auto r1 = leftMat.rows, c1 = leftMat.cols, r2 = rightMat.rows,
         c2 = rightMat.cols;
    // Work only with 2-D matrices that can be legally multiplied.
    if (c1 != r2)
    {
        PyErr_SetString(PyExc_TypeError, 
                        "Incompatible sizes for matrix multiplication.");
        py::throw_error_already_set();
    }
    cv::Mat result = leftMat * rightMat;

    PyObject* ret = cvt.toNDArray(result);

    return ret;
}

void save_to_lmdb(DocOCRStruct &ocr_collector)
{
    std::map<std::string, cv::Mat> ::iterator iter = ocr_collector.images.begin();
    for (; iter != ocr_collector.images.end(); iter++) {
        string name = iter->first;
        cv::Mat img = iter->second;
        //cv::imshow(name, img);
        cv::imwrite("/tmp/"+name+".png", img);

    }
    //cv::waitKey(0);

}

//====================================
std::string recognize_by_image_path(std::string  image_path, std::string model_dir) 
{


    DocOCRImpl impl = DocOCRImpl();
    bool inited = impl.init(model_dir);
    if (!inited) {
        cout << "ocr init Failed. model_dir: " << model_dir << endl;
        exit(-1);
    }
    Mat input_img = imread(image_path, 0);  //return a graylevel image
    bool ret = impl.recognize(input_img);
    cout<<"msg: "<<impl.ocr_collector.msg<<endl;

    save_to_lmdb(impl.ocr_collector);

    return impl.ocr_collector.final_result;

}

std::string recognize_by_cvmat(PyObject *img, std::string model_dir) 
{

    // DocOCRImpl tw_ocr;
    // bool inited = tw_ocr.init(model_dir);
    // if (!inited) {
    //     cout << "tw_ocr.init Failed. model_dir: " << model_dir << endl;
    //     exit(-1);
    // }
    // NDArrayConverter cvt;
    // cv::Mat m{ cvt.toMat(img) };

    // TWOCRResult ocr_collector;
    // tw_ocr.recognize(m, &tw_ocr_result);
    // cout<<"msg: "<<tw_ocr_result.msg<<endl;
    // return tw_ocr_result.final_result;
    return "hello";
}



//====================================
std::string recognize_tiku_answer_by_image_path(std::string  image_path, std::string model_dir) 
{

    // DocOCRImpl tw_ocr;
    // bool inited = tw_ocr.init(model_dir);
    // if (!inited) {
    //     cout << "Failed to load model_dir: " << model_dir << endl;
    //     exit(-1);
    // }

    // TWOCRResult tw_ocr_result;
    // Mat color_img = imread(image_path, 1);  //return a graylevel image
    // tw_ocr.recognize_tiku_answer(color_img, &tw_ocr_result);
    // cout<<"msg: "<<tw_ocr_result.msg<<endl;
    // return tw_ocr_result.final_result;
    return "tikuanswer";
}



//==

static void init()
{
    Py_Initialize();
    import_array();
}


///////////////////////

typedef map<string,int> simap;

simap A()
{
    simap m;
    m["aaa"] = 1;
    m["bbb"] = 2;
    m["ccc"] = 3;
    m["ddd"] = 4;
    m["eee"] = 5;
    m["fff"] = 6;

    return m;
}

struct MyStruct
{
    int a;
    std::string msg;
    PyObject *img;
};

MyStruct get_image(std::string image_path)
{
    Mat input_img = imread(image_path, 0);  //return a graylevel image
    MyStruct st;
    NDArrayConverter cvt;
    PyObject* ret = cvt.toNDArray(input_img);
    st.img = ret;
    st.a = 1223;
    st.msg = "hello";
    return st;
}
/////////////

BOOST_PYTHON_MODULE(ocr)
{
    init();
    py::def("display", display);
    py::def("binarize", binarize);
    py::def("mul", mul);
    py::def("recognize_by_image_path", recognize_by_image_path);
    py::def("recognize_by_cvmat", recognize_by_cvmat);
    py::def("recognize_tiku_answer_by_image_path", recognize_tiku_answer_by_image_path);


    py::class_<simap>("pySImap").def( py::map_indexing_suite<simap>() );

    py::class_<MyStruct>("MyStruct").def_readwrite("a", &MyStruct::a).def_readwrite("msg", &MyStruct::msg).def_readwrite("img", &MyStruct::img);

    py::def("a",A);

    py::def("get_image", get_image);

}
