#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    int delta = atoi(argv[1]);
    srand(time(NULL)+delta);
    for (int i=0; i<30; i++)
       printf("%d\n", rand()%16);
}
for i in $(seq -30 1 30); do echo $i; ./a.out $i | nc 2019shell1.picoctf.com 45107; done