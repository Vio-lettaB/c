#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


char *my_realloc(char *string, int start_size, int len)
{
    char *new_string = (char *)malloc(start_size *sizeof(char));
    memcpy(new_string, string, len );
    free(string);
    return(new_string);
    
}


char *get_string(int *len) 
{
    *len = 0;
    int start_size = 1; 
    char *string = (char*) malloc(sizeof(char)); 

    char c = getchar();
    
    
    while (c != '\n')
    {
        string[(*len)++] = c;
        
        
        if (*len >= start_size) 
        {
            start_size *= 2; 
            string = my_realloc(string, start_size, *len);  
        }

        c = getchar();
    }

    string[*len] = '\0'; 

    return string; 
}

void upper_case(char str[])
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


void remove_extra_space(char str[])
{
    
    for (int i = 0; i < strlen(str); i++)  
    {
        while ( str[i] == str[i + 1]  && str[i + 1] == ' ')
        {
            for (int j = i ; j < strlen(str); j++ )
            {
                str[j] = str[j + 1];
            }
        }
    }
    printf("%s\n", str);
}


void remove_space_before_closing_sign(char str[])
{
    for (int i = 0; i < strlen(str); i++)  
    {
        while ( str[i] == ' ' && (str[i + 1] == ',' || str[i + 1] == '.'))
        {
            for (int j = i ; j < strlen(str); j++ )
            {
                str[j] = str[j + 1];
            }
        }
    }
    printf("%s\n", str);
}


void add_space_after_closing_sign(char str[])
{
    for (int i = 0; i < strlen(str); i++)  
    {
        while((str[i - 1] == ',' || str[i - 1] == '.') && str[i] != ' ' )
        {
            // printf("str before: \"%s\"\n", str);
            int j = strlen(str) + 1;
            // printf("j = %d, i = %d\n", j, i);    
            for (int j = strlen(str) + 1; j > i   ; j--)
            {   
                // printf("%c <- %c\n", str[j], str[j - 1]);
                str[j] = str[j - 1];
                
            }
            str[i] = ' ';
            // printf("str after: \"%s\"\n", str);
        }
        
    }
    printf("%s\n", str);
}


void test_upper_case()
{
    printf("begin\n");
    char str_example[64] = "abc. def";
    printf("str_example: %s\n", str_example);
    char expected_result[64] = "Abc. Def";
    upper_case(str_example);
    for( int i = 0; i < strlen(str_example); i ++ )
    {
        if( str_example[i] != expected_result[i])
        {
            printf("error\n"); 
            printf(" there is lowercase");
        }
    }
    
}


void test_extra_spaces() 
{
    printf("begin\n");
    char str_example[64] = "a          b 1 2 3 4";
     printf("str_example: %s\n", str_example);
    char expected_result[64] = "a b 1 2 3 4";
    remove_extra_space(str_example);
    for( int i = 0; i < strlen(str_example); i ++ )
    {
        if( str_example[i] != expected_result[i])
        {
            printf("error\n"); 
            printf(" there is extra space");
        }
    }
    
}


void test_remove_space_before_closing_sign()
{
    printf("begin\n");
    char str_example[64] = "Abc , Def .";
     printf("str_example: %s\n", str_example);
    char expected_result[64] = "Abc, Def.";
    remove_space_before_closing_sign(str_example);
    for( int i = 0; i < strlen(str_example); i ++ )
    {
        if( str_example[i] != expected_result[i])
        {
            printf("error\n"); 
            printf(" there is extra space before closing sign\n");
        }
    }
    
}


void test_add_space_after_closing_sign()
{
    printf("begin\n");
    char str_example[64] = "Abc,Def";
    printf("str_example: %s\n", str_example);
    char expected_result[64] = "Abc, Def";
    add_space_after_closing_sign(str_example);
    for( int i = 0; i < strlen(str_example); i ++ )
    {
        if( str_example[i] != expected_result[i])
        {
            printf("error\n"); 
            printf(" there is no space after closing sign\n");
        }
    }
    

}



int main()
{
    // test_upper_case();
    // test_extra_spaces();
    // test_remove_space_before_closing_sign();
    // test_add_space_after_closing_sign();
    
    int len;
    char *string = get_string(&len); 

    printf("You've wrote: '%s', symbols: %d\n", string, len); 
    
    upper_case(string);
    remove_extra_space(string);
    remove_space_before_closing_sign(string);
    add_space_after_closing_sign(string);
    
    free(string);

    return 0;

}
