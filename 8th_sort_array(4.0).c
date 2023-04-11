#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>


int compare1(int *arr, int len, int i)
{
    for ( int i = 0; i < (len - 1); i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
        
    }
    
    return i++;
}

int compare2(int *arr, int len, int i)
{
    for ( int i = (len - 1 ); i > 0; i--)
    {
        if (arr[i] > arr[i - 1])
        {
            return 0;
        }
     }   
    return i--;
}

int compare3(int *arr, int len, int i)
{
    for ( int i = 0; i < (len - 1); i++)
    {
        if (abs(arr[i]) > abs(arr[i + 1]))
        {
            return 0;
        }
        
    }
    
    return i++;
}


int replace1(int *arr, int len)
{
    for ( int i = 0; i < (len - 1); i++)
    {
    	if (arr[i] > arr[i + 1])
    	{
    	    int c = 0;
            c = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = c;
    	 }
    }
}

int replace2(int *arr, int len)
{
    for ( int i = (len - 1 ); i > 0; i--)
    {
        if (arr[i] > arr[i - 1])
        {
            int c = 0;
            c = arr[i];
            arr[i] = arr[i - 1];
            arr[i - 1] = c;
    	  }
    }
}

int replace3(int *arr, int len)
{
    for ( int i = 0; i < (len - 1); i++)
    {
    	if (abs(arr[i]) > abs(arr[i + 1]))
    	{
    	    int c = 0;
            c = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = c;
    	 }
    }
}


int sort(int(*compare)(int *arr, int len, int i), int(*replace)(int *arr, int len), int *arr, int len)
{
    int i = 0;
    for (i = 0; compare(arr, len, i) == 0;)
    {
        replace(arr, len);
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
    
    print_array(arr, len);
    sort(compare1(arr, len, 0), replace1(arr, len), arr, len);
    printf("отсортированный массив 1: ");
    print_array(arr, len);
    sort(compare2(arr, len, 0), replace2(arr, len), arr, len);
    printf("отсортированный массив 2: ");
    print_array(arr, len);
    print_array(arr, len);
    sort(compare3(arr, len, 0), replace3(arr, len), arr, len);
    printf("отсортированный массив 3: ");
    print_array(arr, len);
}

