#include <stdio.h>
//#include <Python.h>

char*
say(char *hello, char *world)
{
    printf("Starting C\n");
    printf("%s\n", hello, world);
    //Py_Initialize();
    //PyRun_SimpleString("from time import time, ctime\n"
    //                   "print 'Today is', ctime(time())\n")
    //Py_Finalize();
    printf("Leaving C\n");
    char *x = "These are some chars";
    return x;
}
