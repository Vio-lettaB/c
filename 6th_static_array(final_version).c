#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define Size 6



int a[Size];
int b[9];
int c[3];
int size = 6;


int fill_in_an_array( int *arr, int size)
{
    
    int i;
    
    for (i = 0; i < size; i++) 
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]); 
    }
    return size;
}

int print_array( int size, int *arr )
{   
    for (int i = 0; i < size; i++)
  {
    printf("%d, ", arr[i]); 
  }
}

int Max( int size, int *arr)
{
    int max = 0;
    for(int i = 0; i < size; ++i)
        {
            if(*(arr + i) > max)
            {
                max = *(arr + i);
            }
        }
    return max;
}


int Min( int size, int *arr )
{
    int min = *arr;
    for(int i = 0; i < size; ++i)
        {
            if(*(arr + i) < min)
            {
                min = *(a + i);
            }
        }
    return min;
}

float Mean( int size, int *arr)
{
    float mean = 0;
    for(int i = 0; i < size; ++i)
        {
        
            mean += arr[i];
            
        }
    mean /= size; 
    return mean;
}


float Rms( int size, float mean, int *arr)
{
    float rms = 0;
    for(int i = 0; i < size; ++i)
        {
        
            rms += pow(arr[i] - mean, 2);
            
        }
    rms = sqrt(rms / (size - 1)); 
    return rms;
}
int main()
{
    fill_in_an_array( a, 6 );
    print_array(size, a);
     
    printf(" max = %d", Max(size, a));
    printf(" min = %d", Min(size, a));
    printf(" mean = %f", Mean(size, a));
    printf(" rms = %f\n", Rms(size, Mean(size, a), a));
      
    fill_in_an_array( b, 10 );
    print_array(size, b); 
      
    printf(" max = %d", Max(size, b));
    printf(" min = %d", Min(size, b));
    printf(" mean = %f", Mean(size, b));
    printf(" rms = %f\n", Rms(size, Mean(size, b), b));
      
    fill_in_an_array( c, 4 );
    print_array(size, c);
      
    printf(" max = %d", Max(size, c));
    printf(" min = %d", Min(size, c));
    printf(" mean = %f", Mean(size, c));
    printf(" rms = %f\n", Rms(size, Mean(size, c), c));
} 
