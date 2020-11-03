// C program to convert infix expression to postfix 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include"get_str.c"

// Stack type 
struct Stack1 
{ 
	int top; 
	unsigned capacity; 
	char* array; 
}; 

// Stack Operations 
struct Stack1* createStack1( unsigned capacity ) 
{ 
	struct Stack1* stack1 = (struct Stack1*)malloc(sizeof(struct Stack1)); 
    if (!stack1) 
		return NULL; 
    stack1->top = -1; 
	stack1->capacity = capacity; 
    stack1->array = (char*) malloc(stack1->capacity * sizeof(char)); 
    return stack1; 
} 

int isEmpty1(struct Stack1* stack1) 
{ 
	return stack1->top == -1 ; 
}

char peek1(struct Stack1* stack1) 
{ 
	return stack1->array[stack1->top]; 
}

char pop1(struct Stack1* stack1) 
{ 
	if (!isEmpty1(stack1)) 
		return stack1->array[stack1->top--] ; 
	return '$'; 
} 

void push1(struct Stack1* stack1, char op) 
{ 
	stack1->array[++stack1->top] = op; 
} 


// A utility function to check if 
// the given character is operand 
int isOperand(char ch) 
{ 
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' &&  ch <= '9'); 
} 

// A utility function to return 
// precedence of a given operator 
// Higher returned value means 
// higher precedence 
int Prec(char ch) 
{ 
	switch (ch) 
	{ 
	case '+': 
	case '-': 
		return 1; 
    case '*': 
	case '/': 
		return 2; 
    case '^': 
		return 3; 
	} 
	return -1; 
} 


// The main function that 
// converts given infix expression 
// to postfix expression. 
int infixToPostfix(char* exp) 
{ 
	int i, k; 
    // Create a stack of capacity 
	// equal to expression size 
	struct Stack1* stack1 = createStack1(strlen(exp)); 
	if(!stack1) // See if stack was created successfully 
		return -1 ; 
    for (i = 0, k = -1; exp[i]; ++i) 
	{ 
        if(exp[i] == ' ')
            exp[++k] = exp[i];
		// If the scanned character is 
		// an operand, add it to output. 
		else if (isOperand(exp[i])) 
			exp[++k] = exp[i]; 
		
		// If the scanned character is an 
		// ‘(‘, push it to the stack. 
		else if (exp[i] == '(') 
			push1(stack1, exp[i]); 
		
		// If the scanned character is an ‘)’, 
		// pop and output from the stack 
		// until an ‘(‘ is encountered. 
		else if (exp[i] == ')') 
		{ 
			while (!isEmpty1(stack1) && peek1(stack1) != '(') 
				exp[++k] = pop1(stack1); 
			if (!isEmpty1(stack1) && peek1(stack1) != '(') 
				return -1; // invalid expression			 
			else
				pop1(stack1); 
		} 
		else // an operator is encountered 
		{ 
			while (!isEmpty1(stack1) && 
				Prec(exp[i]) <= Prec(peek1(stack1))) 
				exp[++k] = pop1(stack1); 
			push1(stack1, exp[i]); 
		} 

	} 

	// pop all the operators from the stack 
	while (!isEmpty1(stack1)) 
		exp[++k] = pop1(stack1 ); 

	exp[++k] = '\0'; 
} 

