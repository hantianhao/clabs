#include<stdio.h>
#define MAXLINE 200

int getl(char s[], char t[], int max);
int strindex(char s[], char t[]);

main()
{
    char s[MAXLINE];
    char t[MAXLINE];
    printf("请输入待查找段与查找段，中间用单个空格连接:\n");
    if(getl(s,t,MAXLINE) > 0)
    printf("位置为:%d\n",strindex(s,t));
    else
    printf("not found");
}

int getl(char s[], char t[], int lim)
{
    int c, i, j;
    i = j = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n' && c != ' ')
    s[i++] = c;
    if(c == ' ')
    while(--lim >0 && (c = getchar()) != EOF && c != '\n')
    t[j++] = c;
    if(c == '\n')
    s[i] = t[j] = 0;
    return i;
}

int strindex(char s[], char t[])
{
    int i, j, k,p;
    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
        ;
        if(k > 0 && t[k] == '\0')
        p = i;
    }
    if(p >= 0)
    return p;
    else
    return -1;
}