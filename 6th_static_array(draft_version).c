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

int main()
{
  setting_an_array();
  array_output(size); 
  
  int max = 0;
  int min = 0;
  int average =0;
  int rms = 0;
} 
