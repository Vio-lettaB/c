#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct 
{
    int m[3][3];
}Matrix ;

typedef struct 
{
    int m[2][2];
}Minor ;



Matrix init_matrix()
{
    Matrix c;
    int col_idx = 0 ;
    int row_idx = 0;
    for ( row_idx = 0; row_idx < 3; row_idx++ )
    {
        for ( col_idx = 0; col_idx < 3; col_idx++ )
        {
            c.m[row_idx][col_idx] = 0;
        }
    }
    return c;
}

void make_diagonal_matrix( Matrix  *c )
{
    int i = 0;
    int col_idx= 0 ;
    int row_idx = 0;
    for ( row_idx = 0; row_idx < 3; row_idx++ )
    {
        for ( col_idx = 0; col_idx < 3; col_idx++ )
        {
            c->m[row_idx][col_idx] = (int)(col_idx == row_idx) * 5;
        }
    }
}


Matrix summ(Matrix *a, Matrix *b )
{   
    int col_idx;
    int row_idx;
    Matrix c;
    for ( row_idx = 0; row_idx < 3; row_idx++ )
    {
        for ( col_idx = 0; col_idx < 3; col_idx++ )
        {
            c.m[col_idx][row_idx] = a->m[col_idx][row_idx] + b->m[col_idx][row_idx]; 
        }
    printf( "\n" );
    }
    return c;
}


Matrix mult(Matrix *a, Matrix *b)
{
    int row_idx;
    int col_idx;
    Matrix c = init_matrix();
    for(row_idx = 0; row_idx < 3; row_idx++)
        for(col_idx = 0; col_idx < 3; col_idx++)
         {
            for( int k = 0; k < 3; k++)
               c.m[row_idx][col_idx] += a->m[row_idx][k] * b->m[k][col_idx];
        }
    return c;
}


Minor make_minor(Matrix *a, int i, int j)
{
   Minor b;
   for(int row_idx = 0; row_idx < 2; row_idx++ )
   {
       for(int col_idx = 0; col_idx < 2;  col_idx++ )
       {
          if(row_idx < i && col_idx < j) 
          {
            b.m[row_idx][col_idx] = a->m[row_idx][col_idx];
          }
          if (row_idx >= i )
          {
            b.m[row_idx][col_idx] = a->m[row_idx][col_idx + 1];
          }
          if (col_idx >= j )
          {
            b.m[row_idx][col_idx] = a->m[row_idx + 1][col_idx];
          }
          if(row_idx >= i && col_idx >= j) 
          {
            b.m[row_idx][col_idx] = a->m[row_idx + 1][col_idx + 1];
          }
          printf( "%d\t", b->m[row_idx][col_idx] );
       }
    printf("\n");
   }

   return b;
}



int det_minor(Minor *b) 
{
    int det = 0;
    det = b->m[1][1] * b->m[2][2] - b->m[1][2] * b->m[2][1];
    return det;
}


int det(Matrix *a)
{
    int det = 0;
    int row_idx;
    int col_idx;

    for(row_idx = 0; row_idx < 3; row_idx++)
    {
        for(col_idx = 0; col_idx < 3; col_idx++)
        {
            make_minor(&a, row_idx, col_idx)
            det += pow(-1, row_idx + col_idx) * a->m[col_idx][row_idx] * det_minor();
        }
    }
    printf("det a = %d", det);
}

// int det(Matrix *a)
// {
//     int det = 0;
//     det = a->m[1][1] * a->m[2][2] * a->m[3][3] + a->m[1][2] * a->m[2][3] * a->m[3][1] + a->m[1][3] * a->m[2][1] * a->m[3][2] - a->m[1][3] * a->m[2][2] * a->m[3][1] - a->m[1][2] * a->m[2][1] * a->m[3][3] - a->m[1][1] * a->m[2][3] * a->m[3][2];
//     printf("det a = %d", det);
//     return det; 
// }





int print_matrix(Matrix *c)
{ 
    int row_idx = 0;
    int col_idx = 0 ;
    for ( row_idx = 0; row_idx < 3; row_idx++ )
    {
        for ( col_idx = 0; col_idx < 3; col_idx++ )
        {
        // printf( "[%d][%d]=%d\t", y, x, c.m[y][x] );
        printf( "%d\t", c->m[row_idx][col_idx] );
        }
    printf( "\n" );
    }
}


int main()
{ 
    Matrix a;
    Matrix b;
    Matrix c; 
    int d;

    make_diagonal_matrix(&a);
    print_matrix(&a);
    printf("\n");
    make_diagonal_matrix(&b);
    print_matrix(&b);
     printf("\n");
    c = summ(&a,&b);
    printf("\nsumm = \n");
    print_matrix(&c);
    printf("\n");
    c = mult(&a,&b);
    printf("\n");
    printf("\nmult = \n");
    print_matrix(&c);
    d = det(&a);

}    



