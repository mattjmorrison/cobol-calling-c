#include <stdio.h>

char*
say(char *hello, char *world)
{
    printf("Starting C\n");
    printf("%s\n", hello, world);
    printf("Leaving C\n");
    char *x = "These are some chars";
    return x;
}
