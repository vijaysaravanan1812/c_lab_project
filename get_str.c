//To get line of strings

#include<stdio.h>
int n = 0,c;
char get(char *a)
{
    while ((c = getchar()) != '\n')
    {
        a[n] = c;
        n++;
    }
    a[n] = '\0';
}

