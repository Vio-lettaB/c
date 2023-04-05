#include <stdio.h>
// #define size (9)


int a[12];
int size = 0;


int setting_an_array()
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

int array_output( int size )
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



int main()
{
  setting_an_array();
  array_output(size); 
  
 
  int mean = 0;
  int rms = 0;
  printf(" max = %d", Max(size));
  printf(" min = %d", Min(size));
} 
