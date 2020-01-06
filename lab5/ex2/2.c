#include<stdio.h>
#include<ctype.h>

#define SIZE 100

float getch(void);
void ungetch(float);
int getfloat(float *pn);

int main()
{
    printf("输入任意数量浮点数，各浮点数间以空格间隔:\n");
    float a, c;
    a = c = 0.0;
    while(getfloat(&c) != EOF)
    a = a + c;
    printf("所有浮点数求和可得:%f\n",a);
}

char buf[SIZE];
int bufp = 0 ;

float getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(float c)
{
    if(bufp >= SIZE)
    printf("ungetch: too many characters\n");
    else
    buf[bufp++] = c;
}

int getfloat(float *pn)
{
    float c,  sign;
    if(c == '\n')
    return EOF;
    while(isspace(c = getch()))
    ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1.0 : 1.0;
    if(c == '+' || c == '-')
    c = getch();
    for(*pn = 0; isdigit(c) || c == '.';c = getch())
    {
        if(isdigit(c))
        *pn = 10 * *pn + (c - '0');
        else
        {
            c = getch();
            break;
        }
    }
    int a;
    for(a = 10;isdigit(c);c = getch())
    {
        *pn = *pn + (c - '0')/a;
        a = a * 10;
    }
    *pn *= sign;
    if(c != '\n')
    {
        ungetch(c);
        return c;
    }
    else
    return c;
}