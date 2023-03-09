#include<stdio.h>
#include<conio.h>
#include<math.h>
#define SIZE 150

double Gregory(int n) {
    double res = 0;
    for (int i = 0; i < n; i++) {
        res += pow(-1, i) / (2 * i + 1);
    }
    return 4 * res;
}

double calculate_pi(int n)
{
    printf("n = %d\n", n);
    double pi_old = 0;
    double pi_new = 4;
    int count = 0;
    printf("pow = %lf\n", pow(10, -n ));
    printf("pi_new - pi_old = %lf", fabs(pi_new - pi_old));
    for (int count = 0; fabs(pi_new - pi_old) > pow(10, -n ) ; count++)
    {
        pi_old = pi_new;
        pi_new = Gregory(count + 2);
        printf("new = %lf, old = %lf\n", pi_new, pi_old);
    }
    return pi_new;
}


int main() 
{
    int presicion = 2;
    printf(" pi = %lf ", calculate_pi(presicion));
   
   
}
