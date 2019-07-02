#include <Python.h>
#include <stdio.h>
#include <string.h>

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

char *
callPythonFunction(PyObject *module, char *functionName, char *arguments){
    PyObject *pythonFunction = PyObject_GetAttrString(module, functionName);
    PyObject *args = PyTuple_New(1);
    PyTuple_SetItem(args, 0, PyString_FromString(arguments));
    PyObject *returned = PyObject_CallObject(pythonFunction, args);
    Py_DECREF(args);
    Py_DECREF(pythonFunction);
    Py_DECREF(module);
    return PyString_AsString(returned);
}

int
python(char *cobolParams){
    char *moduleName, *functionName, *arguments, *reply;
    int delim = '|';
    functionName = strchr(cobolParams, delim);
    *functionName = 0;
    *functionName++;
    arguments = strchr(functionName, delim);
    *arguments = 0;
    *arguments++;
    reply = strchr(arguments, delim);
    *reply = 0;
    *reply++;
    moduleName = cobolParams;

    Py_Initialize();
    PyObject *pythonModule = getPythonModule(moduleName);
    if (pythonModule == NULL) {
        return 1;
    }
    else {
        char *d = callPythonFunction(pythonModule, functionName, arguments);
        strcpy(reply, d);
        return 0;
    }

    Py_Finalize();
    return 0;
}
