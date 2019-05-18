#include"tree.h"

define_tree(int)
void main()
{
    int_node *x=new_tree(int,2);
    //traversal(x);printf("\n");
    printf("Inserted 3,1,10,19,15\n");
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
    insert_tree(int, x, 15);
    //traversal(x);
    //printf("\n");
    if (search_tree(int, x, 15))
        printf("15 found in Tree\n" );
    else
    {
        printf("15 not found in Tree\n");
    }
    delete_tree(int,x,15);
    printf("15 deleted\n");
    if (search_tree(int, x, 15))
        printf("15 found in Tree\n");
    else
    {
        printf("15 not found in Tree\n");
    }
    //delete_tree(int, x, 10);
    printf("Level Order : \n");
    printLevelOrder(x);

}