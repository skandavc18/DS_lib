#include "dict.h"
define_dict(int)
void main()
{

int_htable x=new_dict(int,11);
insert_dict(int,x,4);
insert_dict(int,x,4);
insert_dict(int,x,6);
printf("%d \n",(int)search_dict(int,x,4));
//delete_dict(int,x);
}
