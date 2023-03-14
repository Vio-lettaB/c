#include<stdio.h>
#include<math.h>

double Func(double x)
{
    double function_value;
    function_value = pow(x + 25, 2) + x;
    printf( " function_value = %lf ", function_value);
    return function_value;
}

double dFunc(double y)
{
    double derivative;
    double  increment;
    increment = y + pow( 10 , - 13);
    derivative = (Func(increment) - Func(y)) / pow( 10 , - 13);
    printf(" derivative = %lf\n", derivative);
    return derivative;
}
int main()
{
    double X0;
    double accuracy;
    double Xn;
    printf("Введите начальное приближение X0: " );
    scanf("%lf", &X0);
    printf("Введите требуемую точность:" );
    scanf("%lf", &accuracy);
    printf("%lf\n", accuracy);
    for ( double i = X0; fabs(Xn - i) > accuracy ; i = Xn)
    {
        Xn = i - ( Func(i) / dFunc(i) );
        
    }
    printf("корень уравнения, вычисленный с точностью %lf = %lf ", accuracy, Xn);
    
    
}

