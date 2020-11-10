
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"evaluation_of_postfix.c"

struct history
{
    char expression[100];
    int result;
};
typedef struct history history;
history num_of_hisory[15];

void display()
{
        system("clear");
        printf("\nHISTORY\n");
        printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-7s|| %-107s|| %-10s||\n","S_no","Expression","result");
        
           printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
        for (int i = 0; i < 15; i++)
        {
            printf("| %-7d|| %-107s|| %-10d||\n",i+1,num_of_hisory[i].expression,num_of_hisory[i].result);
               printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
        }
        
           //printf("--------------------------------------------------------------------------------------------------------------------------------------\n");
}

void clear()
{
    for (int i = 0; i < 15; i++)
    {
        num_of_hisory[i].expression[0] = '\0';
        num_of_hisory[i].result = 0;
    }
    
}

// Driver program to test above functions 
int main()
{
    system("clear");
    int choice  = 0;
    int i = 0,x;
    char temp[100];
    int solution = 0;
    do
    {
    printf("----------------------------------------------------------------------------------------\n");
	printf("|			CALCULATER 	        	                               |\n");
	printf("----------------------------------------------------------------------------------------\n");
	printf("| %-84s |\n","Menu");
	printf("----------------------------------------------------------------------------------------\n");
	printf("| %-20s | %-20s | %-20s | %-15s |\n","Put calculation - 1","History - 2","Clear history - 3","Exit -0");
	printf("----------------------------------------------------------------------------------------\n");
    printf("Enter your choice\t");
    scanf("%d",&choice);
    getchar();
    if(choice == 1)
    {
        printf("Enter the expression\t");
        get(temp); 
        copystr(temp,num_of_hisory[i].expression);
        infixToPostfix(temp);
        printf("%s\n",temp);
        solution = evaluatePostfix(temp);
	    printf("postfix evaluation: %d\n", evaluatePostfix(temp));
        num_of_hisory[i].result = solution;
              i++;
        getchar();
        system("clear");

    }
    else if (choice == 2)
    {
        system("clear");
        display();
        getchar();
        system("clear");
    }
    else if (choice == 3)
    {
        system("clear");
          printf("----------------------------------------------------------------------------------------\n");
	printf("|			HISTORY CLEARED 	        	                       |\n");
	printf("----------------------------------------------------------------------------------------\n");
        clear();
        i = 0;
        getchar();
        system("clear");

    }
    

    else if(choice > 3)
    {
        printf(" \n");
                 printf("-----------------------------------------------------------------------------------------\n");
	printf("|			     IN VALUED!!! 	               	                        |\n");
	printf("-----------------------------------------------------------------------------------------\n");
        getchar();
        system("clear");

    }
    
    if (i == 15)
        i = 0;
    
    
 } while (choice != 0);
   


    return 0;

}





