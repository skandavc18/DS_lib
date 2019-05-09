#include"heap.h"

define_heap(int)  //define a heap of integer type

void main()
{
    int_heap h=new_heap(int,5,1);  // 5 is size and 1 means max heap. 0 means min heap
    insert_heap(int, h, 5);
    printf("%d %d\n",h->size,h->curr_size); //size holds the total size of heap. curr_size holds the current size
    insert_heap(int, h, 9);  //insert into heap
    insert_heap(int, h, 3);
    insert_heap(int, h, 2);
    insert_heap(int, h, 7); 
    printf("%d %d\n", h->size, h->curr_size); //can dynamically change the size of heap when it gets filled
    printf("%d\n",minmax_heap(h)); // returns the max or min of heap depending on whether it is a max heap or min heap
}


