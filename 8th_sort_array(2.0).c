#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdbool.h>

_Bool Sort1(int *arr, int len)
{
    for ( int i = 0; i < (len - 1); i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
        
    }
    return true;
}

_Bool sort2(int *arr, int len)
{
    for ( int i = (len - 1 ); i > 0; i--)
    {
        if (arr[i] > arr[i - 1])
        {
            return false;
        }
        
    }
    return true;
}

int swap (int *arr, int i)
{
    int c = 0;
    c = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = c;
   
}

int sort_array(_Bool(*Sort)(int *, int), int *arr, int len )
{
    int i = 0;
    while ( Sort(arr, len) == false)
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


int print_array(int *arr, int len)
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
    
    print_array( arr, len);
    sort_array(Sort1(arr,len), arr, len );
    printf("отсортированный массив: ");
    print_array(arr, len);
}
