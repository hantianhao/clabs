#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXOP 100

int getop(char []);
void push(double f);
double pop(void);

int main(int argc, char *argv[])
{
    int type;
    double op2;
    int a = 0;

    while(--argc > 0)
    {
        type = getop(argv[++a]);
        switch(type)
        {
            case NUMBER:
            push(atof(argv[a]));
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
            default:
            printf("error: unknown command \n");
            break;
        }  
    }
    printf("\t%.8g\n",pop());
    return 0 ;
}

int getop(char s[])
{
    if(isdigit(*s))
    return NUMBER;
    else
    return *s;
}

int sp = 0;
double val[MAXOP];

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