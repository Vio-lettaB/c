#include<stdio.h>
#include<math.h>


float Func(float x)
{
   float res = 0;
   res = sin(x);  
   return res;
}

float integral( float a, float b, int n)
{
    float step = 0 ;
    step = (b - a) / n;
    printf(" длина разбиения: %f\n", step );
    float summ = 0 ;
   
    if ( step > 0 )
    {
         for ( float i = a; i < b ; i += step)
        {
            
            float mid = 0;
            
            mid = ( Func(i) + Func( i + step )) * step / 2;
            //  printf(" Промежуточное значение средней линии трапеци: %f\n", mid);
            summ += mid;
            //  printf(" Промежуточное значение средней линии трапеци: %f\n", summ);
            
        }
    return summ;
    }
    else
    {
        for ( float i = b; i < a ; i -= step)
        {
            
            float mid = 0;
            
            mid = ( Func(i) + Func( i + step )) * step / 2;
            // printf(" Промежуточное значение средней линии трапеци: %f\n", mid);
            summ += mid;
            // printf(" Промежуточное значение средней линии трапеци: %f\n", summ);
    }
    return summ;
}}

int main()
{
    int n_step = 0;
    float a = 0;
    float b = 6.28 ;
    printf(" Введите шаг разбиения:" );
    scanf("%d", &n_step);
    // printf("Введите по очереди пределы интегрирования:");
    //  scanf("%f %f", &a, &b);
    printf(" значение интеграла от а = %f  до  b = %f равно = %f", a, b, integral(a, b, n_step));
}


