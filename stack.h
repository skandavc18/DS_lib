#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
typedef char* string;

// A structure to represent a stack 
#define STACK_DECLARE(type)                                            \
typedef struct type##_StackNode                                        \
{                                                                      \
	type data;                                                         \
	struct type##_StackNode* next;                                     \
}stack_##type ;                                                        \
stack_##type* type##_newNode(type data);                                        \
int type##_isEmpty(stack_##type *root);                                        \
void type##_push(stack_##type** root, type data);                             \
type type##_pop(stack_##type** root);                                          \
type type##_peek(stack_##type* root);                                               

#define STACK_DEFINE(type)                                              \
stack_##type* type##_newNode(type data)                                 \
{                                                                       \
	stack_##type* stackNode =                                           \
			(stack_##type*) malloc(sizeof(stack_##type));               \
	stackNode->data = data;                                             \
	stackNode->next = NULL;                                             \
	return stackNode;                                                   \
}                                                                       \
                                                                        \
int type##_isEmpty(stack_##type *root)                                  \
{                                                                       \
	return !root;                                                       \
}                                                                       \
                                                                        \
void type##_push(stack_##type** root, type data)                        \
{                                                                       \
	stack_##type* stackNode = STACK_NEW_NODE(type,data);                \
	stackNode->next = *root;                                            \
	*root = stackNode;                                                  \
    printf(GET_FMT_SPEC(data), data);                                              \
	printf(" pushed to stack\n");                                       \
}                                                                       \
                                                                        \
type type##_pop(stack_##type** root)                                    \
{                                                                       \
	if (STACK_IS_EMPTY(type,*root))                                                 \
		return INT_MIN;                                                 \
	stack_##type* temp = *root;                                         \
	*root = (*root)->next;                                              \
	type popped = temp->data;                                           \
	free(temp);                                                         \
                                                                        \
	return popped;                                                      \
}                                                                       \
                                                                        \
type type##_peek(stack_##type* root)                                    \
{                                                                       \
	if (STACK_IS_EMPTY(type,root))                                                  \
		return INT_MIN;                                                 \
	return root->data;                                                  \
}

#define GET_FMT_SPEC(x) _Generic((x), int: "%d", double: "%lf",float: "%f", char*: "%s")

#define STACK_TYPE(type)\
stack_##type

#define STACK_NEW_NODE(type, data)\
type##_newNode(data)

#define STACK_IS_EMPTY(type, root)\
type##_isEmpty(root)

#define STACK_PEEK(type, root)\
type##_peek(root)

#define STACK_PUSH(type, root, data)\
type##_push(root, data)
 
#define STACK_POP(type, root)\
type##_pop(root)





STACK_DECLARE(string)
STACK_DEFINE(string)
STACK_DECLARE(int)
STACK_DEFINE(int)
STACK_DECLARE(double)
STACK_DEFINE(double)
