#include<stdio.h>
#include<math.h>


float Func1(float x)
{
   float res = 0;
   res = pow(x, 2);  
   return res;
}

float Func2(float x)
{
   float res = 0;
   res = pow(x, 3);  
   return res;
}


float integrate( float(*Func)(float), float a, float b, float step)
{
    
    
    printf(" длина разбиения: %f\n", step );
    float summ = 0;
    float error = 0;
    float counter = 0;
   
    if ( step > 0 )
    {
         for ( float i = a; i < b  ; i += step, counter++)
        {
            
            float mid = 0;
            
            mid = ( Func(i) + Func( i + step )) * step / 2;
            summ += mid;
        }
        error = ( Func(b) + Func( a + (counter * step) )) * (a + (counter * step) - b) / 2;
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
           error = ( Func(b) + Func( a + (counter * step) )) * (a + (counter * step) - b) / 2;
    }
    summ -= error; 
    return summ;
}}

int main()
{
    float a = 0;
    float b = 6;
    float step = 0.01217113;
    
    printf(" значение интеграла 1 от а = %f  до  b = %f равно = %f\n", a, b, integrate( Func1, a, b, step));
    printf(" значение интеграла 2 от а = %f  до  b = %f равно = %f", a, b, integrate( Func2, a, b, step));
}
