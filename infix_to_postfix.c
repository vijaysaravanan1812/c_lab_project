
#include<stdio.h>
#include"stack.c"
#include"get_str.c"

int main()
{
    char line[30];
    get(line);
    printf("%s \n",line);
    push(15);
    push(20);
    printf("%d\n",peek());
    return 0;

}