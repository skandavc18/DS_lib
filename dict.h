#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define mod 10000000007
#define K 977
#define B 199
#define int_cmp(x, y) (x > y) ? 1 : (x < y) ? -1 : 0
#define long_cmp(x, y) (x > y) ? 1 : (x < y) ? -1 : 0
#define double_cmp(x, y) (x > y) ? 1 : (x < y) ? -1 : 0
#define float_cmp(x, y) (x > y) ? 1 : (x < y) ? -1 : 0
#define char_cmp(x, y) (x > y) ? 1 : (x < y) ? -1 : 0
#define str_cmp(x,y) strcmp(x,y)
typedef char* str;

int nextPrime(int n)
{
    int i, j;

    for (i = n + 1;; i++)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
                break;
        }

        if (j == i)
        {
            return i;
        }
    }
}

long long str_hashfunc(str x, int size)
{
    long long y = 0;
    for (int i = 0; i < strlen(x); i++)
    {
        y += ((x[i]) * (long long)pow(256, i)) % mod;
    }
    long long hkey = ((y + B) % (K * size)) / K;
    return hkey;
}
long long float_hashfunc(float x, int size)
{
    unsigned int ui;
    memcpy(&ui, &x, sizeof(float));
    return (long long)((ui & 0xfffff000) % size);
}
long long double_hashfunc(double x, int size)
{
    unsigned long ui;
    memcpy(&ui, &x, sizeof(double));
    return (long long)((ui & 0xfffffffffffff000) % size);
}
long long int_hashfunc(int x, int size)
{
    long long hkey = x % size;
    return hkey;
}

long long long_hashfunc(long x, int size)
{
    long long hkey = x % size;
    return hkey;
}

long long char_hashfunc(char x, int size)
{
    long long hkey = x % size;
    return hkey;
}

#define dict_struct(TYPE)   \
    typedef struct          \
    {                       \
        TYPE data;          \
        int valid;          \
    } TYPE##_record;        \
    typedef struct          \
    {                       \
        TYPE##_record *arr; \
        int size;           \
        int curr_size;      \
        char type[];        \
    } * TYPE##_htable, TYPE##_dict_struct_size;

typedef struct
{
    str data;
    int valid;
} str_record;
typedef struct
{
    str_record *arr;
    int size;
    int curr_size;
    char type[];
} * str_htable,str_dict_struct_size;

void str_dict_rehash(str_htable obj);

#define dict_declarations(TYPE)                                  \
    TYPE##_htable TYPE##_dict_new(int size);                     \
    void TYPE##_dict_rehash(TYPE##_htable obj);                  \
    int TYPE##_dict_insert(TYPE##_htable table, TYPE x);         \
    int TYPE##_dict_delete(TYPE##_htable table, TYPE x);         \
    long long TYPE##_dict_search(TYPE##_htable table, TYPE x);

#define dict_new(TYPE)                                              \
    TYPE##_htable TYPE##_dict_new(int size)                         \
    {                                                               \
        size = nextPrime(size);                                     \
        TYPE##_htable NAME = calloc(1, sizeof(TYPE##_dict_struct_size)); \
        NAME->size = size;                                          \
        NAME->arr = calloc(size, sizeof(TYPE##_record));            \
        NAME->curr_size = 0;                                        \
        return NAME;                                                \
    }

#define dict_rehash(TYPE)                                             \
    void TYPE##_dict_rehash(TYPE##_htable obj)                         \
    {                                                             \
        TYPE##_htable temp = TYPE##_dict_new(nextPrime(obj->size * 2));\
        for (int i = 0; i < obj->size; i++)                       \
        {                                                         \
            if (obj->arr[i].valid == 1)                           \
                TYPE##_dict_insert(temp, obj->arr[i].data);            \
        }                                                         \
        free(obj->arr);                                           \
        free(obj);                                                \
        *(obj) = *(temp);                                         \
    }

#define dict_insert(TYPE)                                                                     \
    int TYPE##_dict_insert(TYPE##_htable table, TYPE x)                                        \
    {                                                                                     \
        long long hash = TYPE##_hashfunc(x, table->size);                                 \
        if ((table->arr[hash].valid == 1) && (TYPE##_cmp(x, table->arr[hash].data) == 0)) \
        {                                                                                 \
            return -1;                                                                    \
        }                                                                                 \
        if ((table->arr[hash].valid == 1) && (TYPE##_cmp(x, table->arr[hash].data)))      \
        {                                                                                 \
            long long cycle = hash;                                                       \
            int i = 1;                                                                    \
            hash = (hash + i * i) % table->size;                                          \
            while ((table->arr[hash].valid == 1) && (cycle != hash))                      \
            {                                                                             \
                hash = (hash + i * i) % table->size;                                      \
                i++;                                                                      \
            }                                                                             \
        }                                                                                 \
        table->arr[hash].data=x;                                                          \
        table->arr[hash].valid = 1;                                                       \
        table->curr_size += 1;                                                            \
        if (table->curr_size / table->size > 0.75)                                        \
            TYPE##_dict_rehash(table);                                                         \
        return 1;                                                                         \
    }

#define dict_search(TYPE)                                                                        \
    long long TYPE##_dict_search(TYPE##_htable table, TYPE x)                                     \
    {                                                                                        \
        long long hash = TYPE##_hashfunc(x, table->size);                                    \
        int flag = 0;                                                                        \
        if ((table->arr[hash].valid==1) && (TYPE##_cmp(x, table->arr[hash].data) == 0))      \
        {                                                                                    \
            return hash;                                                                     \
        }                                                                                    \
        else                                                                                 \
        {                                                                                    \
            long long cycle = hash;                                                          \
            int i = 1;                                                                       \
            hash = (hash + i) % table->size;                                                 \
            while (cycle != hash)                                                            \
            {                                                                                \
                if((table->arr[hash].valid==1) && (TYPE##_cmp(x, table->arr[hash].data)==0));\
                {                                                                            \
                    return hash;                                                             \
                }                                                                            \
                hash = (hash + i * i) % table->size;                                         \
                i++;                                                                         \
            }                                                                                \
        }                                                                                    \
        return -1;                                                                           \
    }

#define dict_delete(TYPE)                              \
    int TYPE##_dict_delete(TYPE##_htable table, TYPE x) \
    {                                              \
        long long pos = TYPE##_dict_search(table, x);   \
        if (pos != -1)                             \
        {                                          \
            table->arr[pos].valid = -1;            \
            table->curr_size += 1;                 \
            return 1;                              \
        }                                          \
        return -1;                                 \
    }

int str_dict_insert(str_htable table, str x)
{
    long long hash = str_hashfunc(x, table->size);
    if ((table->arr[hash].valid == 1) && (strcmp(x, table->arr[hash].data) == 0))
    {
        return -1;
    }
    if ((table->arr[hash].valid == 1) && (strcmp(x, table->arr[hash].data)))
    {
        long long cycle = hash;
        int i = 1;
        hash = (hash + i * i) % table->size;
        while ((table->arr[hash].valid == 1) && (cycle != hash))
        {
            hash = (hash + i * i) % table->size;
            i++;
        }
    }
    table->arr[hash].data = malloc(strlen(x));
    strcpy(table->arr[hash].data, x);
    table->arr[hash].valid = 1;
    table->curr_size += 1;
    if (table->curr_size / table->size > 0.75)
        str_dict_rehash(table);
    return 1;
}

#define str_define_dict()\
    dict_declarations(str)      \
    dict_new(str)              \
    dict_rehash(str)           \
    dict_search(str)           \
    dict_delete(str)      

#define int_define_dict()\
    dict_declarations(int)      \
    dict_struct(int)     \
    dict_new(int)              \
    dict_insert(int)           \
    dict_rehash(int)           \
    dict_search(int)           \
    dict_delete(int)      
#define char_define_dict()\
    dict_declarations(char)     \
    dict_struct(char)         \
    dict_new(char)              \
    dict_insert(char)           \
    dict_rehash(char)           \
    dict_search(char)           \
    dict_delete(char)    

#define float_define_dict()\
    dict_declarations(float)      \
    dict_struct(float)     \
    dict_new(float)              \
    dict_insert(float)           \
    dict_rehash(float)           \
    dict_search(float)           \
    dict_delete(float)  


#define long_define_dict()\
    dict_declarations(long)      \
    dict_struct(long)     \
    dict_new(long)              \
    dict_insert(long)           \
    dict_rehash(long)           \
    dict_search(long)           \
    dict_delete(long)  


#define double_define_dict()\
    dict_declarations(double)      \
    dict_struct(double)     \
    dict_new(double)              \
    dict_insert(double)           \
    dict_rehash(double)           \
    dict_search(double)           \
    dict_delete(double)  

#define define_dict(TYPE) \
    TYPE##_define_dict()

#define new_dict(TYPE,size)\
    TYPE##_dict_new(size)

#define insert_dict(TYPE, table, data)\
    TYPE##_dict_insert(table,data)

#define search_dict(TYPE, table, data)\
    TYPE##_dict_search(table,data)

#define delete_dict(TYPE, table, data) TYPE##_dict_delete(table,data)