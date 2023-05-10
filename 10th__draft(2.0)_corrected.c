#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    double *A;
    int row_size;
    int col_size;
} Matrix;

Matrix* init_matrix(int col_size, int row_size) 
{
    Matrix* M = (Matrix*)malloc(sizeof(Matrix));
    M->row_size = row_size;
    M->col_size = col_size;
    M->A = (double*)malloc(sizeof(double) * col_size * row_size);
    
    // int col_idx = 0;
    // int row_idx = 0;
    // for (col_idx = 0; col_idx < M->col_size; col_idx++)
    // {
    //     for (row_idx = 0; row_idx < M->row_size; row_idx++)
    //     {
    //         M->A[M->row_size * col_idx + row_idx] = 0;
    //     }
    // } можно записать короче
    for (int i = 0; i < col_size * row_size; i++) {
        M->A[i] = 0;
    }
    return M;
}

void destroy_matrix(Matrix* M)
{
    free(M->A);
    free(M);
}

void PrintMatrix(Matrix *M)
{
    int row_idx = 0;
    int col_idx = 0;
    for ( col_idx = 0; col_idx < M->col_size; col_idx++ )
    {
        printf("\t");
        for ( row_idx = 0; row_idx < M->row_size; row_idx++ )
        {
            printf( "%lf\t", M->A[M->row_size * col_idx + row_idx]);
        }
    printf( "\n" );
    }
    printf("\n");
    // return *matA; возвращать матрицу, которая была только что напечатана не нужно
}

Matrix* summ(Matrix *matA, Matrix *matB)
{   
    int A_width = matA->row_size;
    int A_height = matA->col_size;
    int B_width = matB->row_size;
    int B_heigh = matB->row_size;
    if((A_height != B_heigh) || (A_width != B_width))
    {
       printf("Error: can not sum matrices with shapes (%d, %d) and (%d, %d)\n", A_height, A_width, B_heigh, B_width);
       return NULL;
    }
    Matrix* result = init_matrix(matA->col_size, matA->row_size) ;
    for (int i = 0; i < A_width * A_height; i++) {
        result->A[i] = matA->A[i] + matB->A[i];
    }
    return result;
}

int test_summ() {
    double M1_data[4] = {1., 2., 3., 4.};
    double M2_data[4] = {5., 6., 7., 8.};
    double expected_result_data[4] = {6., 8., 10., 12.};

    Matrix* M1 = init_matrix(2, 2);
    Matrix* M2 = init_matrix(2, 2);
    memcpy(M1->A, &M1_data, 4 * sizeof(double));
    memcpy(M2->A, &M2_data, 4 * sizeof(double));

    Matrix* out = summ(M1, M2);
    for (int i = 0; i < 4; i++) {
        if (fabs(out->A[i] - expected_result_data[i]) > 1.e-5) {
            printf("Error: out->A[%d] == %lf; expected: out->A[%d] == %lf", 
                   i, out->A[i], i, expected_result_data[i]);
            return 1;
        }
    }
    destroy_matrix(M1);
    destroy_matrix(M2);
    destroy_matrix(out);
    return 0;
}

int test_mult() {
    //напиши то же самое что и со сложением, только для умножения
    return 0;
}

int test_det() {
    return 0;
}

int test_minor() {
    return 0;
}

int test_inverse() {
    return 0;
}

int main()
{
    int ret;
    ret = test_summ();
    ret = test_mult();
    //и так далее
    if (ret == 0) {
        printf("all tests ok\n");
    }   
}
