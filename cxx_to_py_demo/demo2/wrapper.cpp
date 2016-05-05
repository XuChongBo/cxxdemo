#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Python.h>

using namespace std;


string getContent(string image_path, string model_dir, string log_file) {
    //ofstream logfile(log_file.c_str(), ios_base::app);
    string result = "xxxx";
    return result;
}



PyObject* WrapProcessor(PyObject* self, PyObject* args) {
    const char* a;
    const char* b;
    const char* c;
    if (!PyArg_ParseTuple(args, "sss", &a, &b, &c))
        return NULL;
    string image_file(a);
    string model_path(b);
    string log_file(c);
    string result = getContent(image_file, model_path, log_file);
    return Py_BuildValue("s", result.c_str());
}


static PyMethodDef ocrMethods[] = {
    {"getContent", WrapProcessor, METH_VARARGS},
    {NULL, NULL}
};

extern "C" {
    void initocr() {
        PyObject* m;
        m = Py_InitModule("ocr", ocrMethods);
    }
}
