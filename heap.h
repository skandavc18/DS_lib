#include <stdio.h>
#include <stdlib.h>
typedef char* str;
#define define_heap_struct(TYPE)              \
    typedef struct                            \
    {                                         \
        TYPE *arr;                            \
        int curr_size;                        \
        int size;                             \
        int heap_type;                        \
    } * TYPE##_heap, TYPE##_dict_struct_size; \

#define cmp(heap_type,a,b) (heap_type==0)? a>b : a<b  
// 0 for min heap , 1 for max heap
#define heap_declarations(TYPE)                                      \
    TYPE##_heap TYPE##_heap_new(int size, int heap_type);           \
    void TYPE##_heap_resize(TYPE##_heap h);                         \
    void TYPE##_heap_insert(TYPE##_heap h, TYPE key);                \
    void TYPE##_heapify_bottom_top(TYPE##_heap h, int index);       \
    void TYPE##_heapify_top_bottom(TYPE##_heap h, int parent_node); \
    TYPE TYPE##_heap_delete(TYPE##_heap h);

#define heap_new(TYPE)                                                        \
    TYPE##_heap TYPE##_heap_new(int size, int heap_type)                      \
    {                                                                         \
        TYPE##_heap h = (TYPE##_heap)malloc(sizeof(TYPE##_dict_struct_size)); \
        h->heap_type = heap_type;                                             \
        h->curr_size = 0;                                                     \
        h->size = size;                                                       \
        h->arr = (TYPE *)malloc(size * sizeof(TYPE));                         \
        return h;                                                             \
    }

#define heap_resize(TYPE)                                                      \
    void TYPE##_heap_resize(TYPE##_heap h)                                     \
    {                                                                          \
        TYPE##_heap h1 = (TYPE##_heap)malloc(sizeof(TYPE##_dict_struct_size)); \
        h1->heap_type = h->heap_type;                                          \
        h1->curr_size = h->curr_size;                                          \
        h1->size = 2 * h->size;                                                \
        h1->arr = (TYPE *)malloc(h1->size * sizeof(TYPE));                     \
        for (int i = 0; i < h->curr_size; i++)                                 \
        {                                                                      \
            h1->arr[i] = h->arr[i];                                            \
        }                                                                      \
        free(h->arr);                                                          \
        free(h);                                                               \
        *h = *h1;                                                              \
    }

#define heap_insert(TYPE)                                \
    void TYPE##_heap_insert(TYPE##_heap h, TYPE key)     \
    {                                                    \
        if (h->curr_size < h->size)                      \
        {                                                \
            h->arr[h->curr_size] = key;                  \
            TYPE##_heapify_bottom_top(h, h->curr_size);  \
            h->curr_size++;                              \
        }                                                \
        if (h->curr_size == h->size)                     \
        TYPE##_heap_resize(h);                           \
    }

#define heapify_bottom_top(TYPE)                             \
    void TYPE##_heapify_bottom_top(TYPE##_heap h, int index) \
    {                                                        \
        TYPE temp;                                           \
        int parent_node = (index - 1) / 2;                   \
        if(cmp(h->heap_type,h->arr[parent_node],h->arr[index]))\
        {                                                    \
            temp = h->arr[parent_node];                      \
            h->arr[parent_node] = h->arr[index];             \
            h->arr[index] = temp;                            \
            TYPE##_heapify_bottom_top(h, parent_node);       \
        }                                                    \
    }

#define heapify_top_bottom(TYPE)                                                \
    void TYPE##_heapify_top_bottom(TYPE##_heap h, int parent_node)              \
    {                                                                           \
        int left = parent_node * 2 + 1;                                         \
        int right = parent_node * 2 + 2;                                        \
        int min_max;                                                            \
        TYPE temp;                                                              \
        if (left >= h->curr_size || left < 0)                                   \
            left = -1;                                                          \
        if (right >= h->curr_size || right < 0)                                 \
            right = -1;                                                         \
        if (left != -1 && cmp(h->heap_type, h->arr[parent_node], h->arr[left])) \
            min_max = left;                                                     \
        else                                                                    \
            min_max = parent_node;                                              \
        if (right != -1 && cmp(h->heap_type, h->arr[min_max], h->arr[right]))   \
            min_max = right;                                                    \
        if (min_max != parent_node)                                             \
        {                                                                       \
            temp = h->arr[min_max];                                             \
            h->arr[min_max] = h->arr[parent_node];                                  \
            h->arr[parent_node] = temp;                                         \
            TYPE##_heapify_top_bottom(h, min_max);                              \
        }                                                                       \
    }
#define heap_delete(TYPE)                         \
    TYPE TYPE##_heap_delete(TYPE##_heap h)        \
    {                                             \
        TYPE pop;                                 \
        if (h->curr_size > 0)                     \
        {                                         \
            pop = h->arr[0];                      \
            h->arr[0] = h->arr[h->curr_size - 1]; \
            h->curr_size--;                       \
            TYPE##_heapify_top_bottom(h, 0);      \
            return pop;                           \
        }                                         \
        return (TYPE)0;                           \
    }

#define define_heap(TYPE)   \
    define_heap_struct(TYPE)\
    heap_declarations(TYPE) \
    heap_new(TYPE) \
    heap_resize(TYPE)\
    heap_insert(TYPE)\
    heapify_bottom_top(TYPE)\
    heapify_top_bottom(TYPE)\
    heap_delete(TYPE)

#define new_heap(TYPE, size ,heap_type) \
    TYPE##_heap_new(size, heap_type)

#define insert_heap(TYPE,h,key)\
    TYPE##_heap_insert(h, key)

#define delete_heap(h) TYPE##_heap_delete(h)

#define minmax_heap(h) (h->curr_size>0)? h->arr[0] : 0