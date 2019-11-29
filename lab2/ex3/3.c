#include<stdio.h>
int main()
{
    printf("输入一个16进制的非负整数:");
    int c = getchar();
    int a,b,d,n;
    int x  = 0;
    int s = 16;
    if(c  = '0')
    {
        c = getchar();
        if(c = ('x' ||'X'))
        {
            c = getchar();
            while(c != '\n')
            {
                if(c >='0' && c <='9')
                {
                    a = c - '0';
                    x = x *s + a;
                }
                else if(c >='a' && c <='f')
                {
                    b = c -'W';
                    x = x * s + b;
                }
                else if(c >='A' && c <='F')
                {
                    d = c - '7';
                     x = x * s + d;
                }
                else
                {
                    x = -1;
                    printf("输入了不合法的字符\n");
                    break;
                }
                c = getchar();
            }
        }
        else
        printf("输入了不合法的字符\n");
    }
    else
    printf("输入了不合法的字符\n");
    if(x != -1)
    printf("10进制式：%d\n",x);
}
