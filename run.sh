gcc -c say.c
if cobc -x -o hello hello.cob say.o; then
./hello
echo "Done!"
ls
rm -rf hello
rm -rf *.o
fi