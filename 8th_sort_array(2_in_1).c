#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

int sort1(int *arr, int len)
{
    for (int i = 0; i < (len - 1); i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return 0;
        }
        
    }
    return 1;
}

int sort2(int *arr, int len)
{
    for (int i = 0; i < (len - 1); i++)
    {
        if (arr[i] < arr[i + 1])
        {
            return 0;
        }
        
    }
    return 1;
}

int sort3(int *arr, int len)
{
    for ( int i = 0; i < (len - 1); i++)
    {
        if (abs(arr[i]) > abs(arr[i + 1]))
        {
            return 0;
        }
        
    }
    return 1;
}


int swap(int *arr, int i)
{
    int c = 0;
    c = arr[i];
    arr[i] = arr[i + 1];
    arr[i + 1] = c;
   
}


// int sort_array1(int *arr, int len)
// {
//     int i = 0;
//     while (sort1(arr, len) == 0)
//     {
//         for ( int i = 0; i < (len - 1); i++)
//     	{
//     	    if (arr[i] > arr[i + 1])
//     	    {
//     	        swap(arr, i);
//     	    }
//     	}
//     i++;
//     }
   
// }

// int sort_array2(int *arr, int len)
// {
//     int i = 0;
//     while (sort2(arr, len) == 0)
//     {
//         for (int i = 0; i < (len - 1); i++)
//     	{
//     	    if (arr[i] < arr[i + 1])
//     	    {
//     	        swap(arr, i);
//     	    }
//     	}
//     i++;
//     }
// }

// int sort_array3(int *arr, int len)
// {
//     int i = 0;
//     while (sort1(arr, len) == 0)
//     {
//         for ( int i = 0; i < (len - 1); i++)
//     	{
//     	    if (abs(arr[i]) > abs(arr[i + 1]))
//     	    {
//     	        swap(arr, i);
//     	    }
//     	}
//     i++;
//     }
// }

int swap_if1(int *arr, int len, int i)
{
    if (arr[i] > arr[i + 1])
    {
        swap(arr, i);
    }
}

int swap_if2(int *arr, int len, int i)
{
    if (arr[i] < arr[i + 1])
    {
        swap(arr, i);
    }
}

int swap_if3(int *arr, int len, int i)
{
    if (abs(arr[i]) > abs(arr[i + 1]))
    {
        swap(arr, i);
    }
}

int Bigsort(int(*sort)(int *, int ), int(*swapif)(int *, int, int), int *arr, int len)
{
    int i = 0;
    while (sort(arr, len) == 0)
    {
        for ( int i = 0; i < (len - 1); i++)
    	{
    	    swapif(arr, len, i);
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
    
    print_array(arr, len);
    Bigsort(sort1, swap_if1, arr, len);
    printf("\nотсортированный массив 1: ");
    print_array(arr, len);
    Bigsort(sort2, swap_if2, arr, len);
    printf("\nотсортированный массив 2: ");
    print_array(arr, len);
    Bigsort(sort3, swap_if3, arr, len);
    printf("\nотсортированный массив 3: ");
    
    
    // print_array(arr, len);
    // sort_array1(arr, len);
    // printf("\nотсортированный массив 1: ");
    // print_array(arr, len);
    // sort_array2(arr, len);
    // printf("\nотсортированный массив 2: ");
    // print_array(arr, len);
    // sort_array3(arr, len);
    // printf("\nотсортированный массив 3: ");
    // print_array(arr, len);
    
}
