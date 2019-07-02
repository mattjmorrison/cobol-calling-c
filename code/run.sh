#!/bin/bash
cd /code
if gcc -l python2.7 -I /usr/include/python2.7/ pythonproxy.c -c ; then
    if cobc -x -o hello hello.cob pythonproxy.o -l python2.7 ; then
        export PYTHONPATH=`pwd`
        ./hello
        rm -rf hello
        rm -rf *.o
    fi
fi
