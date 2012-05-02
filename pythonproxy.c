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
    printf("%s\n", hello, world);
    return 12345;
}

int
python(char *hello, char *world){
    printf("Inside C: %s\n", hello, world);
}
