//To get line of strings
#include<stdio.h>

char get(char *a)
{
    int n = 0,c;
    while ((c = getchar()) != '\n')
    {
        a[n] = c;
        n++;
    }
    a[n] = '\0';
}
char copystr(char *exp1,char *exp2)
{
    int i = 0;
    while(exp1[i] != '\0')
    {
        exp2[i] = exp1[i];
        i++;
    }
    exp2[i] = '\0';
    
} 

