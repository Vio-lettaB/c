#include<stdio.h>
#include<math.h>

double Func(double x)
{
    double function_value;
    function_value = pow(x , 2) - 2;
    // printf( " function_value = %lf ", function_value);
    return function_value;
}

//В чём основная идея использования указателя на функции?
//Допустим, у нас не одна математическая функция Func,
//а кроме неё есть ещё func1, func2 и func3
double func1(double x) {
    return sin(x)
}

double func2(double x) {
    return fabs(x) < 0.1 ? 1 : sin(1 / x);
}

double func3(double x) {
    return sin(pow(x, 2))
}

//в текущем варианте реализации функции дифференцирования
//для вычисления производной func1, func2 и func3 
//потребуется созать ещё dfunc1, dfunc2 и dfunc3
//что довольно странно, потому что во всех случаях
//считать численно производную мы будем абсолютно одинаково
double dFunc(double y)
{
    double der;
    double dy;
    dy =  pow( 10 , - 6);
    // printf(" increment = %lf\n", y + dy);
    der = (Func(y + dy) - Func(y)) / dy ;
    // printf(" derivative = %lf\n", der);
    return der;
}

//плохое название функции, переименуй;
//сюда тоже нужно перелать указатель на функцию левой части уравнения
//которое мы решаем
double calculation( double X0, double accuracy )
{
    double i = 0;
    double Xn = X0;
    while ( fabs(Xn - i) > accuracy )
    {
        i = X0;
        Xn = i - ( Func(i) / dFunc(i) );
        // printf("%lf, %lf, ", Xn, fabs(Xn - i));
        X0 = Xn;
        // printf(" Xn - i %lf ", fabs(Xn - i));
       
    }
 return X0;
} 

int main()
{
    double X0 = 2;
    double accuracy = 1.e-6;
    double Xn = 0;
 
    // printf("Введите начальное приближение X0: " );
    // scanf("%lf", &X0);
    // printf("Введите требуемую точность:" );
    // scanf("%lf", &accuracy);
    // printf("%lf\n", accuracy);
    double (*solve_eq) (double, double);
    solve_eq = calculation;
    Xn = solve_eq( X0, accuracy);
    printf("корень уравнения, вычисленный с точностью %lf = %lf ", accuracy, Xn);
    
}  
