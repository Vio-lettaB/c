#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

int size = 0;

int fill_in_an_array( int *arr, int size)
{
    int i = 0;
    
    for (i = 0; i < size; i++) 
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]); 
    }

}

void print_array( int size, int *arr )
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
            if(arr[i] > max)
            {
                max = arr[i];
            }
        }
    return max;
}


int Min( int size, int *arr )
{
    int min = arr[0];
    for(int i = 0; i < size; ++i)
        {
            if(arr[i] < min)
            {
                min = arr[i];
            }
        }
    return min;
}

float Mean( int size, int *arr)
{
    float mean = 0;
    for(int i = 0; i < size; ++i)
        {
        
            mean += *(arr + i);
            
        }
    mean /= size; 
    return mean;
}


float Rms( int size, float mean, int *arr)
{
    float rms = 0;
    for(int i = 0; i < size; ++i)
        {
        
            rms += pow(*(arr + i) - mean, 2);
            
        }
    rms = sqrt(rms / (size - 1)); 
    free(arr);
    return rms;
}
int main()
{
    int *arr;
    
    printf("\nВведите размер массива : ");
    scanf("%d", &size);
    arr = (int*)malloc(size * sizeof(int));
   
    
    fill_in_an_array( arr, size );
    print_array(size, arr);
     
    printf(" max = %d", Max(size, arr));
    printf(" min = %d", Min(size, arr));
    printf(" mean = %f", Mean(size, arr));
    printf(" rms = %f", Rms(size, Mean(size, arr), arr));
      
    // fill_in_an_array( b );
    // print_array(size, b); 
      
      
    // printf(" max = %d", Max(size, b));
    // printf(" min = %d", Min(size, b));
    // printf(" mean = %f", Mean(size, b));
    // printf(" rms = %f", Rms(size, Mean(size, b), b));
      
    // fill_in_an_array( c );
    // print_array(size, c);
      
    // printf(" max = %d", Max(size, c));
    // printf(" min = %d", Min(size, c));
    // printf(" mean = %f", Mean(size, c));
    // printf(" rms = %f", Rms(size, Mean(size, c), c));
} 

