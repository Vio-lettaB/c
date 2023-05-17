#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>


typedef struct
{
    double *A;
    int row_size;
    int col_size;

}Matrix;




Matrix *init_matrix(int col_size, int row_size) 
{
    Matrix* M = (Matrix*)malloc(sizeof(Matrix));
    M->row_size = row_size;
    M->col_size = col_size;
    M->A = (double*)malloc(sizeof(double) * col_size * row_size);
    
    for (int i = 0; i < col_size * row_size; i++)
    {
        M->A[i] = 0;
    }
    return M;
}


Matrix *make_diagonal_matrix(int col_size, int row_size)
{
    Matrix* M = (Matrix*)malloc(sizeof(Matrix));
    M->row_size = row_size;
    M->col_size = col_size;
    M->A = (double*)malloc(sizeof(double) * col_size * row_size);
    
    int col_idx = 0;
    int row_idx = 0;
  
    for ( col_idx = 0; col_idx < M->col_size; col_idx++ )
    {
        for ( row_idx = 0; row_idx < M->row_size; row_idx++ )
        {
            M->A[M->row_size * col_idx + row_idx] = (int)(col_idx == row_idx) * 2;
        }
    }
    return M;
}



void destroy_matrix(Matrix *M)
{
    free(M->A);
    free(M);
   
}



/*
main() {
    Matrix A = init_matrix(...)
    Matrix B = init_matrix(...)
    C = ..
    C = A + b
    
    destroy_matrix(A)
    destroy_matrix(b)
    destroy_matrix(c)
}
*/


void PrintMatrix(Matrix *matA)
{
    int row_idx = 0;
    int col_idx = 0;
    for ( col_idx = 0; col_idx < matA->col_size; col_idx++ )
    {
        printf("\t");
        for ( row_idx = 0; row_idx < matA->row_size; row_idx++ )
        {
            printf( "%lf\t", matA->A[matA->row_size * col_idx + row_idx]);
        }
    printf( "\n" );
    }
    printf("\n");

}

Matrix *summ(Matrix *matA, Matrix *matB)
{   
    if( matA->row_size != matB->row_size || matA->col_size != matB->col_size )
    {
       
       printf("Error: can not sum matrices with shapes (%d, %d) and (%d, %d)\n", matA->col_size, matA->row_size, matB->col_size, matB->row_size);
       return NULL;

    }
    else
    {
        Matrix *matC = init_matrix(matA->col_size, matA->row_size);
        for (int i = 0; i < matA->row_size * matA->col_size; i++) 
        {
            matC->A[i] = matA->A[i] + matB->A[i];
        }
        printf("сумма матриц A и B:\n\n");
        return matC;  
    }
}

int test_summ()
{
    double M1_data[4] = {1., 2., 3., 4.};
    double M2_data[4] = {5., 6., 7., 8.};
    double expected_result_data[4] = {6., 8., 10., 12.};

    Matrix* M1 = init_matrix(2, 2);
    Matrix* M2 = init_matrix(2, 2);
    memcpy(M1->A, &M1_data, 4 * sizeof(double));
    memcpy(M2->A, &M2_data, 4 * sizeof(double));

    Matrix* out = summ(M1, M2);
    for (int i = 0; i < 4; i++) 
    {
        if (fabs(out->A[i] - expected_result_data[i]) > 1.e-5) 
        {
            printf("Error: out->A[%d] == %lf; expected: out->A[%d] == %lf\n", 
                   i, out->A[i], i, expected_result_data[i]);
            return 1;
        }
    }
    destroy_matrix(M1);
    destroy_matrix(M2);
    destroy_matrix(out);
    return 0;
}




Matrix *mult(Matrix *matA, Matrix *matB)
{
    
    if( matA->row_size != matB->col_size )
    {
        printf("Error: can not multiply matrices with shapes (%d, %d) and (%d, %d)\n", matA->col_size, matA->row_size, matB->col_size, matB->row_size);
        return NULL;
    }
    else
    {
        Matrix *matC = init_matrix(matA->col_size, matB->row_size);
        int col_idx = 0;
        while ( col_idx < matC->col_size )
        {
            // printf("%d\n", col_idx);
            int row_idx = 0; 
            while ( row_idx < matC->row_size )
            {
                int k = 0;
                while ( k < matC->col_size )
                {
                    matC->A[matA->row_size * col_idx + row_idx] += ( matA->A[matA->row_size * col_idx + k] *  matB->A[matB->row_size * k + row_idx]);
                    // printf(" IJ of A %lf\n", matA->A[matA->row_size * k + row_idx]);
                    // printf(" IJ of B %lf\n", matB->A[matA->row_size * col_idx + k]);
                    k++;
                }
                row_idx++;
            }
            col_idx++;
        }
        printf("произведение матриц A и B:\n\n");
        return matC;  
    }
}

int test_mult() 
{
    double M1_data[4] = {1., 2., 3., 4.};
    double M2_data[4] = {5., 6., 7., 8.};
    double expected_result_data[4] = {19., 22., 43., 50.};

    Matrix* M1 = init_matrix(2, 2);
    Matrix* M2 = init_matrix(2, 2);
    memcpy(M1->A, &M1_data, 4 * sizeof(double));
    memcpy(M2->A, &M2_data, 4 * sizeof(double));

    Matrix* out = mult(M1, M2);
    for (int i = 0; i < 4; i++) 
    {
        if (fabs(out->A[i] - expected_result_data[i]) > 1.e-5) 
        {
            printf("Error: out->A[%d] == %lf; expected: out->A[%d] == %lf\n\n", i, out->A[i], i, expected_result_data[i]);
            return 1;
        }
    }
    destroy_matrix(M1);
    destroy_matrix(M2);
    destroy_matrix(out);
    return 0;
    return 0;
}




Matrix *make_minor(Matrix *matA, int i, int j)
{
   
    Matrix *matB = init_matrix(matA->col_size - 1, matA->row_size - 1) ;
    for(int col_idx = 0; col_idx < matB->col_size; col_idx++ )
    {
       for(int row_idx = 0; row_idx < matB->row_size;  row_idx++ )
       {
            if(row_idx < i && col_idx < j) 
            {
                matB->A[matB->row_size * col_idx + row_idx] = matA->A[matA->row_size * col_idx + row_idx];
            }
            if (row_idx >= i )
            {
                matB->A[matB->row_size * col_idx + row_idx] = matA->A[matA->row_size * col_idx  + (row_idx + 1)];
            }
              if (col_idx >= j )
            {
                matB->A[matB->row_size * col_idx + row_idx] = matA->A[matA->row_size * (col_idx + 1) + row_idx ];
            }
            if(row_idx >= i && col_idx >= j) 
            {
                matB->A[matB->row_size * col_idx + row_idx] = matA->A[matA->row_size * (col_idx + 1) + (row_idx + 1)];
            }
        // printf( "%lf\t",  matB.A[matA->row_size * col_idx + row_idx] );
       }
        // printf("\n");
    }
    // printf("\n");
    return matB;
}

int test_minor()
{
    double M1_data[9] = {1., 2., 3., 4., 5., 6., 7., 8., 9.};

    double expected_result_data_a[4] = {5., 6., 8., 9.};
    double expected_result_data_b[4] = {4., 6., 7., 9.};
    double expected_result_data_c[4] = {4., 5., 7., 8.};
    double expected_result_data_d[4] = {2., 3., 8., 9.};
    double expected_result_data_e[4] = {1., 3., 7., 9.};
    double expected_result_data_f[4] = {1., 2., 7., 8.};
    double expected_result_data_g[4] = {2., 3., 5., 6.};
    double expected_result_data_h[4] = {1., 3., 4., 6.};
    double expected_result_data_i[4] = {1., 2., 4., 5.};

    Matrix* M1 = init_matrix(3, 3);
    memcpy(M1->A, &M1_data, 9 * sizeof(double));

    for (int i = 0; i < 3; i ++)
    {
        for (int j = 0; j < 3; j ++)
        {
           
            switch( 3 * i + j)
            {
                case  0:
                {   
                    Matrix *out = make_minor(M1, j, i);
                    for (int k = 0; k < 4; k++) 
                    {
                        if (fabs(out->A[k] - expected_result_data_a[k]) > 1.e-5) 
                        {
                            printf("Error:  minor 1) out->A[%d] == %lf; expected: out->A[%d] == %lf\n",
                            k, out->A[k], k, expected_result_data_a[k]);
                            destroy_matrix(out);
                            return 1;
                        }
                        
                    }
                    break;
                }
                case  1:
                {
                    for (int k = 0; k < 4; k++) 
                    {   
                        Matrix *out = make_minor(M1, j, i);
                        if (fabs(out->A[k] - expected_result_data_b[k]) > 1.e-5) 
                        {
                            printf("Error: minor 2) out->A[%d] == %lf; expected: out->A[%d] == %lf\n",
                            k, out->A[k], k, expected_result_data_b[k]);
                            destroy_matrix(out);
                            return 1;
                        }  
                    }
                    break;
                }
                case 2:
                {
                    for (int k = 0; k < 4; k++) 
                    {
                        Matrix *out = make_minor(M1, j, i);
                        if (fabs(out->A[k] - expected_result_data_c[k]) > 1.e-5) 
                        {
                            printf("Error:  minor 3) out->A[%d] == %lf; expected: out->A[%d] == %lf\n",
                            k, out->A[k], k, expected_result_data_c[k]);
                            destroy_matrix(out);
                            return 1;
                        }
                    }
                    break;
                }
                case 3:
                {
                    for (int k = 0; k < 4; k++) 
                    {
                        Matrix *out = make_minor(M1, j, i);
                        if (fabs(out->A[k] - expected_result_data_d[k]) > 1.e-5) 
                        {
                            printf("Error: minor 4) out->A[%d] == %lf; expected: out->A[%d] == %lf\n",
                            k, out->A[k], k, expected_result_data_d[k]);
                            destroy_matrix(out);
                            return 1;
                        }
                    }
                    break;
                }
                case 4:
                {
                    for (int k = 0; k < 4; k++) 
                    {
                        Matrix *out = make_minor(M1, j, i);
                        if (fabs(out->A[k] - expected_result_data_e[k]) > 1.e-5) 
                        {
                            printf("Error:  minor 5) out->A[%d] == %lf; expected: out->A[%d] == %lf\n", 
                            k, out->A[k], k, expected_result_data_e[k]);
                            destroy_matrix(out);
                            return 1;
                        }
                    }
                    break;
                }
                case 5:
                {
                    for (int k = 0; k < 4; k++) 
                    {
                        Matrix *out = make_minor(M1, j, i);
                        if (fabs(out->A[k] - expected_result_data_f[k]) > 1.e-5) 
                        {
                            printf("Error: minor 6) out->A[%d] == %lf; expected: out->A[%d] == %lf\n", 
                            k, out->A[k], k, expected_result_data_f[k]);
                            destroy_matrix(out);
                            return 1;
                        }
                    }
                    break;
                }
                case 6:
                {
                    for (int k = 0; k < 4; k++) 
                    {
                        Matrix *out = make_minor(M1, j, i);
                        if (fabs(out->A[k] - expected_result_data_g[k]) > 1.e-5) 
                        {
                            printf("Error: minor 7) out->A[%d] == %lf; expected: out->A[%d] == %lf\n",
                            k, out->A[k], k, expected_result_data_g[k]);
                            destroy_matrix(out);
                            return 1;
                        }
                    }
                    break;
                }
                case 7:
                {
                    for (int k = 0; k < 4; k++) 
                    {
                        Matrix *out = make_minor(M1, j, i);
                        if (fabs(out->A[k] - expected_result_data_h[k]) > 1.e-5) 
                        {
                            printf("Error: minor 8) out->A[%d] == %lf; expected: out->A[%d] == %lf\n", 
                            k, out->A[k], k, expected_result_data_h[k]);
                            destroy_matrix(out);
                            return 1;
                        }
                    }
                    break;
                }
                case 8:
                {
                    for (int k = 0; k < 4; k++) 
                    {
                        Matrix *out = make_minor(M1, j, i);
                        if (fabs(out->A[k] - expected_result_data_i[k]) > 1.e-5) 
                        {
                            printf("Error: minor 9) out->A[%d] == %lf; expected: out->A[%d] == %lf\n",
                            k, out->A[k], k, expected_result_data_i[k]);
                            destroy_matrix(out);
                            return 1;
                        }
                    }
                    break;
                }
                
            }
        }
     }
    destroy_matrix(M1);
    
    return 0;

}

double det(Matrix *matA)
{   
   
    if( matA->row_size != matA->col_size)
    {
        printf("Error: can not to calculatethe determinant matrix with shapes (%d, %d)\n\n", matA->col_size, matA->row_size);
        return 0;
    }
    else
    {
        int d = 0;
        if(matA->col_size == 1)
        {
            return matA->A[0];
           
        }
        else
        {
            if(  matA->col_size == 2)
            {
                double d = 0;
                int x = 0;
                int y = 0;
                // printf("help!!!\n");
                if (matA->A[0]  != 0 && matA->A[3] != 0 )
                {
                    x = matA->A[0] * matA->A[3]; 
                    // printf(" x = %d\n", x);
                }
                if (matA->A[2]  != 0 && matA->A[1] != 0 )
                {
                    y = matA->A[2] * matA->A[1]; 
                    // printf(" y = %d\n", y);
                }
                return d = x - y;
            }
            else
            {
                
                for ( int col_idx = 0; col_idx < matA->col_size; col_idx++ )
                {
                    // printf("%d\n", col_idx);
                    for ( int row_idx = 0; row_idx < matA->row_size; row_idx++ )
                    {
                        Matrix *matB = make_minor( matA, row_idx, col_idx);
                        // printf("\n");
                        d += pow(- 1, row_idx ) * matA->A[matA->row_size * col_idx + row_idx] * det(matB);
                    }
                }
               
            }
             
        }
        return d;
    }
}

int test_det_1()
{
    double M1_data[1]= {2};
    double expected_result_det = 2;
    Matrix* M1 = init_matrix(1, 1);
    memcpy(M1->A, &M1_data, 1 * sizeof(double));
    double out = det(M1);
    
    if (fabs(out - expected_result_det) > 1.e-5) 
    {
        printf("Error:  det 1_1 out 1 == %lf; expected: out == %lf\n\n", out, expected_result_det);
        return 1;
    }
    
    destroy_matrix(M1);
    return 0;
    
}

int test_det() 
{
    double M1_data[4] = {1., 2., 3., 4.};
    
    double expected_result_det = -2 ;

    Matrix* M1 = init_matrix(2, 2);
    memcpy(M1->A, &M1_data, 4 * sizeof(double));

    double out = det(M1);
    
    
    if (fabs(out - expected_result_det) > 1.e-5) 
    {
        printf("Error: det:  out == %lf; expected: out == %lf\n\n", out, expected_result_det);
        return 1;
    }
    
    destroy_matrix(M1);
    return 0;
}

Matrix *inverse(Matrix *matA, double d)
{
    if( matA->row_size != matA->col_size)
    {
        printf("Error: can not find the inverse matrix, because matrix with shapes (%d, %d)\n\n", matA->col_size, matA->row_size);
        return NULL; 
    }
    else
    {
        Matrix *matB = init_matrix(matA->col_size, matA->row_size) ;
        if (matA->col_size == 1)
        {
            matB->A[0] = 1/matA->A[0];
        }
        else
        {
            for( int col_idx = 0; col_idx < matA->col_size; col_idx++)
            {
                for( int row_idx = 0; row_idx < matA->row_size; row_idx++)
                {
                    Matrix *matC = make_minor(matA, row_idx, col_idx);
                    
                    // print_minor(&m);
                    // printf("\n");
    
                    matB->A[matB->col_size * row_idx + col_idx] = pow(- 1, col_idx + row_idx + 1) *  (det(matC)/ d);
                    // printf("minor det = %lf\n", det(matC));
                    // printf(" det = %lf\n\n", d);
                    // printf("det minor = %d\n\n", det_minor(&m));
                }
            }
        }
        
        // printf("\n");
        printf("обратная к матрице A:\n\n");
        return matB;
    }
}

int test_inverse()
{
    double M1_data[4] = {1., 2., 3., 4.};
    double expected_result_data[4] = {-2.0, 1.0, 1.5, -0.5};

    Matrix* M1 = init_matrix(2, 2);
    memcpy(M1->A, &M1_data, 4 * sizeof(double));

    Matrix* out = inverse(M1, 2);
    for (int i = 0; i < 4; i ++)
    {
        printf("%lf\n", out->A[i]);
    }
    for (int i = 0; i < 4; i++) 
    {
        
        if (fabs(out->A[i] - expected_result_data[i]) > 1.e-5) 
        {
            printf("Error: inverse: out->A[%d] == %lf; expected: out->A[%d] == %lf\n\n", i, out->A[i], i, expected_result_data[i]);
            return 1;
        }
    }
    destroy_matrix(M1);
    destroy_matrix(out);
    return 0;
}


int main()
{
    test_summ();
    test_mult();
    test_det_1();
    test_minor();
    test_det();
    test_inverse();
    exit(1);
    int col_size1;
    int col_size2;
    int row_size1;
    int row_size2;
    
    
    
    printf("Введите размер столбцов матрицы A: \n");
    scanf("%d", &col_size1); 
    printf("Введите размер строк матрицы A: \n");
    scanf("%d", &row_size1); 
    printf("Введите размер столбцов матрицы B: \n");
    scanf("%d", &col_size2); 
    printf("Введите размер строк матрицы B: \n");
    scanf("%d", &row_size2); 

    Matrix *A = make_diagonal_matrix( col_size1, row_size1);
    Matrix *B = make_diagonal_matrix( col_size2, row_size2);
    Matrix *C;
    double DET;
    
    PrintMatrix(A);
    PrintMatrix(B);
    
   
    C = summ(A, B);
    PrintMatrix(C);
    destroy_matrix(C);
    
    
    C = mult(A, B);
    PrintMatrix(C);
    destroy_matrix(C);
    
    DET = det(A);
    printf("det a = %lf\n\n", DET);
    destroy_matrix(C);
    
  
    C = inverse(A, DET);
    PrintMatrix(C);
    destroy_matrix(C);
    destroy_matrix(B);
    destroy_matrix(A);
    
}
