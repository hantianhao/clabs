#include<stdio.h>
int main()

{
    {
    printf("celsius fahr\n");
    } 
    int celsius, fahr;
    int lower, upper, step;
    
    upper = 100;
    lower = 0;
    step = 5;
    

    celsius = lower;
    while (celsius <= upper) {
        fahr = 32+(9*celsius/5);
        printf("%d\t%d\n", celsius, fahr);
        celsius = celsius + step;
    }
}    