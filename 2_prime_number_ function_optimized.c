#include <stdio.h>
#include <math.h>

int n;
int i;

 
int isPrime(int i)
{
	for (int k = 2; k <= sqrt(i) ; k++)
	{
		if (i % k == 0)
			return 0;
	} 
	return 1;
}

int main()
{
    printf(" введите число N\n" );
    scanf("%d", &n);
    while (n < 2)
    {
       printf(" N не простое ");
    }
   for(i = 2; i <= n; i++)
   {
        if (isPrime( i ) == 1 )
        {
            printf (" %d", i );
        }
   }
}
