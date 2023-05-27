#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    char name[50];
    char surname[50];
    int number;
    int day;
    int month;
    int year;
};

typedef struct data Data;

struct node 
{
    Data *data;
    struct node *next;
};

typedef struct node Node;

Node *create_list( Data *data) 
{
    Node *head = (Node *)malloc(sizeof(Node));
    memcpy( head->data->name, data->name, 11 );
    memcpy( head->data->surname, data->surname, 11 );
    head->data->number = data->number;
    head->data->day = data->day;
    head->data->month = data->month;
    head->data->year = data->year;
    head->next = NULL;
    return head;
}

void add_node(Node *head, Data *data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    memcpy( new_node->data->name, data->name, 11 );
    memcpy( new_node->data->surname, data->surname, 11 );
    new_node->data->number = data->number;
    new_node->data->day = data->day;
    new_node->data->month = data->month;
    new_node->data->year = data->year;
    new_node->next = NULL;
    
    Node *current_node = head;
    while (current_node->next != NULL) 
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

void delete_node(Node *head, Data *data)
{
    Node *current_node = head;
    Node *prev_node = NULL;
    
    while (current_node != NULL)
    {
        if (current_node->data == data)
        {
            if (prev_node == NULL)
            {
                head = current_node->next;
            } 
            else 
            {
                prev_node->next = current_node->next;
            }
            free(current_node);
            return;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }
}

void print_Data( Data *data)
{
    printf("Имя: %s\n", data->name);
    printf("Фамилия: %s\n", data->surname);
    printf("Номер телефона: %d\n", data->number);
    printf("Дата рождения: %d.%d.%d\n", data->day, data->month, data->year);
}

void print_list(Node *head)
{
    Node *current_node = head;
    while (current_node != NULL)
    {
        print_Data(current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

int main()
{
    Data *data_1;
    Data *data_2;
    Data *data_3;
    printf("Введите данные первого контакта:\n Введите имя:\n ");
    scanf("%s", data_1->name );
    printf("Введите фамилию:\n");
    scanf("%s", data_1->surname );
    printf("Введите номер телефона:\n");
    scanf("%d", &data_1->number );
    printf("Введите дату рождения:\n Число:\n");
    scanf("%d", &data_1->day );
    printf("Месяц:\n");
    scanf("%d", &data_1->month );
    printf("Год:\n");
    scanf("%d", &data_1->year );
    
    printf("Введите данные второго контакта:\n Введите имя:\n ");
    scanf("%s", data_2->name );
    printf("Введите фамилию:\n");
    scanf("%s", data_2->surname );
    printf("Введите номер телефона:\n");
    scanf("%d", &data_2->number );
    printf("Введите дату рождения:\n Число:\n");
    scanf("%d", &data_2->day );
    printf("Месяц:\n");
    scanf("%d", &data_2->month );
    printf("Год:\n");
    scanf("%d", &data_2->year );
    
    printf("Введите данные третьего контакта:\n Введите имя:\n ");
    scanf("%s", data_3->name );
    printf("Введите фамилию:\n");
    scanf("%s", data_3->surname );
    printf("Введите номер телефона:\n");
    scanf("%d", &data_3->number );
    printf("Введите дату рождения:\n Число:\n");
    scanf("%d", &data_3->day );
    printf("Месяц:\n");
    scanf("%d", &data_3->month );
    printf("Год:\n");
    scanf("%d", &data_3->year );
    
    
    Node *head = create_list(data_1);
    add_node(head, data_2);
    add_node(head, data_3);
    print_list(head);
    
    delete_node(head, data_2);
    print_list(head);
    
    return 0;
}
