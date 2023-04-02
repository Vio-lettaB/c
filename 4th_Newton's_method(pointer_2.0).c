#include<stdio.h>
#include<math.h>
 

double Func1(double x)
{
    double function_value;
    return function_value = pow(x , 2) - 2;
}


double Func2(double x)
{
    double function_value;
    return function_value = sin(x);
}


double Func3(double x)
{
    double function_value;
    return function_value = pow(x , 2) - sin(x);
}

double derivate(double(*fuction)(double), double X0, double dX) 
{
    return (fuction(X0 + dX) - fuction(X0 - dX)) / (2 * dX);
}


double approximate_root_of_equation( double X0, double dX, double accuracy, double(*fuction)(double) )
{
    double i = 0;
    double Xn = X0;
    while ( fabs(Xn - i) > accuracy )
    {
        i = X0;
        Xn = i - ( fuction(i) / derivate(fuction, X0, dX) );
        X0 = Xn;
       
    }
 return X0;
} 

int main()
{
    double X0 = 2;
    double dX = 1.e-6;
    double accuracy = 1.e-6;
    double Xn = 0;
    
    printf("приближенный корень уравнения 1:\n");
    printf("%lf\n", approximate_root_of_equation(X0, dX, accuracy, Func1));
    printf("приближенный корень уравнения 2:\n");
    printf("%lf\n", approximate_root_of_equation(X0, dX, accuracy, Func2));
    printf("приближенный корень уравнения 3:\n");
    printf("%lf\n", approximate_root_of_equation(X0, dX, accuracy, Func3));
}
