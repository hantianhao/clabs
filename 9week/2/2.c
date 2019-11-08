#include<stdio.h>
int main()
{
    printf("请输入五位以内的正整数:");
    char a;
    int c = 1;
    int d = 0;
    unsigned int b = 0;
    while(( a = getchar()) != '\n')
    {
        b = b*10 +(a - '0');
    }
    while(b > 0)
    {
        if(b & c != 0)
        {
            d++;
        }
        b = b >> 1;
    }
    printf("该数二进制值中1的个数:%d\n",d);
}