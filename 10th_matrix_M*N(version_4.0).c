#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct
{
    double *A;
    int row_size;
    int col_size;
}Matrix;



Matrix dynamic_array_alloc(int col_size, int row_size)
{
    Matrix matA;
    matA.row_size = row_size;
    matA.col_size = col_size;
    matA.A = (double *)malloc((matA.row_size*matA.col_size)*sizeof(double *));
    return matA;
}


Matrix init_matrix(Matrix * matA)
{
    Matrix matB = dynamic_array_alloc(matA->col_size, matA->row_size); 
    int col_idx = 0;
    int row_idx = 0;
    for (col_idx = 0; col_idx < matA->col_size; col_idx++ )
    {
        for ( row_idx = 0; row_idx < matA->row_size; row_idx++ )
        {
            matB.A[matA->row_size * col_idx + row_idx] = 0;
        }
    }
    return matB;
}


Matrix init_mult_matrix(Matrix * matA, Matrix * matB)
{
    Matrix matC = dynamic_array_alloc(matA->col_size, matB->row_size); 
    int col_idx = 0;
    int row_idx = 0;
    for (col_idx = 0; col_idx < matA->col_size; col_idx++ )
    {
        for ( row_idx = 0; row_idx < matB->row_size; row_idx++ )
        {
            matC.A[matC.row_size * col_idx + row_idx] = 0;
        }
    }
    return matC;
}


Matrix init_minor(Matrix * matA)
{
    Matrix matB = dynamic_array_alloc(matA->col_size - 1, matA->row_size - 1 ); 
    int col_idx = 0;
    int row_idx = 0;
    for (col_idx = 0; col_idx < matA->col_size; col_idx++ )
    {
        for ( row_idx = 0; row_idx < matA->row_size; row_idx++ )
        {
            matB.A[matB.row_size * col_idx + row_idx] = 0;
        }
    }
    return matB;
}





Matrix make_diagonal_matrix(Matrix  *matA)
{
    Matrix matB = dynamic_array_alloc(matA->col_size, matA->row_size);
    int i = 0;
    int col_idx = 0;
    int row_idx = 0;
  
    for ( col_idx = 0; col_idx < matA->col_size; col_idx++ )
    {
        for ( row_idx = 0; row_idx < matA->row_size; row_idx++ )
        {
            matB.A[matA->row_size * col_idx + row_idx] = (int)(col_idx != row_idx) * 2;
        }
    }
    return matB;
}



Matrix PrintMatrix(Matrix *matA)
{
    Matrix matB = init_matrix( matA );
    matB = make_diagonal_matrix( &matB );
    int row_idx = 0;
    int col_idx = 0;
    for ( col_idx = 0; col_idx < matA->col_size; col_idx++ )
    {
        for ( row_idx = 0; row_idx < matA->row_size; row_idx++ )
        {
            printf( "%lf\t", matB.A[matA->row_size * col_idx + row_idx]);
        }
    printf( "\n" );
    }
    printf("\n");
    return matB;
}

Matrix summ(Matrix *matA, Matrix *matB)
{   
    if( matA->row_size != matB->row_size || matA->col_size != matB->col_size )
    {
       printf("матрицы имеют различные размеры, суммирование не возможно!(");
    }
    else
    {
        Matrix matC = init_matrix( matA );
        for ( int row_idx = 0; row_idx < matC.row_size; row_idx++ )
        {
            int col_idx = 0;
            printf("%d\n", row_idx);
            for ( col_idx = 0; col_idx < matC.col_size; col_idx++ )
            {
                matC.A[matA->row_size * col_idx + row_idx] = (int) matA->A[matA->row_size * col_idx + row_idx] + (int) matB->A[matB->row_size * col_idx + row_idx];
                printf(" IJ of A %lf\n", matA->A[matA->row_size * col_idx + row_idx]);
                printf(" IJ of B %lf\n", matB->A[matA->row_size * col_idx + row_idx]);
                
            }
        }
        return matC;  
    }
}



Matrix mult(Matrix *matA, Matrix *matB)
{
    if( matA->row_size != matB->col_size )
    {
       printf("матрицы имеют различные размеры, умножение не возможно!(");
    }
    else
    {
        Matrix matC = init_mult_matrix( matA, matB );
        for ( int row_idx = 0; row_idx < matC.row_size; row_idx++ )
        {
            int col_idx = 0;
            printf("%d\n", row_idx);
            for ( col_idx = 0; col_idx < matC.col_size; col_idx++ )
            {
                for(int k = 0; k < matC.col_size; k++)
                {
                    matC.A[matA->row_size * col_idx + row_idx] += (int) matA->A[matA->row_size * k + row_idx] + (int) matB->A[matB->row_size * col_idx + k];
                    printf(" IJ of A %lf\n", matA->A[matA->row_size * k + row_idx]);
                    printf(" IJ of B %lf\n", matB->A[matA->row_size * col_idx + k]);
                }
            }
        }
        return matC;  
    }
}


Matrix make_minor(Matrix *matA, int i, int j)
{
    Matrix matB = init_minor( matA );
    for(int row_idx = 0; row_idx < matB.row_size; row_idx++ )
    {
       for(int col_idx = 0; col_idx < matB.col_size;  col_idx++ )
       {
          if(row_idx < i && col_idx < j) 
          {
            matB.A[matA->row_size * col_idx + row_idx] = matA->A[matA->row_size * col_idx + row_idx];
          }
          if (row_idx >= i )
          {
            matB.A[matA->row_size * col_idx + row_idx] = matA->A[matA->row_size * (col_idx + 1) + row_idx];
          }
          if (col_idx >= j )
          {
            matB.A[matA->row_size * col_idx + row_idx] = matA->A[matA->row_size * col_idx + (row_idx + 1)];
          }
          if(row_idx >= i && col_idx >= j) 
          {
            matB.A[matA->row_size * col_idx + row_idx] = matA->A[matA->row_size * (col_idx + 1) + (row_idx + 1)];
          }
          
          printf( "%lf\t",  matB.A[matA->row_size * col_idx + row_idx] );
          
       }
          printf("\n");
    }
      printf("\n");
    return matB;
}



int det(Matrix *matA)
{   
   
    if( matA->row_size != matA->col_size)
    {
        printf("матрица вырожденная!(\n"); 
        return 0;
    }
    else
    {
        if(  matA->row_size == 2)
        {
            int d = 0;
            int x = 0;
            int y = 0;
            if (matA->A[matA->row_size * 0 + 0]  != 0 && matA->A[matA->row_size * matA->col_size + matA->row_size] != 0 )
            {
                x = matA->A[matA->row_size * 0 + 0] * matA->A[matA->row_size * matA->col_size + matA->row_size]; 
            }
            if (matA->A[matA->row_size * 0 + matA->row_size]  != 0 && matA->A[matA->row_size * matA->col_size + 0] != 0 )
            {
                y = matA->A[matA->row_size * 0 + matA->row_size] * matA->A[matA->row_size * matA->col_size + 0]; 
            }
            return d = x - y;
        }
        else
        {
            int d = 0;
            for ( int row_idx = 0; row_idx < matA->row_size; row_idx++ )
            {
                printf("%d\n", row_idx);
                for ( int col_idx = 0; col_idx < matA->col_size; col_idx++ )
                {
                    Matrix matB = make_minor( matA, row_idx, col_idx);
                    printf("\n");
                    d += pow(- 1, col_idx ) * matA->A[matA->row_size * col_idx + row_idx] * det(&matB);
                }
            }
            return d;
        }
    }
}



Matrix inverse(Matrix *matA, int d)
{
    if( matA->row_size != matA->col_size)
    {
        printf("матрицa не квадратная, нахождение обратной матрицы не возможно!!(\n"); 
    }
    else
    {
        Matrix matB = init_matrix( matA);
        
        for( int row_idx = 0; row_idx < matA->row_size; row_idx++)
        {
            for( int col_idx = 0; col_idx < matA->col_size; col_idx++)
            {
                Matrix matC = make_minor(matA, col_idx, row_idx);
                // printf("minor\n");
                // print_minor(&m);
                // printf("\n");
                matB.A[matA->row_size * col_idx + row_idx] = pow(- 1, col_idx + row_idx) * (double) det(&matC)/(double) d;
                // printf("det minor = %d\n\n", det_minor(&m));
            }
        }
        // printf("\n");
        return matB;
    }
}

// Matrix ** dynamic_array_alloc(int row_idx, int col_max)
// {
//     int **A = (int **)malloc(row_max*sizeof(int *));
//     for(int row_idx = 0; row_idx < row_max; row_idx++) 
//     {
//         A[row_idx] = (int *)malloc(col_max*sizeof(int));
//     }
//     return A;
// }

// void dynamic_array_free(int **A, int row_max)
// {
//     for(int row_idx = 0; row_idx < row_max; row_idx++) {
//         free(A[row_idx]);
//     }
//     free(A);
// }


// Matrix summ(Matrix *a, Matrix *b, int row_max, int col_max )
// {   
//     int row_idx;
//     int col_idx;
//     Matrix c;
//     for ( row_idx = 0; row_idx < row_max; row_idx++ )
//     {
//         for ( col_idx = 0; col_idx < col_max; col_idx++ )
//         {
//             c.m[row_idx][col_idx] = a->m[col_idx][row_idx] + b->m[col_idx][row_idx]; 
//         }
//     printf( "\n" );
//     }
//     return c;
// }


// Matrix mult(Matrix *a, Matrix *b, int row_max, int col_max)
// {
//     int row_idx;
//     int col_idx;
//     Matrix c = init_matrix();
//     for(row_idx = 0; row_idx < row_max; row_idx++)
//     {
//         for(col_idx = 0; col_idx < col_max; col_idx++)
//         {
//             for( int k = 0; k < col_max; k++)
//             {
//               c.m[row_idx][col_idx] += a->m[row_idx][k] * b->m[k][col_idx];
//             }
//         }
//     }
//     return c;
// }



int main()
{
    Matrix A;
    Matrix B;
    Matrix C;
    int DET;
    printf("Введите количество строк матрицы A: \n");
    scanf("%d", &A.col_size); 
    printf("Введите количество столбцов матрицы A: \n");
    scanf("%d", &A.row_size); 
    printf("Введите количество строк матрицы B: \n");
    scanf("%d", &B.col_size); 
    printf("Введите количество столбцов матрицы B: \n");
    scanf("%d", &B.row_size); 
    PrintMatrix(&A);
    PrintMatrix(&B);
    C = summ(&A, &B);
    PrintMatrix(&C);
    C = mult(&A, &B);
    PrintMatrix(&C);
    DET = det(&A);
    printf("det a = %d\n", DET);
    C = inverse(&A, DET);
    PrintMatrix(&C);
    
}
