#include"tree.h"

define_tree(int)
void main()
{
    int_node *x=new_tree(int,2);
    //traversal(x);printf("\n");
    
    insert_tree(int,x,3);
    //traversal(x);
    //printf("\n");
    insert_tree(int, x, 1);
    //traversal(x);
    //printf("\n");
    insert_tree(int, x, 10);
    //traversal(x);
    //printf("\n");
    insert_tree(int, x, 19);
    //traversal(x);
    //printf("\n");
    //traversal(x);
    //printf("\n");
    //printf("%d\n", search_tree(int, x, 15));
    //delete_tree(int, x, 10);
    printLevelOrder(x);
    printf("\n");

}