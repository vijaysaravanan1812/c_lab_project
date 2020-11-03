// C program to evaluate value of a postfix expression 
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include"infix_to_postfix.c"

// Stack type 
int stack[50];
int top = -1;

void push(int x)
{
	stack[++top] = x;
}

int pop()
{
	int x;
	x = stack[top--];
}

int peek()
{
	return stack[top];
}
// Function to perform an operation and return output. 
int PerformOperation(char operation, int operand1, int operand2)
{
	if(operation == '+') 
		return operand1 +operand2;
	else if(operation == '-') 
		return operand1 - operand2;
	else if(operation == '*') 
		return operand1 * operand2;
	else if(operation == '/') 	
		return operand1 / operand2;
	else if (operation == '^')
	{
		int product = 1;
		for (int i = 1; i <= operand2; i++)
		{
			product = product * operand1;
		}
		return product;
		
	}

	else printf("Unexpected Error \n");
	return -1; 
}
// The main function that returns value of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
	// Create a stack of capacity equal to expression size 
	int i; 

	// Scan all characters one by one 
	for (i = 0; i < strlen(exp); i++) 
	{ 
		// If the scanned character is an operand (number here), 
		// push it to the stack.
		if (exp[i] == ' ')
            continue;
		
        
        else if (isdigit(exp[i])) 
        {
            int operand = 0; 
			while(i< strlen(exp) && isdigit(exp[i]))
            {
				// For a number with more than one digits, as we are scanning from left to right. 
				// Everytime , we get a digit towards right, we can multiply current total in operand by 10 
				// and add the new digit. 
				operand = (operand*10) + (exp[i] - '0'); 
				i++;
			}
			// Finally, you will come out of while loop with i set to a non-numeric character or end of string
			// decrement i because it will be incremented in increment section of loop once again. 
			// We do not want to skip the non-numeric character by incrementing i twice. 
			i--;
			push(operand); 
        }
		// If the scanned character is an operator, pop two 
		// elements from stack apply the operator 
		else if(isoperator(exp[i]))
		{ 
			int val2 = pop(); 
			int val1 = pop(); 

			int result = PerformOperation(exp[i], val1, val2);
			push(result);

		}
	} 
	return peek(); 
} 

// Driver program to test above functions 
int main() 
{ 
	char exp[50];
	printf("Enter the expression\n");
    get(exp); 
	infixToPostfix(exp); 
	printf ("postfix evaluation: %d \n ", evaluatePostfix(exp)); 
	return 0; 
} 
