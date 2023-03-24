#include<stdio.h>
#include<math.h>

double Func(double x)
{
    double function_value;
    function_value = sin(x);
    printf( " function_value = %lf ", function_value);
    return function_value;
}

double dFunc(double y)
{
    double der;
    double dy;
    dy =  pow( 10 , - 6);
    printf(" increment = %lf\n", y + dy);
    der = (Func(y + dy) - Func(y)) / dy ;
    printf(" derivative = %lf\n", der);
    return der;
}



int main()
{
    
    double accuracy = 1.e-6;
    double Xn = 0 ;
    // printf("Введите начальное приближение X0: " );
    // scanf("%lf", &X0);
    // printf("Введите требуемую точность:" );
    // scanf("%lf", &accuracy);
    printf("%lf\n", accuracy);
    double i;
    for (  double X0 = 200; fabs(X0 - i) > accuracy;  X0 = Xn )
    {
        i = X0;
        Xn = i - ( Func(i) / dFunc(i) );
        printf("%lf\n ", Xn );
        printf("Xn - i %lf\n ", fabs(X0 - i));
       
    }
    printf("корень уравнения, вычисленный с точностью %lf = %lf ", accuracy, Xn);
    
}  
