//stack implimentation using dynamic array
#include<stdio.h>
int top = -1;
char s[100];

void push(char x) 
{ 
    top++;
	s[top]= x; 
} 

char pop() 
{  
	char x = s[top]; 
	top--;
    return x;
} 
char peek() 
{ 
    char x = s[top]; 
	return x;
} 



