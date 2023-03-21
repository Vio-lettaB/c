#include<stdio.h>
#include<math.h>

double Func(double x)
{
    double function_value;
    function_value = pow(x, 2) - 2;
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
    double X0 = 2;
    double accuracy = 1.e-6;
    double Xn;
    // printf("Введите начальное приближение X0: " );
    // scanf("%lf", &X0);
    // printf("Введите требуемую точность:" );
    // scanf("%lf", &accuracy);
    printf("%lf\n", accuracy);
    double i = X0;
    while ( fabs(Xn - i) > accuracy )
    {
        Xn = i - ( Func(i) / dFunc(i) );
        printf("%lf, %lf, ", Xn, fabs(Xn - i));
        i = Xn;
    }
    printf("корень уравнения, вычисленный с точностью %lf = %lf ", accuracy, Xn);
    
}  
