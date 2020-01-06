#include<stdio.h>

int main()
{
    printf("请输入一个有效格式的16进制数:\n");
    unsigned int c ;
    unsigned int a = 0;
    unsigned int x = 0;
    unsigned int b;
    b = x-1;
    if((c = getchar()) == '0')
    {
        if((c = getchar()) == 'X' || c == 'x')
        {
            while((c = getchar()) != '\n')
            {
                if(c >= '0' && c <= '9')
                {
                    a = a * 16 + (c - '0');
                }
                else if(c >= 'A' && c <= 'F')
                {
                    a = a * 16 + (c - '7');
                }
                else if(c >= 'a' && c <= 'f')
                {
                    a = a *16 + (c - 'W');
                }
                else
                {
                    a = -2;
                    break;
                }
            }

            if(a < b && a >= 0)
            {
                printf("10进制转化后得:%u\n",a);
            }
            else if(a == -2 )
            printf("输入内容错误\n");
            else
            {
                printf("输入过大数字,请更改为更小的数字\n");
                printf("转化后可得到的最大值为:%u\n",x-1);
            }
        }
        else
        printf("输入格式错误\n");
    }
    else
    printf("输入格式错误\n");
}