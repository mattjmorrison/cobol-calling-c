#include <Python.h>
#include <stdio.h>

char*
getstring(char *hello, char *world)
{
    printf("Starting C\n");
    printf("%s\n", hello, world);
    Py_Initialize();
    PyRun_SimpleString(
            "print 'Starting Python'\n"
            "from time import time, ctime\n"
            "print 'Today is', ctime(time())\n"
            "print 'Leaving Python'\n");
    Py_Finalize();
    printf("Leaving C\n");
    char *x = "These are some chars";
    return x;
}

int
getint(char *hello, char *world){
    printf("HELLO: %s\n", hello);
    printf("WORLD: %s\n", world);
    return 12345;
}

int
python(char *moduleName, char *functionName){
    printf("Starting C\n");
    Py_Initialize();
    PyRun_SimpleString(
        "import sys\n"
        "sys.path.append('/Users/mattjmorrison/Projects/coboltest')\n"
    );
    PyObject *pythonModuleName = PyString_FromString("sample");
    PyObject *pythonModule = PyImport_Import(pythonModuleName);
    if (pythonModule != NULL) {
        Py_DECREF(pythonModuleName);
        PyObject *pythonFunction = PyObject_GetAttrString(pythonModule, "mysample");
        PyObject_CallObject(pythonFunction, PyTuple_New(0));
        Py_DECREF(pythonFunction);
        Py_DECREF(pythonModule);
    }
    else {
        PyErr_Print();
        fprintf(stderr, "Failed to load sample\n");
        return 1;
    }

    Py_Finalize();
    printf("Ending C\n");
    return 0;
}
