#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "opencv2/opencv.hpp"
#include "ocr_interface.h"

#include <Python.h>

using namespace std;

string process_image(string image_path, string model_dir, string log_file) {
    ofstream logfile(log_file.c_str(), ios_base::app);
    TWOCR tw_ocr;
    bool inited = tw_ocr.init(model_dir);
    if (!inited) {
        logfile << "Failed to init ocr, please check it. model_dir: " << model_dir << endl;
        return "";
    }

    stringstream result;
    TWOCRResult tw_ocr_result;
    bool ret = tw_ocr.recognize(image_path, tw_ocr_result);
    // 兼容旧接口，language = 1 表示中文，2 表示英文
    result << tw_ocr_result.language + 1 << "\t" << tw_ocr_result.final_result;

    if (tw_ocr_result.msg != "") {
        logfile << "image path: " << image_path << ", info: " << tw_ocr_result.msg << endl;
    }
    return result.str();
}

PyObject* WrapProcessor(PyObject* self, PyObject* args) {
    const char* image_path;
    const char* model_dir;
    const char* log_path;
    if (!PyArg_ParseTuple(args, "sss", &image_path, &model_dir, &log_path))
        return NULL;
    string image_file(image_path);
    string model_path(model_dir);
    string log_file(log_path);
    string result = process_image(image_file, model_path, log_file);
    return Py_BuildValue("s", result.c_str());
}

static PyMethodDef ocrMethods[] = {
    {"process_image", WrapProcessor, METH_VARARGS},
    {NULL, NULL}
};

extern "C" {
    void initocr() {
        PyObject* m;
        m = Py_InitModule("ocr", ocrMethods);
    }
}
