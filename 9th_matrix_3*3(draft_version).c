#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct 
{
    float m[3][3];
}Matrix ;

int summ(Matrix *a, Matrix *b )
{
    Matrix c;
    
}

int mult(Matrix *a, Matrix *b)
{
    Matrix c;
}

int det(Matrix *a)
{
    int det = 0;
    
}

int inverse(Matrix *a)
{
    Matrix a_inv;
    
}

int print_matrix(Matrix * c)
{ 
    int y = c.m[][];
    int x = c.m[][];
    for ( y = 0; y < 3; y++ )
    {
        for ( x = 0; x < 3; x++ )
        {
        printf( "[%d][%d]=%d\t", y, x, c.m[y][x] );
        }
    printf( "\n" );
    }
}


int main()
{
    Matrix a;
    Matrix b;
    print_matrix(a);
    
    
    
    
    int i = 0;
    int Height = 3;
    int Width = 3; 
    int a[Height][Width];
    int x, y;
    for ( y = 0; y < Height; y++ )
    {
        for ( x = 0; x < Width; x++ )
        {
            printf("a[%d][%d] = ", y, x );
            scanf("%d", &i );
            a[y][x] = i;
        }
    }
    
}
