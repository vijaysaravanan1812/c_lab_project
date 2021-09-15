//Program to check whether string is digit or operator

#include<stdio.h>
#include<stdlib.h>

int isoperator(char C)
{
	return (C == '+' || C == '-' || C == '*' || C == '/' || C == '^');
}

// A utility function to check if 
// the given character is operand 
int isOperand(char ch) 
{ 
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' &&  ch <= '9'); 
} 