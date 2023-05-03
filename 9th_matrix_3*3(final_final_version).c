#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct 
{
    double m[3][3];
}Matrix ;

typedef struct 
{
    double m[2][2];
}Minor ;






Matrix init_matrix()
{
    Matrix c;
    int col_idx = 0;
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


Minor init_minor()
{
    Minor c;
    int col_idx = 0 ;
    int row_idx = 0;
    for ( row_idx = 0; row_idx < 2; row_idx++ )
    {
        for ( col_idx = 0; col_idx < 2; col_idx++ )
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
            c->m[row_idx][col_idx] = (int)(col_idx != row_idx) * 2;
        }
    }
}




Minor make_minor(Matrix *a, int i, int j)
{
    Minor b = init_minor();
    // printf("\n");
    // print_minor(&b);
    // printf("\n");
    // printf("i-Й минор\n");
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
            b.m[row_idx][col_idx] = a->m[row_idx + 1][col_idx];
          }
          if (col_idx >= j )
          {
            b.m[row_idx][col_idx] = a->m[row_idx][col_idx + 1];
          }
          if(row_idx >= i && col_idx >= j) 
          {
            b.m[row_idx][col_idx] = a->m[row_idx + 1][col_idx + 1];
          }
          
        //   printf( "%lf\t", b.m[row_idx][col_idx] );
          
       }
        //  printf("\n");
    }
    //  printf("\n");
    return b;
}



int det_minor(Minor *b) 
{
    int det = 0;
    int x = 0;
    int y = 0;
    if (b->m[0][0]  != 0 && b->m[1][1] != 0 )
    {
        x = b->m[0][0] * b->m[1][1]; 
    }
    if (b->m[0][1]  != 0 && b->m[1][0] != 0 )
    {
        y = b->m[0][1] * b->m[1][0]; 
    }
    det = x - y;
    // printf("%d\n", x);
    // printf("%d\n\n", y);
    // printf("\n det i-го минора = %f\n", &det);
    return det;
    
}


int det(Matrix *a)
{   
    Minor b;
    int det = 0;
    int row_idx;
    int col_idx;

    for(row_idx = 0; row_idx < 1; row_idx++)
    {
        for(col_idx = 0; col_idx < 3; col_idx++)
        {
            b = make_minor(a, row_idx, col_idx);
            printf("\n");
            det += pow(- 1, col_idx ) * a->m[col_idx][row_idx] * det_minor(&b);
        }
    }
    printf("det a = %d\n", det);
    return det;
}


Matrix inverse(Matrix *a, int det)
{
    Matrix c = init_matrix();
    
    int row_idx;
    int col_idx;
    for(row_idx = 0; row_idx < 3; row_idx++)
    {
        for(col_idx = 0; col_idx < 3; col_idx++)
        {
            Minor m = init_minor();
            m = make_minor(a, col_idx, row_idx);
            // printf("minor\n");
            // print_minor(&m);
            // printf("\n");
            c.m[col_idx][row_idx] = pow(- 1, col_idx + row_idx) * (double) det_minor(&m)/(double) det;
            // printf("det minor = %d\n\n", det_minor(&m));
        }
    }
    // printf("\n");
    return c;
}


// int det(Matrix *a)
// {
//     int det = 0;
//     det = a->m[0][0] * a->m[1][1] * a->m[2][2] + a->m[0][1] * a->m[1][2] * a->m[2][0] + a->m[0][2] * a->m[1][0] * a->m[2][1] - a->m[0][2] * a->m[1][1] * a->m[2][0] - a->m[0][1] * a->m[1][0] * a->m[2][2] - a->m[0][0] * a->m[1][2] * a->m[2][1];
//     printf("det a = %d", det);
//     return det; 
// }





Matrix summ(Matrix *a, Matrix *b )
{   
    int col_idx;
    int row_idx;
    Matrix c;
    for ( row_idx = 0; row_idx < 3; row_idx++ )
    {
        for ( col_idx = 0; col_idx < 3; col_idx++ )
        {
            c.m[row_idx][col_idx] = a->m[col_idx][row_idx] + b->m[col_idx][row_idx]; 
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
    {
        for(col_idx = 0; col_idx < 3; col_idx++)
        {
            for( int k = 0; k < 3; k++)
            {
               c.m[row_idx][col_idx] += a->m[row_idx][k] * b->m[k][col_idx];
            }
        }
    }
    return c;
}




int print_matrix(Matrix *c)
{ 
    int row_idx = 0;
    int col_idx = 0 ;
    for ( row_idx = 0; row_idx < 3; row_idx++ )
    {
        for ( col_idx = 0; col_idx < 3; col_idx++ )
        {
        // printf( "[%d][%d]=%d\t", y, x, c.m[y][x] );
        printf( "%lf\t", c->m[row_idx][col_idx] );
        }
    printf( "\n" );
    }
}

int print_minor(Matrix *c)
{ 
    int row_idx = 0;
    int col_idx = 0 ;
    for ( row_idx = 0; row_idx < 2; row_idx++ )
    {
        for ( col_idx = 0; col_idx < 2; col_idx++ )
        {
        // printf( "[%d][%d]=%d\t", y, x, c.m[y][x] );
        printf( "%lf\t", c->m[row_idx][col_idx] );
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
    printf("\n");
    c = inverse(&a, d);
    printf("\ninverse = \n");
    print_matrix(&c);
    

}    
