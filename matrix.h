#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#define define_matrix_struct(TYPE) \
    typedef struct            \
    {                         \
        TYPE **data;          \
        int r;                \
        int c;                \
        int curr_r;           \
    } * TYPE##_matrix, TYPE##_matrix_size;
define_matrix_struct(int)
define_matrix_struct(char)
define_matrix_struct(long)
define_matrix_struct(float)
define_matrix_struct(double)
int countDigit(long n) 
{ 
    if (n == 0) 
        return 0; 
    return 1 + countDigit(n / 10); 
} 
void int_matrix_print(int_matrix mat)
{
    if (mat->r == 0 && mat->c == 0)
    {
        printf("Matrix is empty ! \n");
        return;
    }
    int max=0;
    for(int i=0;i<mat->c;i++)
    {
        for(int j=0;j<mat->r;j++)
        {
            if (countDigit(mat->data[i][j])>max)
                max = countDigit(mat->data[i][j]);
        }
    }
    printf(" --");
    printf("%*c", max * mat->c, ' ');
    printf(" --\n");
    for (int i = 0; i < mat->r; i++)
    {
        for (int j = 0; j < mat->c; j++)
        {
            if (j == 0)
                printf("| ");
            printf("%*d ", max, mat->data[i][j]);
        }
        printf(" |\n");
    }
    printf(" --");
    printf("%*c", max * mat->c, ' ');
    printf(" --\n");
}

void char_matrix_print(char_matrix mat)
{
    if (mat->r == 0 && mat->c == 0)
    {
        printf("Matrix is empty ! \n");
        return;
    }
    int max = 0;
    for (int i = 0; i < mat->c; i++)
    {
        for (int j = 0; j < mat->r; j++)
        {
            if (countDigit(mat->data[i][j]) > max)
                max = countDigit(mat->data[i][j]);
        }
    }
    printf(" --");
    printf("%*c", max * mat->c, ' ');
    printf(" --\n");
    for (int i = 0; i < mat->r; i++)
    {
        for (int j = 0; j < mat->c; j++)
        {
            if (j == 0)
                printf("| ");
            printf("%*c ", max, mat->data[i][j]);
        }
        printf(" |\n");
    }
    printf(" --");
    printf("%*c", max * mat->c, ' ');
    printf(" --\n");
}

void long_matrix_print(long_matrix mat)
{
    if (mat->r == 0 && mat->c == 0)
    {
        printf("Matrix is empty ! \n");
        return;
    }
    int max = 0;
    for (int i = 0; i < mat->c; i++)
    {
        for (int j = 0; j < mat->r; j++)
        {
            if (countDigit(mat->data[i][j]) > max)
                max = countDigit(mat->data[i][j]);
        }
    }
    printf(" --");
    printf("%*c", max * mat->c, ' ');
    printf(" --\n");
    for (int i = 0; i < mat->r; i++)
    {
        for (int j = 0; j < mat->c; j++)
        {
            if (j == 0)
                printf("| ");
            printf("%*ld ", max, mat->data[i][j]);
        }
        printf(" |\n");
    }
    printf(" --");
    printf("%*c", max * mat->c, ' ');
    printf(" --\n");
}

void float_matrix_print(float_matrix mat)
{
    if (mat->r == 0 && mat->c == 0)
    {
        printf("Matrix is empty ! \n");
        return;
    }
    int max = 0;
    for (int i = 0; i < mat->c; i++)
    {
        for (int j = 0; j < mat->r; j++)
        {
            if (countDigit((int)mat->data[i][j]) > max)
                max = countDigit((int)mat->data[i][j]);
        }
    }
    printf(" --");
    printf("%*c", (max + 12) * (mat->c - 1), ' ');
    printf(" --\n");
    for (int i = 0; i < mat->r; i++)
    {
        for (int j = 0; j < mat->c; j++)
        {
            if (j == 0)
            {
                printf("| ");
                printf("%*f ", max, mat->data[i][j]);
            }
            else
                printf("%*lf ", max + 8, mat->data[i][j]);
        }
        printf(" |\n");
    }
    printf(" --");
    printf("%*c", (max + 12) * (mat->c - 1), ' ');
    printf(" --\n");
}

void double_matrix_print(double_matrix mat)
{
    if (mat->r == 0 && mat->c == 0)
    {
        printf("Matrix is empty ! \n");
        return;
    }
    int max = 0;
    for (int i = 0; i < mat->c; i++)
    {
        for (int j = 0; j < mat->r; j++)
        {
            if (countDigit((int)mat->data[i][j]) > max)
                max = countDigit((int)mat->data[i][j]);
        }
    }
    printf(" --");
    printf("%*c", (max+8) *( mat->c), ' ');
    printf(" --\n");
    for (int i = 0; i < mat->r; i++)
    {
        for (int j = 0; j < mat->c; j++)
        {
            if (j == 0)
                printf("| ");
            printf("%*lf ", max+8, mat->data[i][j]);
        }
        printf(" |\n");
    }
    printf(" --");
    printf("%*c", (max+8) * (mat->c), ' ');
    printf(" --\n");
}

#define print_matrix(TYPE, mat) TYPE##_matrix_print(mat)

#define matrix_declarations(TYPE)                                                 \
    TYPE##_matrix TYPE##_matrix_multiply(TYPE##_matrix mat1, TYPE##_matrix mat2); \
    TYPE##_matrix TYPE##_matrix_add(TYPE##_matrix mat1, TYPE##_matrix mat2);      \
    TYPE##_matrix TYPE##_matrix_sub(TYPE##_matrix mat1, TYPE##_matrix mat2);      \
    void TYPE##_swap_row(TYPE##_matrix mat, int i, int j);                        \
    int TYPE##_gauss_elim(TYPE##_matrix mat);                                     \
    void TYPE##_adjoint(TYPE **A, TYPE **adj,int n);                              \
    double_matrix TYPE##_matrix_inverse(TYPE##_matrix mat1);                      \
    void TYPE##_getCofactor(TYPE **mat, TYPE **temp, int p, int q, int n);        \
    TYPE TYPE##_matrix_determinant_help(TYPE **mat, int n, int N);                \
    TYPE TYPE##_matrix_determinant(TYPE##_matrix mat);                            \
    int TYPE##_matrix_insert(TYPE##_matrix mat, int n, ...);                      \
    void TYPE##_matrix_print(TYPE##_matrix mat);                                  \
    TYPE##_matrix TYPE##_matrix_transpose(TYPE##_matrix mat1);

#define matrix_multiply(TYPE)                                                       \
    TYPE##_matrix TYPE##_matrix_multiply(TYPE##_matrix mat1, TYPE##_matrix mat2)    \
    {                                                                               \
        int x, i, j;                                                                \
        if (mat1->c == mat2->r)                                                     \
        {                                                                           \
            TYPE **res = (TYPE **)malloc(mat1->r * sizeof(TYPE *));                 \
            for (i = 0; i < mat1->r; i++)                                           \
                res[i] = (TYPE *)malloc(mat2->c * sizeof(TYPE));                    \
            for (i = 0; i < mat1->r; i++)                                           \
            {                                                                       \
                for (j = 0; j < mat2->c; j++)                                       \
                {                                                                   \
                    res[i][j] = 0;                                                  \
                    for (x = 0; x < mat1->c; x++)                                   \
                    {                                                               \
                        *(*(res + i) + j) += *(*(mat1->data + i) + x) *             \
                                             *(*(mat2->data + x) + j);              \
                    }                                                               \
                }                                                                   \
            }                                                                       \
            TYPE##_matrix temp = (TYPE##_matrix)malloc(sizeof(TYPE##_matrix_size)); \
            temp->r = mat1->r;                                                      \
            temp->c = mat2->c;                                                      \
            temp->curr_r = mat1->curr_r;                                            \
            temp->data = res;                                                       \
            return temp;                                                            \
        }                                                                           \
        else                                                                        \
        {                                                                           \
            return NULL;                                                            \
        }                                                                           \
    }

#define matrix_add(TYPE)                                                                \
    TYPE##_matrix TYPE##_matrix_add(TYPE##_matrix mat1, TYPE##_matrix mat2)             \
    {                                                                                   \
        int x, i, j;                                                                    \
        if ((mat1->c == mat1->c) && (mat1->r == mat2->r))                               \
        {                                                                               \
            TYPE **res = (TYPE **)malloc(mat1->r * sizeof(TYPE *));                     \
            for (i = 0; i < mat1->r; i++)                                               \
                res[i] = (TYPE *)malloc(mat2->c * sizeof(TYPE));                        \
            for (i = 0; i < mat1->r; i++)                                               \
            {                                                                           \
                for (j = 0; j < mat2->c; j++)                                           \
                {                                                                       \
                    res[i][j] = mat1->data[i][j] + mat2->data[i][j];                    \
                }                                                                       \
                TYPE##_matrix temp = (TYPE##_matrix)malloc(sizeof(TYPE##_matrix_size)); \
                temp->r = mat1->r;                                                      \
                temp->c = mat2->c;                                                      \
                temp->curr_r = mat1->curr_r;                                            \
                temp->data = res;                                                       \
                return temp;                                                            \
            }                                                                           \
        }                                                                               \
        else                                                                            \
        {                                                                               \
            return NULL;                                                                \
        }                                                                               \
    }

#define matrix_sub(TYPE)                                                                \
    TYPE##_matrix TYPE##_matrix_sub(TYPE##_matrix mat1, TYPE##_matrix mat2)             \
    {                                                                                   \
        int x, i, j;                                                                    \
        if ((mat1->c == mat1->c) && (mat1->r == mat2->r))                               \
        {                                                                               \
            TYPE **res = (TYPE **)malloc(mat1->r * sizeof(TYPE *));                     \
            for (i = 0; i < mat1->r; i++)                                               \
                res[i] = (TYPE *)malloc(mat2->c * sizeof(TYPE));                        \
            for (i = 0; i < mat1->r; i++)                                               \
            {                                                                           \
                for (j = 0; j < mat2->c; j++)                                           \
                {                                                                       \
                    res[i][j] = mat1->data[i][j] + mat2->data[i][j];                    \
                }                                                                       \
                TYPE##_matrix temp = (TYPE##_matrix)malloc(sizeof(TYPE##_matrix_size)); \
                temp->r = mat1->r;                                                      \
                temp->c = mat2->c;                                                      \
                temp->curr_r = mat1->curr_r;                                            \
                temp->data = res;                                                       \
                return temp;                                                            \
            }                                                                           \
        }                                                                               \
        else                                                                            \
        {                                                                               \
                return NULL;                                                            \
        }                                                                               \
    }

#define swap_row(TYPE)                                      \
void TYPE##_swap_row(TYPE##_matrix mat, int i, int j)       \
{                                                           \
    for (int k = 0; k <= mat->c; k++)                       \
    {                                                       \
        TYPE temp = mat->data[i][k];                        \
        mat->data[i][k] = mat->data[j][k];                  \
        mat->data[j][k] = temp;                             \
    }                                                       \
}

#define gauss_elim(TYPE)                                    \
int TYPE##_gauss_elim(TYPE##_matrix mat)                    \
{                                                           \
    for (int k = 0; k < mat->c; k++)                        \
    {                                                       \
        int i_max = k;                                      \
        TYPE v_max = mat->data[i_max][k];                   \
        for (int i = k + 1; i < mat->c; i++)                \
            if (abs(mat->data[i][k]) > v_max)               \
                v_max = mat->data[i][k], i_max = i;         \
        if (!mat->data[k][i_max])                           \
            return k;                                       \
        if (i_max != k)                                     \
            TYPE##_swap_row(mat, k, i_max);                 \
        for (int i = k + 1; i < mat->c; i++)                \
        {                                                   \
            TYPE f = mat->data[i][k] / mat->data[k][k];     \
            for (int j = k + 1; j <= mat->c; j++)           \
                mat->data[i][j] -= mat->data[k][j] * f;     \
            mat->data[i][k] = 0;                            \
        }                                                   \
    }                                                       \
    return -1;                                              \
}

#define matrix_getCofactor(TYPE)                                   \
    void TYPE##_getCofactor(TYPE **mat, TYPE **temp, int p, int q, int n) \
    {                                                              \
        int i = 0, j = 0;                                          \
        for (int row = 0; row < n; row++)                          \
        {                                                          \
            for (int col = 0; col < n; col++)                      \
            {                                                      \
                if (row != p && col != q)                          \
                {                                                  \
                    temp[i][j++] = mat[row][col];                  \
                    if (j == n - 1)                                \
                    {                                              \
                        j = 0;                                     \
                        i++;                                       \
                    }                                              \
                }                                                  \
            }                                                      \
        }                                                          \
    }

#define matrix_determinant_help(TYPE)                                               \
    TYPE TYPE##_matrix_determinant_help(TYPE **mat, int n, int N)                   \
    {                                                                               \
        TYPE D = 0;                                                                 \
        if (n == 1)                                                                 \
            return mat[0][0];                                                       \
        TYPE **temp = (TYPE **)malloc(N * sizeof(TYPE *));                          \
        for (int i = 0; i < N; i++)                                                 \
            temp[i] = (TYPE *)malloc(N * sizeof(TYPE));                             \
        int sign = 1;                                                               \
        for (int f = 0; f < n; f++)                                                 \
        {                                                                           \
            TYPE##_getCofactor(mat, temp, 0, f, n);                                 \
            D += sign * mat[0][f] * TYPE##_matrix_determinant_help(temp, n - 1, N); \
            sign = -sign;                                                           \
        }                                                                           \
        free(temp);                                                                 \
        return D;                                                                   \
    }

#define matrix_determinant(TYPE)                                       \
    TYPE TYPE##_matrix_determinant(TYPE##_matrix mat)                  \
    {                                                                  \
        if (mat->r != mat->c)                                          \
        {                                                              \
            return 0;                                                  \
        }                                                              \
        else                                                           \
        {                                                              \
            return TYPE##_matrix_determinant_help(mat->data, mat->r,mat->r); \
        }                                                              \
    }
#define adjoint(TYPE)                                                                             \
    void TYPE##_adjoint(TYPE **A, TYPE **adj, int n)                                              \
    {                                                                                             \
        if (n == 1)                                                                               \
        {                                                                                         \
            adj[0][0] = 1;                                                                        \
            return;                                                                               \
        }                                                                                         \
        int sign = 1;                                                                             \
        TYPE **temp = (TYPE **)malloc(n * sizeof(TYPE *));                                  \
        for (int i = 0; i < n; i++)                                                               \
            temp[i] = (TYPE *)malloc(n * sizeof(TYPE));                                       \
        for (int i = 0; i < n; i++)                                                               \
        {                                                                                         \
            for (int j = 0; j < n; j++)                                                           \
            {                                                                                     \
                TYPE##_getCofactor(A, temp, i, j, n);                                             \
                sign = ((i + j) % 2 == 0) ? 1 : -1;                                               \
                adj[j][i] = (sign) * (TYPE##_matrix_determinant_help(temp,n-1,n-1)); \
            }                                                                                     \
        }                                                                                         \
        free(temp);\
    }

#define matrix_inverse(TYPE)                                                   \
    double_matrix TYPE##_matrix_inverse(TYPE##_matrix mat1)                    \
    {                                                                          \
        TYPE det = TYPE##_matrix_determinant(mat1);                            \
        if (det == 0)                                                          \
        {                                                                      \
            return NULL;                                                       \
        }                                                                      \
        if (mat1->r != mat1->c)                                                \
            return NULL;                                                       \
        double **res = (double **)malloc(mat1->r * sizeof(double *));          \
        for (int i = 0; i < mat1->r; i++)                                      \
            res[i] = (double *)malloc(mat1->c * sizeof(double));               \
        double_matrix mat = (double_matrix)malloc(sizeof(double_matrix_size)); \
        mat->r = mat1->r;                                                      \
        mat->c = mat1->c;                                                      \
        mat->curr_r = mat1->curr_r;                                            \
        mat->data = res;                                                       \
        TYPE **adj = (TYPE **)malloc(mat1->r * sizeof(TYPE *));                \
        for (int i = 0; i < mat1->r; i++)                                      \
            adj[i] = (TYPE *)malloc(mat1->c * sizeof(TYPE));                   \
        TYPE##_adjoint(mat1->data, adj, mat->r);                               \
        for (int i = 0; i < mat->r; i++)                                       \
            for (int j = 0; j < mat->c; j++)                                   \
                res[i][j] = adj[i][j] / (double)(det);                         \
        free(adj);                                                             \
        return mat;                                                            \
    }

#define matrix_transpose(TYPE)                                                 \
    TYPE##_matrix TYPE##_matrix_transpose(TYPE##_matrix mat1)                  \
    {                                                                          \
        TYPE **res = (TYPE **)malloc(mat1->c * sizeof(TYPE *));                \
        for (int i = 0; i < mat1->c; i++)                                      \
            res[i] = (TYPE *)malloc(mat1->r * sizeof(TYPE));                   \
        TYPE##_matrix mat = (TYPE##_matrix)malloc(sizeof(TYPE##_matrix_size)); \
        mat->r = mat1->c;                                                      \
        mat->c = mat1->r;                                                      \
        mat->curr_r = mat1->c;                                                 \
        mat->data = res;                                                       \
        int j;                                                                 \
        for (int i = 0; i < mat->r; i++)                                       \
            for (j = 0; j < mat->c; j++)                                       \
                mat->data[i][j] = mat1->data[j][i];                            \
        return mat;                                                            \
    }

#define matrix_new(TYPE)                                                       \
    TYPE##_matrix TYPE##_matrix_new(int r, int c)                              \
    {                                                                          \
        TYPE **res = (TYPE **)malloc(r * sizeof(TYPE *));                      \
        for (int i = 0; i < r; i++)                                                \
            res[i] = (TYPE *)malloc(c * sizeof(TYPE));                         \
        TYPE##_matrix mat = (TYPE##_matrix)malloc(sizeof(TYPE##_matrix_size)); \
        mat->r = r;                                                            \
        mat->c = c;                                                            \
        mat->data = res;                                                       \
        mat->curr_r = -1;                                                       \
        return mat;                                                            \
    }

#define matrix_insert_row(TYPE)                                               \
    int TYPE##_matrix_insert(TYPE##_matrix mat, int n, ...)                   \
    {                                                                         \
        va_list ap;                                                           \
        va_start(ap, n);                                                      \
        if (n > mat->c)                                                       \
            return 0;                                                         \
        if (mat->curr_r == mat->r - 1)                                        \
        {                                                                     \
            mat->data = (TYPE **)realloc(mat->data, (mat->r + 1) * sizeof(TYPE *)); \
            mat->data[mat->r]=(TYPE *)malloc(mat->c * sizeof(TYPE)); \
            mat->r+=1;                                                        \
        }                                                                     \
        mat->curr_r += 1;                                                     \
        for (int i = 0; i < n; i++)                                           \
        {                                                                     \
            mat->data[mat->curr_r][i] = va_arg(ap, TYPE);                     \
        }                                                                     \
        return 1;                                                             \
    }

#define define_matrix(TYPE)   \
    matrix_declarations(TYPE) \
    matrix_new(TYPE) \
    matrix_multiply(TYPE) \
    matrix_add(TYPE)  \
    matrix_sub(TYPE)  \
    swap_row(TYPE)   \
    gauss_elim(TYPE) \
    adjoint(TYPE) \
    matrix_inverse(TYPE)\
    matrix_getCofactor(TYPE) \
    matrix_determinant_help(TYPE) \
    matrix_determinant(TYPE) \
    matrix_transpose(TYPE)\
    matrix_insert_row(TYPE)\

#define new_matrix(TYPE,r,c) \
    TYPE##_matrix_new(r,c)

#define multiply_matrix(TYPE,mat1,mat2)\
    TYPE##_matrix_multiply(mat1,mat2)

#define add_matrix(TYPE, mat1, mat2) \
    TYPE##_matrix_add(mat1,mat2)

#define sub_matrix(TYPE, mat1, mat2) \
    TYPE##_matrix_sub(mat1, mat2)

#define transpose_matrix(TYPE,mat1)\
    TYPE##_matrix_transpose(mat1)

#define determinant_matrix(TYPE,mat) \
    TYPE##_matrix_determinant(mat)

#define inverse_matrix(TYPE, mat1) \
    TYPE##_matrix_inverse(mat1)

#define insert_row_matrix(TYPE, mat,n,...) \
    TYPE##_matrix_insert(mat,n, __VA_ARGS__)
