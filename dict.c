#include "dict.h"
define_dict(int)
void main()
{

int_htable x=new_dict(int,5);
printf("Initial Size of Dictionary is %d\n",x->size);
printf("Inserting 4,4,6,10\n");
insert_dict(int,x,4);
insert_dict(int,x,4);
insert_dict(int,x,6);
insert_dict(int,x,10);
printf("Total Size of dictionary is %d \n", x->size);
printf("Current Size of dictionary is %d \n",x->curr_size);
printf("Element 4 is found in position %d\n", (int)search_dict(int, x, 4));
printf("Inserting 28\n");
insert_dict(int, x, 28);
printf("Total Size of dictionary is %d \n", x->size);
printf("Current Size of dictionary is %d \n", x->curr_size);
delete_dict(int,x,28);
printf("Deleted 5\n");
printf("Total Size of dictionary is %d \n", x->size);
printf("Current Size of dictionary is %d \n", x->curr_size);
}
