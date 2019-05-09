#include<stdio.h>
#include<stdlib.h>
typedef char* string;

// A structure to represent a dll 
#define DLL_DECLARE(type)                                                       \
typedef struct type##_linked_list                                               \
{                                                                               \
    type number;                                                                \
    struct type##_linked_list *next;                                                   \
    struct type##_linked_list *previous;                                               \
}type##_node;                                                                   \
                                                                                \
type##_node* type##_head=NULL;                          \
type##_node* type##_tail=NULL;                          \
                                                                                \
type##_node* type##_getNewNode(type val);                                       \
void type##_insert_at_head(type value);                                         \
void type##_insert_at_tail(type value);                                         \
void type##_insert_at_middle(type value, int position);                         \
void type##_deleteNode(int position);                                           \
void type##_printLinkedListForward();                                           \
void type##_printLinkedListBackward();                                          

#define DLL_DEFINE(type)                                                        \
type##_node* type##_getNewNode(type val)                                        \
{                                                                               \
    type##_node *temp_node;                                                     \
    temp_node = (type##_node *) malloc(sizeof(type##_node));                    \
    temp_node->number=val;                                                      \
    temp_node->next=NULL;                                                       \
    temp_node->previous=NULL;                                                   \
                                                                                \
    return temp_node;                                                           \
}                                                                               \
                                                                                \
void type##_insert_at_head(type value)                                          \
{                                                                               \
    type##_node *newNode = type##_getNewNode(value);                            \
                                                                                \
    if(type##_head==NULL)                                                              \
    {                                                                           \
        type##_head=newNode;                                                           \
        type##_tail=newNode;                                                           \
        return;                                                                 \
    }                                                                           \
    newNode->next = type##_head;                                                       \
    type##_head->previous = newNode;                                                   \
    type##_head = newNode;                                                             \
}                                                                               \
void type##_insert_at_tail(type value)                                          \
{                                                                               \
    type##_node *newNode = type##_getNewNode(value);                                   \
                                                                                \
    if(type##_head==NULL)                                                              \
    {                                                                           \
        type##_head=newNode;                                                           \
        type##_tail=newNode;                                                           \
        return;                                                                 \
    }                                                                           \
                                                                                \
    type##_tail->next = newNode;                                                       \
    newNode->previous = type##_tail;                                                   \
                                                                                \
    type##_tail = newNode;                                                             \
}                                                                               \
                                                                                \
void type##_insert_at_middle(type value, int position)                          \
{                                                                               \
    type##_node *newNode = type##_getNewNode(value);                            \
                                                                                \
    if(type##_head==NULL)                                                              \
    {                                                                           \
        type##_head=newNode;                                                           \
        type##_tail=newNode;                                                           \
        return;                                                                 \
    }                                                                           \
                                                                                \
    type##_node *temp = (type##_node *) malloc(sizeof(type##_node));                          \
    temp = type##_head;                                                                \
    int i = 1;                                                                  \
                                                                                \
    while((i < position-1) && temp->next!=NULL){                                \
        temp = temp->next;                                                      \
        i++;                                                                    \
    }                                                                           \
                                                                                \
    newNode->next = temp->next;                                                 \
    newNode->previous = temp;                                                   \
                                                                                \
    if(temp->next)                                                              \
        temp->next->previous = newNode;                                         \
                                                                                \
    temp->next = newNode;                                                       \
}                                                                               \
                                                                                \
void type##_deleteNode(int position){                                           \
                                                                                \
    if(type##_head==NULL) return;                                                      \
                                                                                \
    if(position==1){                                                            \
        type##_head = type##_head->next;                                                      \
                                                                                \
        if(type##_head->next==NULL)                                                    \
            type##_tail = NULL;                                                        \
        else                                                                    \
            type##_head->next->previous = NULL;                                        \
                                                                                \
        return;                                                                 \
    }                                                                           \
                                                                                \
    type##_node *temp = (type##_node*) malloc(sizeof(type##_node));             \
    type##_node *tempAnother = (type##_node*) malloc(sizeof(type##_node));      \
    int i = 1;                                                                  \
                                                                                \
    temp = type##_head;                                                                \
                                                                                \
    while((i < position) && temp->next!=NULL){                                  \
        temp = temp->next;                                                      \
        i++;                                                                    \
    }                                                                           \
                                                                                \
    if(i == position){                                                          \
                                                                                \
        tempAnother = temp->previous;                                           \
        tempAnother->next = temp->next;                                         \
                                                                                \
        if(temp->next==NULL)                                                    \
            type##_tail = tempAnother;                                                 \
        else                                                                    \
            temp->next->previous = tempAnother;                                 \
                                                                                \
        free(temp);                                                             \
    }                                                                           \
    else                                                                        \
        printf("Desired position does not exist! Position: ");           \
        printf(GET_FMT_SPEC(i), i);                   \
        printf("\n");                                                                        \
}                                                                               \
                                                                                \
void type##_printLinkedListForward()                                            \
{                                                                               \
    printf("\nYour updated linked list in FORWARD ORDER:\n");                   \
                                                                                \
    type##_node *myList;                                                        \
    myList = type##_head;                                                              \
                                                                                \
    while(1)                                                                    \
    {                                                                           \
        if(type##_head==NULL || type##_tail==NULL) break;                                     \
                                                                                \
        printf(GET_FMT_SPEC(myList->number), myList->number);                   \
        printf(" ");                                          \
                                                                                \
        if(myList==type##_tail) break;                                                 \
                                                                                \
        myList = myList->next;                                                  \
    }                                                                           \
    puts("\n");                                                                 \
}                                                                               \
                                                                                \
void type##_printLinkedListBackward()                                           \
{                                                                               \
    printf("\nYour full linked list in REVERSE ORDER:\n");                      \
                                                                                \
    type##_node *myList;                                                        \
    myList = type##_tail;                                                              \
                                                                                \
    while(1)                                                                    \
    {                                                                           \
        if(type##_head==NULL || type##_tail==NULL) break;                                     \
        printf(GET_FMT_SPEC(myList->number), myList->number);                    \
        printf(" ");                                          \
                                                                                \
        if(myList->previous==NULL) break;                                       \
                                                                                \
        myList = myList->previous;                                              \
    }                                                                           \
    puts("\n");                                                                 \
}                                                                               

#define GET_FMT_SPEC(x) _Generic((x), int: "%d", double: "%lf",float: "%f", char*: "%s")

#define DLL_TYPE(type)\
type##_node

#define DLL_GET_NEW_NODE(type, data)\
type##_getNewNode(data)

#define DLL_INSERT_AT_HEAD(type, root)\
type##_insert_at_head(root)

#define DLL_INSERT_AT_TAIL(type, root)\
type##_insert_at_tail(root)

#define DLL_INSERT_AT_MIDDLE(type, root, data)\
type##_insert_at_middle(root, data)
 
#define DLL_DELETE_NODE(type, root)\
type##_deleteNode(root)

#define DLL_PRINT_LINKEDLIST_FORWARD(type)\
type##_printLinkedListForward()

#define DLL_PRINT_LINKEDLIST_BACKWARD(type)\
type##_printLinkedListBackward()

DLL_DECLARE(string)
DLL_DEFINE(string)
DLL_DECLARE(int)
DLL_DEFINE(int)
DLL_DECLARE(double)
DLL_DEFINE(double)