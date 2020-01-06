#include<stdio.h>
#include<stdlib.h>

#define MAX 100

int main(int argc, char *argv[])
{
    int a = 0;
    double b;
    int c = argv[++a];
    while((--argc) > 0 )
    {
        if(c > (b = atof(argv[a])))
        c = b;
        a++;
    }
    printf("%d\n",c);
}