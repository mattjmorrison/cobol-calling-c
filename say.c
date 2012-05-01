#include <stdio.h>
//#include <Python.h>

char*
getstring(char *hello, char *world)
{
    printf("Starting C\n");
    printf("%s\n", hello, world);
    //Py_Initialize();
    //mod = Py_Import("mod")
    //Py_GetAttr(mod, 'somefunc')
    // Py_CallFunc(mod, func, args, kwargs)
    //PyRun_SimpleString("from time import time, ctime\n"
    //                   "print 'Today is', ctime(time())\n")
    //Py_Finalize();
    printf("Leaving C\n");
    char *x = "These are some chars";
    return x;
}

int
getint(char *hello, char *world){
    printf("%s\n", hello, world);
    return 12345;
}
