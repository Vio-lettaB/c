#include <stdio.h>
#include <math.h>


//есть 3 функции

double func1(double x) {
    return sin(x);
}

double func2(double x) {
    return fabs(x) < 0.1 ? 1 : sin(1 / x); // это тернарный оператор. Погугли "тернарный оператор си"
}

double func3(double x) {
    return sin(pow(x, 2));
}

// есть одна для всех функция дифференцирования, которая принимает
// 1) указатель на дифференцируемую функцию
// 2) x
// 3) dx
double derivate(double(*fuction)(double), double x, double dx) {
    return (fuction(x + dx) - fuction(x - dx)) / (2 * dx);
}

// есть одна для всех функция, печатающая значение в точке х.
// Она принимает:
// 1) название функции
// 2) указатель на функцию
// 3) точку x
void print_function_value_in_point(char* name, double(*fuction)(double), double x) {
    printf("%s(x = %lf) = %lf\n", name, x, fuction(x));
}

// есть одна для всех функция, печатающая значение производной в точке х.
// Она принимает:
// 1) название функции
// 2) указатель на функцию
// 3) точку x
void print_derivation_in_point(char* name, double(*fuction)(double), double x) {
    // в этой функции мы передаём указатель на функцию fuction в функцию derivate
    // в качестве аргумента. и это всё ещё даже работает
    printf("d/dx (%s(x = %lf)) = %lf\n", name, x, derivate(fuction, x, 1.e-5));
}


int main() {
    double x_value = 6.28;
    print_function_value_in_point("func1", func1, x_value);
    print_function_value_in_point("func2", func2, x_value);
    print_function_value_in_point("func3", func3, x_value);
    printf("\n");
    double new_x_value = 6.28 / 4;
    print_derivation_in_point("func1", func1, new_x_value);
    print_derivation_in_point("func2", func2, new_x_value);
    print_derivation_in_point("func3", func3, new_x_value);
}