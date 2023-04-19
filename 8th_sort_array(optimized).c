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
    printf("\n");
}


void swap(int *a, int *b)
{
    int c = 0;
    c = *a;
    *a = *b;
    *b = c;
   
}

int comparison1(int *a, int *b)
{
    if (*a > *b)
        {
            return 0;
        }
}

int comparison2(int *a, int *b)
{
    if (*a < *b)
        {
            return 0;
        }
}
 int comparison3(int *a, int *b)
{
    if ( abs(*a) > abs(*b))
        {
            return 0;
        }
}


// int sort(int(*comparison)(int *, int * ), int *arr, int len)
// {
//     int iter = 0;
//     while (comparison(&arr[iter], &arr[iter + 1]) == 0)
//     {
//         for (iter = 0; iter < (len - 1); iter++)
//         {
//             // printf("iter = %d\n", iter);
//             for (int j = 0; j < (len - 1); j++)
//           {
//             	if (comparison(&arr[j], &arr[j + 1]) == 0)
//                 {
//                      swap(&arr[j], &arr[j + 1]);
//                 }
//             }
//         }
//     }
//     iter ++;
// }

int sort(int(*comparison)(int *, int * ), int *arr, int len)
{
    int last_swap_j = len;
               
    for (int iter = 0; iter < (len - 1); iter ++)
    {
        
        // if (comparison(&arr[iter], &arr[iter + 1]) == 0)
        // {
            // printf("iter = %d\n", iter);
            printf(" last_swap_j= %d\n", last_swap_j);
            for (int j = 0; j < (len - 1 - iter); j++)
           {
                //printf("j = %d\n", j);
                
            	if (comparison(&arr[j], &arr[j + 1]) == 0)
                {
                     swap(&arr[j], &arr[j + 1]);
                    //  last_swap_j = j;
                }
                else 
                {
                    continue;
                }
                last_swap_j = j;
             
            }
             print_array(arr, len);
                 printf("\n");
        // }
        
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
    
    printf("\nисходный массив : ");
    print_array(arr, len);
    sort(comparison1, arr, len);
    printf("\nотсортированный массив 1: ");
    print_array(arr, len);
    sort(comparison2, arr, len);
    printf("\nотсортированный массив 2: ");
    print_array(arr, len);
    sort(comparison3, arr, len);
    printf("\nотсортированный массив 3: ");
    print_array(arr, len);
    
}
