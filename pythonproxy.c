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
getint(char *cobolParams){ // 2 vars PIC X(6)
    char *first, *second;
    first = cobolParams + 5;
    *first = 0;
    first++;
    second = cobolParams;

    printf("HELLO: %s\n", first);
    printf("WORLD: %s\n", second);
    return 12345;
}

PyObject*
getPythonModule(char *name){
    PyObject *pythonModuleName = PyString_FromString(name);
    PyObject *pythonModule = PyImport_Import(pythonModuleName);
    Py_DECREF(pythonModuleName);
    if (pythonModule == NULL) {
        PyErr_Print();
        fprintf(stderr, "Failed to load sample\n");
    }
    
    return pythonModule;
}

void
callPythonFunction(PyObject *module, char *functionName){
    PyObject *pythonFunction = PyObject_GetAttrString(module, functionName);
    PyObject_CallObject(pythonFunction, PyTuple_New(0));
    Py_DECREF(pythonFunction);
    Py_DECREF(module);
}

int
python(char *cobolParams){
    //TODO write common way to extract COBOL args
    char *moduleName, *functionName;
    functionName = cobolParams + 6;
    *functionName = 0;
    functionName++;
    moduleName = cobolParams;

    printf("Starting C\n");
    Py_Initialize();
    PyRun_SimpleString(
        "import sys\n"
        "sys.path.append('/Users/mattjmorrison/Projects/coboltest')\n"
    );
    PyObject *pythonModule = getPythonModule(moduleName);
    if (pythonModule == NULL) {
        return 1;
    }
    else {
        callPythonFunction(pythonModule, functionName);
    }

    Py_Finalize();
    printf("Ending C\n");
    return 0;
}
