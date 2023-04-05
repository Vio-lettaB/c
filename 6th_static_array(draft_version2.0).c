#include <stdio.h>
#include <math.h>
#define Size 6



int a[Size];
int b[9];
int c[3];
int size = 0;


int fill_in_an_array( int *arr)
{
    printf("Введите размер массива : ");
    scanf("%d", &size);
    
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
  
  fill_in_an_array( b );
  print_array(size, b); 
  
  printf(" max = %d", Max(size, b));
  printf(" min = %d", Min(size, b));
  printf(" mean = %f", Mean(size, b));
  printf(" rms = %f", Rms(size, Mean(size, b), b));
} 
