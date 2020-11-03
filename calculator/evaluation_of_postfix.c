// C program to evaluate value of a postfix expression 
#include <stdio.h> 
#include <string.h> 
#include <ctype.h> 
#include <stdlib.h> 
#include"infix_to_postfix.c"

// Stack type 
struct Stack 
{ 
	int top; 
	unsigned capacity; 
	int* array; 
}; 

// Stack Operations 
struct Stack* createStack( unsigned capacity ) 
{ 
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack)); 
    if (!stack) 
        return NULL; 
    stack->top = -1; 
	stack->capacity = capacity; 
	stack->array = (int*) malloc(stack->capacity * sizeof(int)); 
    if (!stack->array) 
        return NULL; 
    return stack; 
} 

int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1 ; 
} 

char peek(struct Stack* stack) 
{ 
	return stack->array[stack->top]; 
} 

char pop(struct Stack* stack) 
{ 
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 

void push(struct Stack* stack, char op) 
{ 
	stack->array[++stack->top] = op; 
} 


// The main function that returns value of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
	// Create a stack of capacity equal to expression size 
	struct Stack* stack = createStack(strlen(exp)); 
	int i; 

	// See if stack was created successfully 
	if (!stack) return -1; 

	// Scan all characters one by one 
	for (i = 0; exp[i]; ++i) 
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
			push(stack, operand); 
        }
		// If the scanned character is an operator, pop two 
		// elements from stack apply the operator 
		else
		{ 
			int val1 = pop(stack); 
			int val2 = pop(stack); 
            int product = 1;
			switch (exp[i]) 
			{ 
			case '+':
                    push(stack, val2 + val1);
                    break; 
			case '-':
                    push(stack, val2 - val1);
                    break; 
			case '*': 
                    push(stack, val2 * val1); 
                    break; 
			case '/': 
                    push(stack, val2/val1); 
                    break; 
            case '^':
                    for (int i = 1; i <= val1; i++)
                    {
                        product = product*val2;
                    }
                    push(stack, product);
                    break;
                    
			} 
		}
	} 
	return pop(stack); 
} 

// Driver program to test above functions 
int main() 
{ 
	char *exp;
    exp = (char *)malloc(sizeof(char));
    get(exp); 
	infixToPostfix(exp); 
    printf("%s\n",exp);
	printf ("postfix evaluation: %d", evaluatePostfix(exp)); 
	return 0; 
} 
