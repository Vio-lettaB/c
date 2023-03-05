#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int n;
int i;

int isPrime(int i)
{
    
	for (int k = 2; k < i; k++)
	{

		float j;
		float m;
		float r;
		float q;

		r = i/k;
		j = i;
		m = k;
		q = (j/m) - r;

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
        if (isPrime( i ) == 1 )
        {
            printf (" %d\n", i );
        }

   }
}
