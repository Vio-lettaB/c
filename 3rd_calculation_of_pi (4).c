#include<stdio.h>
#include<conio.h>
#include<math.h>




long double calculate_pi(int n, int *COUNT )
{
    
    printf("n = %d\n", n);
    long double pi_old = 4;
    long double pi_new = 1;
    int count = 0;
    printf("pow = %lf\n", pow(10, -n ));
    printf("pi_new - pi_old = %f\n", fabs(pi_new - pi_old));
    double res = 0;
    for (int count = 0; fabs(pi_new - pi_old) > pow(10, -n ) ; count++)
    {
        pi_old = pi_new;
       
        res += pow(-1, count ) / (2 * count + 1);
        
        pi_new = 4 * res;
        printf("old = %0.10Lf, new = %0.10Lf\n", pi_old, pi_new);
        COUNT[0] = count;
    }
    return pi_old;
}


int main() 
{
    int cnt = 0;
    int presicion = 2;
    printf("Введите точность от 0 до 4 знаков после запятой:");
    // scanf("%d", &presicion);
    /*printf(" presicion = %ls\n ", &presicion);*/
    printf(" pi = %0.*Lf ", presicion, calculate_pi(presicion, &cnt));
    printf(" count = %d ", cnt);
   
}
