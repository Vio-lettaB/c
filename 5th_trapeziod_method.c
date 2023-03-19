#include<stdio.h>
#include<math.h>


float Func(float x)
{
   float res;
   res = pow(x , 2);  
   return res;
}



double main()
{
    int step;
    float a;
    float b;
    float len;
    float Xn;
    float i;
    float *ind;
    printf(" Введите шаг разбиения:" );
    scanf("%d", &step);
    printf("Введите по очереди пределы интегрирования:");
    scanf("%f", &a);
    scanf("%f", &b);
    len = (b - a) / step;
    printf(" длина разбиения: %f\n", len );
    for ( i = a; i != b ; i += len)
    {
        float mid;
        float summid;
        mid = ( Func(i) + Func( i + len )) * len / 2;
        // printf(" Промежуточное значение средней линии трапеци: %f\n", mid);
        summid += mid;
        // printf(" Промежуточное значение средней линии трапеци: %f\n", summid);
        ind = &summid;
    }
    printf(" значение интеграла от а = %f  до  b = %f равно = %f", a, b, *ind );
    
}
