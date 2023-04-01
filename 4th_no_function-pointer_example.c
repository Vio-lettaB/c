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

// 3 функции, выглядящие абсолютно одинаково и делающие одно и то же
// это называется дублирование кода. Это плохо
double derivate_func1(double x, double dx) {
    return (func1(x + dx) - func1(x - dx)) / (2 * dx);
}

double derivate_func2(double x, double dx) {
    return (func2(x + dx) - func2(x - dx)) / (2 * dx);
}

double derivate_func3(double x, double dx) {
    return (func2(x + dx) - func2(x - dx)) / (2 * dx);
}

// ещё 3 одинаковых функции
void print_func1_value_in_point(double x) {
    printf("%s(x = %lf) = %lf\n", x, func1(x));
}

void print_func2_value_in_point(double x) {
    printf("func2(x = %lf) = %lf\n", x, func2(x));
}

void print_func3_value_in_point(double x) {
    printf("func3(x = %lf) = %lf\n", x, func3(x));
}

// и ещё 3 одинаковых функции
void print_dfunc1_in_point(double x) {
    printf("d/dx (func1(x = %lf)) = %lf\n", x, derivate_func1(x, 1.e-5));
}

void print_dfunc2_in_point(double x) {
    printf("d/dx (func2(x = %lf)) = %lf\n", x, derivate_func2(x, 1.e-5));
}

void print_dfunc3_in_point(double x) {
    printf("d/dx (func3(x = %lf)) = %lf\n", x, derivate_func3(x, 1.e-5));
}

// итого вместо 3х функций, которые принимают в себя указатели на функцию
// мы получаем целых 9 функций, которые одинаково выглядят и делают одно и то же
// в 3 раза больший объём кода
// в 3 раза больше читать
// в 3 раза больше писать
// в 3 раза больше шансов ошибиться
// в 3 раза дольше искать ошибку

int main() {
    double x_value = 6.28;
    print_func1_value_in_point(x_value);
    print_func2_value_in_point(x_value);
    print_func3_value_in_point(x_value);
    printf("\n");
    double new_x_value = 6.28 / 4;
    print_dfunc1_in_point(new_x_value);
    print_dfunc2_in_point(new_x_value);
    print_dfunc3_in_point(new_x_value);
}