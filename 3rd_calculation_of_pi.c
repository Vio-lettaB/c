
#include<stdio.h>
#include<conio.h>
#define SIZE 150

int main() 
{
    
    double pi4 = 1, num = 3;
    
    for(int i = 0; i < 50000000 ; i++)
    {
        
        if(i % 2 != 0) 
        {
            pi4 += 1 / num;
        } else
        {
            pi4 -= 1 / num;
        }
        num += 2;
    }
    printf("%.100f", (4 * pi4));
    getch(); //ждем нажатия клавиши
    return 0;
}
