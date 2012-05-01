gcc -c say.c
cobc -x -o hello hello.cob say.o
./hello
rm -rf hello
rm -rf *.o