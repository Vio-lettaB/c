#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

int print_array(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
      printf ("%d, ", arr[i]);
    }
}


void swap(int *a, int *b)
{
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
   
}

int comparison1(int *arr, int i)
{
    if (arr[i] > arr[i + 1])
        {
            return 0;
        }
}

int comparison2(int *arr, int i)
{
    if (arr[i] < arr[i + 1])
        {
            return 0;
        }
}
 int comparison3(int *arr, int i)
{
    if ( abs(arr[i]) > abs(arr[i + 1]))
        {
            return 0;
        }
}


int sort(int(*comparison)(int *, int ), int *arr, int len)
{

    for (int i = 0; i < (len - 1); i++)
    {
        while (comparison(arr, i) == 0)
        {
            for (int i = 0; i < (len - 1); i++)
            {
            	if (comparison(arr, i) == 0)
                {
                    swap(&arr[i], &arr[i + 1]);
                }
            	
            }
                
        }
    }
}



int main()
{
    int *arr;
    int len = 0;
    
    printf ("\nВведите размер массива : ");
    scanf ("%d", &len);
    arr = (int *) malloc (len * sizeof (int));
        
    int i;
        
    for (i = 0; i < len; i++)
    {
        printf ("arr[%d] = ", i);
        scanf ("%d", &arr[i]);
    }
    
    print_array(arr, len);
    sort(comparison1, arr, len);
    printf("\nотсортированный массив 1: ");
    print_array(arr, len);
    sort(comparison2, arr, len);
    printf("\nотсортированный массив 2: ");
    print_array(arr, len);
    sort(comparison3, arr, len);
    printf("\nотсортированный массив 3: ");
    
    
    
}
