#include<stdio.h>
#include<math.h>


float Func(float x)
{
   float res = 0;
   res = pow(x, 2);  
   return res;
}

float integral( float a, float b)
{
    float step = 0.012114498;
    
    printf(" длина разбиения: %f\n", step );
    float summ = 0;
    float diff = 0;
   
    if ( step > 0 )
    {
         for ( float i = a; i < b  ; i += step)
        {
            
            float mid = 0;
            
            mid = ( Func(i) + Func( i + step )) * step / 2;
            //  printf(" Промежуточное значение средней линии трапеци: %f\n", mid);
            summ += mid;
            //  printf(" Промежуточное значение средней линии трапеци: %f\n", summ);
            diff = ( Func(b) + Func( i + step )) * ( (i + step)- b) / 2;
        }
        
        summ -= diff;    
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
            diff = ( Func(b) + Func( i + step )) * ( (i + step)- b) / 2;
    }
    summ -= diff; 
    return summ;
}}

int main()
{
    float a = 0;
    float b = 6 ;
    // printf("Введите по очереди пределы интегрирования:");
    //  scanf("%f %f", &a, &b);
    printf(" значение интеграла от а = %f  до  b = %f равно = %f", a, b, integral(a, b));
}
