#include <stdio.h>
#include <string.h>
#include <ctype.h>

char red_line(char str[])
{
    str[0] = toupper(str[0]);
    for(int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '.' && str[i + 1] == ' ') 
        {
            str[i + 2] = toupper(str[i + 2]);
        }
    }
    printf("%s\n", str);
}


char remove_extra_space(char str[])
{
    // char str_new[];
    
    for (int i = 0; i < strlen(str); i++)  
    {
        while ( str[i] == str[i + 1]  && str[i + 1] == ' ')
        {
            str[i + 1] = ' ';
            for (int j = i ; j < sizeof(&str) ; j++)
            {
               
                
            }
       
        }
    }
    printf("%s\n", str);
}


char remove_space_before_closing_sign(char str[])
{
    
}

char add_space_after_closing_sign(char str[])
{
    // for (int i = 0; i < strlen(str); i++)  
    // {
    //     while(str[i] == str[i + 1] && str[i] == ' ')
    //     {
    //         for (int j = i; j < sizeof(&str); j++)
    //         {
    //             str[j] = str[j + 1];
    //         }
       
    //     }
    // }
    // printf("%s\n", str);
}


int main()
{
    char str[1000] = "let's  make correctly written line .But it should be done simply. ";
    red_line(str);
    remove_extra_space(str);
    remove_space_before_closing_sign(str);
    add_space_after_closing_sign(str);
   
}
