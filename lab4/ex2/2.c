#include<stdio.h>
#include<stdlib.h>

#include<ctype.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
double val[MAXOP];
int sp = 0;

int main()
{
    int type,a,x;
    a = x =  0;
    double op2,i,j;
    char s[MAXOP];
    printf("输入100位以内的数元素，每个元素以空格符间隔:\n");
    while((type = getop(s)) != EOF)
    {
        switch(type)
        {
            case NUMBER:
            push(atof(s));
            break;
            case '+':
            push(pop() + pop());
            break;
            case '*':
            push(pop() * pop());
            break;
            case '-':
            op2 = pop();
            push(pop() - op2);
            break;
            case '/':
            op2 = pop();
            if(op2 != 0.0)
            push(pop() / op2);
            else
            printf("error: zero divisor\n");
            break;
            case '%':
            op2 = pop();
            if((int) op2 != 0)
            push((int) pop() % (int) op2);
            else
            printf("error: zero divisor\n");
            break;
            case 'P':
            printf("%g\n",val[sp-1]);
            break;
            case 'D':
            i = pop();
            push(i);
            push(i);
            i = 0;
            break;
            case 'C':
            i = pop();
            j = pop();
            push(i);
            push(j);
            i = j = 0;
            break;
            case 'R':
            while(val[a] !='\0')
            {
                val[a++] = '\0';
            }
            break;
            case'E':
            while(printf("%g ",val[x++]))
            ;
            x = 0;
            printf("\n");
            break;
            case '\n':
            printf("命令：【P】打印栈顶元素；【D】复制栈顶元素；【C】交换栈顶两个元素；【R】清空栈; 【E】打印所有栈元素\n");
        }
    }
    return 0;
}

void push(double f)
{
    if(sp < MAXOP)
    val[sp++] = f;
    else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if(sp > 0)
    return val[--sp];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c, a, b;
    i = 0;

    while((s[0] = c = getch()) == ' ' || c == '\t')
    ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.' && c != '-')
    return c;
    if(c == '-' && !isdigit(b = getch()))
    {
        ungetch(b);
        return c;
    }
    if(isdigit(c))
    while(isdigit(s[++i] = c = getch()))
    ;
    else
    {
        s[++i] = b;
        while(isdigit(s[++i] = c = getch()))
        ;
    }
    if(c == '.')
    while(isdigit(s[++i] = c = getch()))
    ;
    s[i] = '\0';
    if(c != EOF)
    ungetch(c);
    return NUMBER;
}

char buf[MAXOP];
int bufp = 0 ;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= MAXOP)
    printf("ungetch: too many characters\n");
    else
    buf[bufp++] = c;
}