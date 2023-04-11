#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>



int fill_in_an_array( int *arr, int size)
{
    int i = 0;
    
    for (i = 0; i < size; i++) 
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]); 
    }

}

void print_array(  int *arr, int size )
{   
    for (int i = 0; i < size; i++)
  {
    printf("%d, ", arr[i]); 
  }
 
}

int Max( int *arr, int size)
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


int Min( int *arr, int size)
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

float Mean( int *arr, int size )
{
    float mean = 0;
    for(int i = 0; i < size; ++i)
        {
        
            mean += *(arr + i);
            
        }
    mean /= size; 
    return mean;
}


float Rms( int *arr, int size, float mean, )
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
    int size = 0;
    
    printf("\nВведите размер массива : ");
    scanf("%d", &size);
    arr = (int*)malloc(size * sizeof(int));
   
    
    fill_in_an_array( arr, size );
    print_array(arr, size);
     
    printf(" max = %d", Max(arr, size));
    printf(" min = %d", Min(arr, size));
    printf(" mean = %f", Mean(arr, size));
    printf(" rms = %f", Rms(arr, size, Mean(arr, size)));
      
} 
