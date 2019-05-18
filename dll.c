#include "dll.h"

int main()
{
    /*int a = 5, b = 15, c = 43, d = 23, e = 12, f = 66, g = 99, h =65, i = 20, j = 8;
    int pos = 2, insertMidValue = 500, deletePos = 4;

    //Create a linked list
    printf("Insert nodes at tail: %d, %d, %d\n", a, b, c);
    DLL_INSERT_AT_TAIL(int,a);
    DLL_INSERT_AT_TAIL(int,b);
    DLL_INSERT_AT_TAIL(int,c);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(int);

    printf("Insert node: %d at middle. Position: %d\n", insertMidValue, pos);
    DLL_INSERT_AT_MIDDLE(int,insertMidValue, pos); //here midValue = 500 and pos = 2

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(int);

    printf("Delete item of position number %d", deletePos);
    DLL_DELETE_NODE(int,deletePos);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(int);

    printf("Insert nodes at front: %d\n", d);
    DLL_INSERT_AT_HEAD(int,d);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(int);

    printf("Insert nodes at tail: %d\n", e);
    DLL_INSERT_AT_TAIL(int,e);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(int);

    printf("Insert nodes at front: %d\n", f);
    DLL_INSERT_AT_HEAD(int,f);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(int);

    printf("Delete first node of list\n");
    DLL_DELETE_NODE(int,1);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(int);

    printf("Insert nodes at tail: %d, %d, %d, %d\n", g, h, i, j);
    DLL_INSERT_AT_TAIL(int,g);
    DLL_INSERT_AT_TAIL(int,h);
    DLL_INSERT_AT_TAIL(int,i);
    DLL_INSERT_AT_TAIL(int,j);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(int);

    //print the list backward
    DLL_PRINT_LINKEDLIST_BACKWARD(int);*/

    /*printf("Output for Double:\n");

    double a = 5, b = 15, c = 43, d = 23, e = 12, f = 66, g = 99, h =65, i = 20, j = 8;
    int pos = 2,  deletePos = 4;
    double insertMidValue = 500;

    //Create a linked list
    printf("Insert nodes at tail: %lf, %lf, %lf\n", a, b, c);
    DLL_INSERT_AT_TAIL(double,a);
    DLL_INSERT_AT_TAIL(double,b);
    DLL_INSERT_AT_TAIL(double,c);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(double);

    printf("Insert node: %lf at middle. Position: %d\n", insertMidValue, pos);
    DLL_INSERT_AT_MIDDLE(double,insertMidValue, pos); //here midValue = 500 and pos = 2

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(double);

    printf("Delete item of position number %d", deletePos);
    DLL_DELETE_NODE(double,deletePos);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(double);

    printf("Insert nodes at front: %lf\n", d);
    DLL_INSERT_AT_HEAD(double,d);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(double);

    printf("Insert nodes at tail: %lf\n", e);
    DLL_INSERT_AT_TAIL(double,e);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(double);

    printf("Insert nodes at front: %lf\n", f);
    DLL_INSERT_AT_HEAD(double,f);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(double);

    printf("Delete first node of list\n");
    DLL_DELETE_NODE(double,1);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(double);

    printf("Insert nodes at tail: %lf, %lf, %lf, %lf\n", g, h, i, j);
    DLL_INSERT_AT_TAIL(double,g);
    DLL_INSERT_AT_TAIL(double,h);
    DLL_INSERT_AT_TAIL(double,i);
    DLL_INSERT_AT_TAIL(double,j);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(double);

    //print the list backward
    DLL_PRINT_LINKEDLIST_BACKWARD(double);*/

    printf("Output for string:\n");

    string a = "hi", b = "hello", c = "how", d = "r", e = "what", f = "r", g = "u", h ="doing", i = "these", j = "days";
    int pos = 2,  deletePos = 4;
    string insertMidValue = "?";

    //Create a linked list
    printf("Insert nodes at tail: %s, %s, %s\n",a,b,c);
    DLL_INSERT_AT_TAIL(string,a);
    DLL_INSERT_AT_TAIL(string,b);
    DLL_INSERT_AT_TAIL(string,c);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(string);

    printf("Insert node: %s at middle. Position: %d\n", insertMidValue, pos);
    DLL_INSERT_AT_MIDDLE(string,insertMidValue, pos); //here midValue = 500 and pos = 2

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(string);

    printf("Delete item of position number %d", deletePos);
    DLL_DELETE_NODE(string,deletePos);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(string);

    printf("Insert nodes at front: %s\n",d);
    DLL_INSERT_AT_HEAD(string,d);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(string);

    printf("Insert nodes at tail: %s\n",e);
    DLL_INSERT_AT_TAIL(string,e);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(string);

    printf("Insert nodes at front: %s\n",f);
    DLL_INSERT_AT_HEAD(string,f);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(string);

    printf("Delete first node of list\n");
    DLL_DELETE_NODE(string,1);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(string);

    printf("Insert nodes at tail: %s, %s, %s, %s\n",g,h,i,j);
    DLL_INSERT_AT_TAIL(string,g);
    DLL_INSERT_AT_TAIL(string,h);
    DLL_INSERT_AT_TAIL(string,i);
    DLL_INSERT_AT_TAIL(string,j);

    //print the list forward
    DLL_PRINT_LINKEDLIST_FORWARD(string);

    //print the list backward
    DLL_PRINT_LINKEDLIST_BACKWARD(string);

    return 0;
}

