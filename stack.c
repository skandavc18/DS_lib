// C program for linked list implementation of stack 
#include "stack.h"

int main() 
{ 
	STACK_TYPE(int)* root = NULL; 
    printf("Output for Int:\n");
	STACK_PUSH(int,&root, 10); 
	STACK_PUSH(int,&root, 20);
	STACK_PUSH(int,&root, 30);
    
	printf("%d popped from stack\n", STACK_POP(int,&root)); 

	printf("Top element is %d\n", STACK_PEEK(int,root)); 

    STACK_TYPE(double)* rootDouble = NULL; 
    printf("Output for Double:\n");
	STACK_PUSH(double,&rootDouble, 10);
	STACK_PUSH(double,&rootDouble, 20);
    STACK_PUSH(double,&rootDouble, 30); 

	printf("%lf popped from stack\n", STACK_POP(double,&rootDouble)); 

	printf("Top element is %lf\n", STACK_PEEK(double,rootDouble));

    STACK_TYPE(string)* rootString = NULL; 
    printf("Output for string:\n");
	STACK_PUSH(string,&rootString, "Hello");
	STACK_PUSH(string,&rootString, "Hi");
    STACK_PUSH(string,&rootString, "Bye"); 

	printf("%s popped from stack\n", STACK_POP(string,&rootString)); 

	printf("Top element is %s\n", STACK_PEEK(string,rootString));

	return 0; 
} 
