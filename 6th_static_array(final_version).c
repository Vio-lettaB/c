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

int print_array( int *arr, int size )
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
            if(*(arr + i) > max)
            {
                max = *(arr + i);
            }
        }
    return max;
}


int Min( int *arr, int size )
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

float Mean( int *arr, int size)
{
    float mean = 0;
    for(int i = 0; i < size; ++i)
        {
        
            mean += arr[i];
            
        }
    mean /= size; 
    return mean;
}


float Rms(  int *arr, int size, float mean)
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
    
    printf("Введите размер массива a : ");
    scanf("%d", &size); 
    
    fill_in_an_array( a, size );
    print_array(a, size );
     
    printf(" max = %d", Max(a, size));
    printf(" min = %d", Min(a, size));
    printf(" mean = %f", Mean(a, size));
    printf(" rms = %f\n", Rms(a, size, Mean(a, size)));
      
      
    printf("Введите размер массива b : ");
    scanf("%d", &size);   
    
    fill_in_an_array( b, size );
    print_array(b, size); 
      
    printf(" max = %d", Max(b, size));
    printf(" min = %d", Min(b, size));
    printf(" mean = %f", Mean(b, size));
    printf(" rms = %f\n", Rms(b, size, Mean(b, size)));
    
        
    printf("Введите размер массива c : ");
    scanf("%d", &size);   
    
      
    fill_in_an_array( c, size );
    print_array(c, size);
      
    printf(" max = %d", Max(c, size));
    printf(" min = %d", Min(c, size));
    printf(" mean = %f", Mean(c, size));
    printf(" rms = %f\n", Rms(c, size, Mean(c, size)));
}    
