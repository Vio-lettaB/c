#include<stdio.h>
#include<math.h>


float Func(float x)
{
   float res;
   res = 1 - x;  
   return res;
}

float integral( float a, float b, int n)
{
    float step;
    step = (b - a) / n;
    printf(" длина разбиения: %f\n", step );
    float summid;
    float ind;
    if ( step > 0 )
    {
         for ( float i = a; i != b ; i += step)
        {
            
            float mid;
            
            mid = ( Func(i) + Func( i + step )) * step / 2;
            // printf(" Промежуточное значение средней линии трапеци: %f\n", mid);
            summid += mid;
            // printf(" Промежуточное значение средней линии трапеци: %f\n", summid);
             ind = summid;
        }
    }
    else
    {
        for ( float i = b; i != a ; i += step)
        {
            
            float mid;
            
            mid = ( Func(i) + Func( i + step )) * step / 2;
            // printf(" Промежуточное значение средней линии трапеци: %f\n", mid);
            summid += mid;
            // printf(" Промежуточное значение средней линии трапеци: %f\n", summid);
             ind = summid;
    }
    return ind;
}

int main()
{
    int n_step;
    float a = 0;
    float b = 3.14;

   
    printf(" Введите шаг разбиения:" );
    scanf("%d", &n_step);
    // printf("Введите по очереди пределы интегрирования:");
    // scanf("%f %f", &a, &b);
    printf(" значение интеграла от а = %f  до  b = %f равно = %f", a, b, integral(a, b, n_step));
} 
