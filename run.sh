# echo "Starting Compile"
if gcc -l python2.7 -I /usr/include/python2.7/ pythonproxy.c -c ; then
    # echo "pythonproxy.c is compiled"
    if cobc -x -o hello hello.cob pythonproxy.o -l python2.7 ; then
        # echo "hello.cob is compiled"
        ./hello
        rm -rf hello
        rm -rf *.o
    # else
        # echo "error compiling hello.cob"
    fi
# else
    # echo "error compiling pythonproxy.c"
fi
