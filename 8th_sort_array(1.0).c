#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

int Is_sorted(int *arr, int len)
{
    for ( int i = 0; i < (len - 1); i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
        
    }
    return 1;
}

int swap (int *arr, int i)
{
    int c = 0;
    c = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = c;
   
}

int sort_array (int *arr, int len)
{
    int i = 0;
    while (Is_sorted(arr, len) == 0)
    {
        for ( int i = 0; i < (len - 1); i++)
    	{
    	    if (arr[i] > arr[i + 1])
    	    {
    	        swap (arr, i);
    	    }
    	}
    i++;
    }
   
}


int print_array (int *arr, int len)
{
  for (int i = 0; i < len; i++)
    {
      printf ("%d, ", arr[i]);
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
    
    print_array (arr, len);
    sort_array (arr, len);
    printf("отсортированный массив: ");
    print_array (arr, len);
}


