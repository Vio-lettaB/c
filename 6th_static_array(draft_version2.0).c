#include <stdio.h>
#include <math.h>
#define  Size 9 ;


int a[12];
int size = 0;


int fill_in_an_array()
{
    printf("Введите размер массива : ");
    scanf("%d", &size);
    int i;
    for (i = 0; i < size; i++) 
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]); 
    }
    return size;
}

int print_array( int size )
{   
    for (int i = 0; i < size; i++)
  {
    printf("%d, ", a[i]); 
  }
}

int Max( int size)
{
    int max = 0;
    for(int i = 0; i < size; ++i)
        {
            if(a[i] > max)
            {
                max = a[i];
            }
        }
    return max;
}


int Min( int size )
{
    int min = a[0];
    for(int i = 0; i < size; ++i)
        {
            if(a[i] < min)
            {
                min = a[i];
            }
        }
    return min;
}

float Mean()
{
    float mean = 0;
    for(int i = 0; i < size; ++i)
        {
        
            mean += a[i];
            
        }
    mean /= size; 
    return mean;
}


float Rms( int size, float mean)
{
    float rms = 0;
    for(int i = 0; i < size; ++i)
        {
        
            rms += pow(a[i] - mean, 2);
            
        }
    rms = sqrt(rms / (size - 1)); 
    return rms;
}
int main()
{
  fill_in_an_array();
  print_array(size); 
  
  printf(" max = %d", Max(size));
  printf(" min = %d", Min(size));
  printf(" mean = %f", Mean(size));
  printf(" rms = %f", Rms(size, Mean(size)));
} 
