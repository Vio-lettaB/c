#include<stdio.h>
#include<math.h>


float Func(float x)
{
   float res;
   res = pow(x , 2);  
   return res;
}



int main()
{
    int n_step;
    float a;
    float b;
    float step;
    float ind;
    printf(" Введите шаг разбиения:" );
    scanf("%d", &n_step);
    printf("Введите по очереди пределы интегрирования:");
    scanf("%f", &a);
    scanf("%f", &b);
    step = (b - a) / n_step;
    printf(" длина разбиения: %f\n", step );
    for ( float i = a; i != b ; i += step)
    {
        float mid;
        float summid;
        mid = ( Func(i) + Func( i + step )) * step / 2;
        // printf(" Промежуточное значение средней линии трапеци: %f\n", mid);
        summid += mid;
        // printf(" Промежуточное значение средней линии трапеци: %f\n", summid);
        ind = summid;
    }
    printf(" значение интеграла от а = %f  до  b = %f равно = %f", a, b, ind );
    
}
