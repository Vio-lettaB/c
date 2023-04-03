#include<stdio.h>
#include<math.h>


float Func(float x)
{
   float res = 0;
   res = pow(x, 2);  
   return res;
}

float integrate( float a, float b, float step)
{
    
    
    printf(" длина разбиения: %f\n", step );
    float summ = 0;
    float error = 0;
    float counter = 0;
    float diff = 0;
   
    if ( step > 0 )
    {
         for ( float i = a; i < b  ; i += step, counter++)
        {
            
            float mid = 0;
            
            mid = ( Func(i) + Func( i + step )) * step / 2;
            summ += mid;
           printf("counter = %f\n", counter);
           diff = ( Func(b) + Func( i + step )) * ( (i + step)- b) / 2;
           printf("Func( i + step) = %f\n", Func(i + step));
        }
        error = ( Func(b) + Func( a + (counter * step) )) * (a + (counter * step) - b) / 2;
        printf("Func(b) = %f\n", Func(b));
        printf("Func(a + (counter * step)) = %f\n", Func( a + (counter * step) ));
        
        summ -= error;    
    return summ;
    }
    else
    {
        for ( float i = b; i < a ; i -= step)
        {
            
            float mid = 0;
            
            mid = ( Func(i) + Func( i + step )) * step / 2;
            summ += mid;
            error = ( Func(b) + Func( i + step )) * ( (i + step)- b) / 2;
    }
    summ -= error; 
    return summ;
}}

int main()
{
    float a = 0;
    float b = 6;
    float step = 0.012114498;
    
    printf(" значение интеграла от а = %f  до  b = %f равно = %f", a, b, integrate(a, b, step));
}
