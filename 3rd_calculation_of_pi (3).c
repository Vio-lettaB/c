#include<stdio.h>
#include<conio.h>
#include<math.h>


double Gregory(int r) 
{
    double res = 0;
    for (int i = 0; i < r; i++) 
    {
        res += pow(-1, i) / (2 * i + 1);
    }
    return 4 * res;
}

long double calculate_pi(int n)
{
    
    printf("n = %d\n", n);
    long double pi_old = 0;
    long double pi_new = 4;
    int count = 0;
    printf("pow = %lf\n", pow(10, -n ));
    printf("pi_new - pi_old = %Lf\n", fabs(pi_new - pi_old));
    for (int count = 0; fabs(pi_new - pi_old) > pow(10, -n ) ; count++)
    {
        pi_old = pi_new;
        pi_new = Gregory(count + 2);
        printf("old = %0.10Lf, new = %0.10Lf\n", pi_old, pi_new);
    }
    return pi_old;
}


int main() 
{
    int presicion = 4;
    printf(" presicion = %ls\n ", &presicion);
    printf(" pi = %0.50Lf ",calculate_pi(presicion));
   
   
}
