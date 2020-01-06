#include<stdio.h>
int main()
{
    int a = 1;
    int b = 0;
    int c = 0;
    printf("请输入五位以内的正整数:");
    scanf("%d", &c);
    while(c)
    {
        b = c%2;
        c = c/2;
        if(b == 1)
        ++a;
    }
    printf("二进制化后数中1的个数：%d\n",a);
}