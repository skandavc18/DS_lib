#include "matrix.h"

define_matrix(double)

void main()
{
    double_matrix mat= new_matrix(double,2,3);
    insert_row_matrix(double,mat,3,6.,7.,9.);
    insert_row_matrix(double, mat, 3, 9.,8.,9.);
    insert_row_matrix(double, mat, 3, 6.,3.,1.);
    printf("A :\n");
    print_matrix(double, mat);
    printf("Determinant : %lf\n",determinant_matrix(double,mat));
    double_matrix inv=inverse_matrix(double,mat);
    printf("inverse(A) :\n");
    print_matrix(double, inv);
    double_matrix mul=multiply_matrix(double,mat,inv);
    printf("A*inverse(A) :\n");
    print_matrix(double,mul);
}