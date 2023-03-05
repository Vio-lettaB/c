#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n;
int i;

int isPrimeCast(int i)
{
    
	for (int k = 2; k < i; k++)
	{
	    float q;
	    
		q = ((float) i / (float) k  - i/k);

		if (q > 0.0)
		{
			return 1;
		}
    return 0;
	}
}

int main()
{
    printf(" введите число N\n" );
    scanf(" %d", &n);
    while (n < 2)
    {
       printf(" N не простое ");
    }
   for(i = 2; i <= n; i++)
   {
        if (isPrimeCast( i ) == 1 )
        {
            printf (" %d\n", i );
        }

   }
}
