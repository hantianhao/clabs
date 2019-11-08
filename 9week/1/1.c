#include<stdio.h>
int main()
{
    unsigned int a = 1;
    unsigned int b =0;
    while(a >0)
    {
        a = a<<1;
        b =b +1;
    }
    printf("最大值为:%u 位数为:%u\n",a-1,b);
}    