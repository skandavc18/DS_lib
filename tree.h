#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
typedef char *str;  
typedef struct NODE1     
{                       
    int key;           
    struct NODE1 *left;  
    struct NODE1 *right; 
    int height;         
} int_node;

typedef struct NODE2
{
    str key;
    struct NODE2 *left;
    struct NODE2 *right;
    int height;
} str_node;

typedef struct NODE3
{
    char key;
    struct NODE3 *left;
    struct NODE3 *right;
    int height;
} char_node;

typedef struct NODE4
{
    long key;
    struct NODE4 *left;
    struct NODE4 *right;
    int height;
} long_node;

typedef struct NODE5
{
    float key;
    struct NODE5 *left;
    struct NODE5 *right;
    int height;
} float_node;

typedef struct NODE6
{
    double key;
    struct NODE6 *left;
    struct NODE6 *right;
    int height;
} double_node;

#define max(TYPE)                    \
    TYPE TYPE##_max(TYPE a, TYPE b)  \
    {                                \
        return (a > b) ? a : b;      \
    }

str str_max(str a,str b)
{
    return strcmp(a,b) > 0 ? a : b;
}

#define tree_declarations(TYPE)                                   \
    TYPE##_node *TYPE##_tree_new(TYPE key);                       \
    TYPE TYPE##_max(TYPE a, TYPE b);                              \
    int TYPE##_height(TYPE##_node *n);                            \
    TYPE##_node *TYPE##_rightRotate(TYPE##_node *y);              \
    TYPE##_node *TYPE##_leftRotate(TYPE##_node *x);               \
    TYPE##_node *TYPE##_tree_insert(TYPE##_node *node, TYPE key); \
    int TYPE##_tree_search(TYPE##_node *t, TYPE e);               \
    TYPE##_node *TYPE##_minValueNode(TYPE##_node *node);          \
    TYPE##_node *TYPE##_tree_delete(TYPE##_node *t, TYPE data);

#define tree_height(TYPE)             \
    int TYPE##_height(TYPE##_node *N) \
    {                                 \
        if (N == NULL)                \
            return 0;                 \
        return N->height;             \
    }

#define tree_new(TYPE)                                                  \
    TYPE##_node *TYPE##_tree_new(TYPE key)                              \
    {                                                                   \
        TYPE##_node *node = (TYPE##_node *)malloc(sizeof(TYPE##_node)); \
        node->key = key;                                                \
        node->left = NULL;                                              \
        node->right = NULL;                                             \
        node->height = 1;                                               \
        return (node);                                                  \
    }

str_node *str_tree_new(str key)
{
    str_node *node = (str_node *)malloc(sizeof(str_node));
    strcpy(node->key , key);
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

#define rightRotate(TYPE)                                                            \
    TYPE##_node *TYPE##_rightRotate(TYPE##_node *y)                                  \
    {                                                                                \
        TYPE##_node *x = y->left;                                                    \
        TYPE##_node *T2 = x->right;                                                  \
        x->right = y;                                                                \
        y->left = T2;                                                                \
        y->height = TYPE##_max(TYPE##_height(y->left), TYPE##_height(y->right)) + 1; \
        x->height = TYPE##_max(TYPE##_height(x->left), TYPE##_height(x->right)) + 1; \
        return x;                                                                    \
    }

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
#define leftRotate(TYPE)                                                             \
    TYPE##_node *TYPE##_leftRotate(TYPE##_node *x)                                   \
    {                                                                                \
        TYPE##_node *y = x->right;                                                   \
        TYPE##_node *T2 = y->left;                                                   \
        y->left = x;                                                                 \
        x->right = T2;                                                               \
        x->height = TYPE##_max(TYPE##_height(x->left), TYPE##_height(x->right)) + 1; \
        y->height = TYPE##_max(TYPE##_height(y->left), TYPE##_height(y->right)) + 1; \
        return y;                                                                    \
    }

#define getBalance(TYPE)                                         \
    int TYPE##_getBalance(TYPE##_node *N)                        \
    {                                                            \
        if (N == NULL)                                           \
            return 0;                                            \
        return TYPE##_height(N->left) - TYPE##_height(N->right); \
    }

#define tree_insert(TYPE)                                                                     \
    TYPE##_node *TYPE##_tree_insert(TYPE##_node *node, TYPE key)                              \
    {                                                                                         \
        if (node == NULL)                                                                     \
            return (TYPE##_tree_new(key));                                                    \
        if (key < node->key)                                                                  \
            node->left = TYPE##_tree_insert(node->left, key);                                 \
        else if (key > node->key)                                                             \
            node->right = TYPE##_tree_insert(node->right, key);                               \
        else                                                                                  \
            return node;                                                                      \
        node->height = 1 + TYPE##_max(TYPE##_height(node->left), TYPE##_height(node->right)); \
        int balance = TYPE##_getBalance(node);                                                \
        if (balance > 1 && key < node->left->key)                                             \
            return TYPE##_rightRotate(node);                                                  \
        if (balance < -1 && key > node->right->key)                                           \
            return TYPE##_leftRotate(node);                                                   \
        if (balance > 1 && key > node->left->key)                                             \
        {                                                                                     \
            node->left = TYPE##_leftRotate(node->left);                                       \
            return TYPE##_rightRotate(node);                                                  \
        }                                                                                     \
        if (balance < -1 && key < node->right->key)                                           \
        {                                                                                     \
            node->right = TYPE##_rightRotate(node->right);                                    \
            return TYPE##_leftRotate(node);                                                   \
        }                                                                                     \
        return node;                                                                          \
    }
#define minValueNode(TYPE)                              \
    TYPE##_node *TYPE##_minValueNode(TYPE##_node *node) \
    {                                                   \
        TYPE##_node *current = node;                    \
        while (current->left != NULL)                   \
            current = current->left;                    \
        return current;                                 \
    }

#define tree_delete(TYPE)                                                                     \
    TYPE##_node *TYPE##_tree_delete(TYPE##_node *root, int key)                               \
    {                                                                                         \
        if (root == NULL)                                                                     \
            return root;                                                                      \
        if (key < root->key)                                                                  \
            root->left = TYPE##_tree_delete(root->left, key);                                 \
        else if (key > root->key)                                                             \
            root->right = TYPE##_tree_delete(root->right, key);                               \
        else                                                                                  \
        {                                                                                     \
            if ((root->left == NULL) || (root->right == NULL))                                \
            {                                                                                 \
                TYPE##_node *temp = root->left ? root->left : root->right;                    \
                if (temp == NULL)                                                             \
                {                                                                             \
                    temp = root;                                                              \
                    root = NULL;                                                              \
                }                                                                             \
                else                                                                          \
                    *root = *temp;                                                            \
                free(temp);                                                                   \
            }                                                                                 \
            else                                                                              \
            {                                                                                 \
                TYPE##_node *temp = TYPE##_minValueNode(root->right);                         \
                root->key = temp->key;                                                        \
                root->right = TYPE##_tree_delete(root->right, temp->key);                     \
            }                                                                                 \
        }                                                                                     \
        if (root == NULL)                                                                     \
            return root;                                                                      \
        root->height = 1 + TYPE##_max(TYPE##_height(root->left), TYPE##_height(root->right)); \
        int balance = TYPE##_getBalance(root);                                                \
        if (balance > 1 && TYPE##_getBalance(root->left) >= 0)                                \
            return TYPE##_rightRotate(root);                                                  \
        if (balance > 1 && TYPE##_getBalance(root->left) < 0)                                 \
        {                                                                                     \
            root->left = TYPE##_leftRotate(root->left);                                       \
            return TYPE##_rightRotate(root);                                                  \
        }                                                                                     \
        if (balance < -1 && TYPE##_getBalance(root->right) <= 0)                              \
            return TYPE##_leftRotate(root);                                                   \
        if (balance < -1 && TYPE##_getBalance(root->right) > 0)                               \
        {                                                                                     \
            root->right = TYPE##_rightRotate(root->right);                                    \
            return TYPE##_leftRotate(root);                                                   \
        }                                                                                     \
        return root;                                                                          \
    }

#define tree_search(TYPE)                                   \
    int TYPE##_tree_search(TYPE##_node *t, TYPE e)          \
    {                                                       \
        if (t == NULL)                                      \
            return 0 ;                                      \
        if (e < t->key)                                     \
            return TYPE##_tree_search(t->left, e );         \
        else if (e > t->key)                                \
            return TYPE##_tree_search(t->right, e);         \
        else                                                \
            return 1;                                       \
    }

void printGivenLevel(int_node* root, int level) 
{ 
    if (root == NULL)
    {
        return; 
    }
    if (level == 1)
    {
        printf("%d ",root->key);
    }
    else if (level > 1) 
    {
        printGivenLevel(root->left, level-1); 
        printGivenLevel(root->right, level-1); 
    } 
} 
void printLevelOrder(int_node* root) 
{ 
    int h = root->height; 
    int i; 
    for (i=1; i<=h; i++)
    {
        printGivenLevel(root, i);
        printf("\n");
    }
} 
  

#define str_define_tree()      \
    tree_declarations(int)     \
    tree_height(int)           \
    rightRotate(int)           \
    leftRotate(int)            \
    getBalance(int)            \
    tree_insert(int)           \
    minValueNode(int)          \
    tree_search(int)           \
    tree_delete(int)          

#define int_define_tree()      \
    max(int)                   \
    tree_declarations(int)     \
    tree_new(int)              \
    tree_height(int)           \
    rightRotate(int)           \
    leftRotate(int)            \
    getBalance(int)            \
    tree_insert(int)           \
    minValueNode(int)          \
    tree_search(int)           \
    tree_delete(int)      
#define char_define_tree()      \
    max(char)                   \
    tree_declarations(char)     \
    tree_new(char)              \
    tree_height(char)           \
    rightRotate(char)           \
    leftRotate(char)            \
    getBalance(char)            \
    tree_insert(char)           \
    minValueNode(char)          \
    tree_search(char)           \
    tree_delete(char)   

#define float_define_tree()      \
    max(float)                   \
    tree_declarations(float)     \
    tree_new(float)              \
    tree_height(float)           \
    rightRotate(float)           \
    leftRotate(float)            \
    getBalance(float)            \
    tree_insert(float)           \
    minValueNode(float)          \
    tree_search(float)           \
    tree_delete(float)   

#define long_define_tree()      \
    max(long)                   \
    tree_declarations(long)     \
    tree_new(long)              \
    tree_height(long)           \
    rightRotate(long)           \
    leftRotate(long)            \
    getBalance(long)            \
    tree_insert(long)           \
    minValueNode(long)          \
    tree_search(long)           \
    tree_delete(long)   


#define double_define_tree()      \
    max(double)                   \
    tree_declarations(double)     \
    tree_new(double)              \
    tree_height(double)           \
    rightRotate(double)           \
    leftRotate(double)            \
    getBalance(double)            \
    tree_insert(double)           \
    minValueNode(double)          \
    tree_search(double)           \
    tree_delete(double)   

#define define_tree(TYPE)          \
    TYPE##_define_tree()

#define new_tree(TYPE,data) \
    TYPE##_tree_new(data)

#define insert_tree(TYPE, node, data)\
    node=TYPE##_tree_insert(node,data)

#define search_tree(TYPE,node, data)\
    TYPE##_tree_search(node,data)

#define delete_tree(TYPE,node, data) node=TYPE##_tree_delete(node,data)