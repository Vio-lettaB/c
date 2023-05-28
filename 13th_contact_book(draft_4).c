#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    char name[100];
    char surname[100];
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

Node *create_list( Data *old_data) 
{
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = (Data *)malloc(sizeof(Data));
    memcpy( head->data->name, old_data->name, 100 );
    memcpy( head->data->surname, old_data->surname, 100 );
    head->data->number = old_data->number;
    head->data->day = old_data->day;
    head->data->month = old_data->month;
    head->data->year = old_data->year;
    head->next = NULL;
    return head;
}

void add_node_end(Node *head, Data *old_data) 
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = (Data *)malloc(sizeof(Data));
    memcpy( new_node->data->name, old_data->name, 100 );
    memcpy( new_node->data->surname, old_data->surname, 100 );
    new_node->data->number = old_data->number;
    new_node->data->day = old_data->day;
    new_node->data->month = old_data->month;
    new_node->data->year = old_data->year;
    new_node->next = NULL;
    
    Node *current_node = head;
    while (current_node->next != NULL) 
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}


void add_node_top(Node *head, Data *old_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = (Data *)malloc(sizeof(Data));
    memcpy( new_node->data->name, old_data->name, 100 );
    memcpy( new_node->data->surname, old_data->surname, 100 );
    new_node->data->number = old_data->number;
    new_node->data->day = old_data->day;
    new_node->data->month = old_data->month;
    new_node->data->year = old_data->year;
    new_node->next = head;
    head = new_node;
}

int my_strcmp(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    if(*(const unsigned char*)s1 - *(const unsigned char*)s2 > 0)
    {
        return 1;
    }
    if(*(const unsigned char*)s1 - *(const unsigned char*)s2 < 0)
    {
        return - 1;
    }
    if (*(const unsigned char*)s1 - *(const unsigned char*)s2 == 0)
    {
        return 0;
    }
}

void delete_node(Node **head, Data *data)
{
    Node *current_node = *head;
    Node *prev_node = NULL;
    
    while (current_node != NULL)
    {
        if (my_strcmp(current_node->data->name, data->name) == 0 && 
        my_strcmp(current_node->data->surname, data->surname) == 0 )
        {
            if (prev_node == NULL)
            {
                *head = current_node->next;
            } 
            else 
            {
                prev_node->next = current_node->next;
            }
            free(current_node->data);
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
    printf("\n\n");
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

Node *sorted_merge( Node *a, Node *b, int i)
{
    if (a == NULL)
    {
        return b;
    }
 
    else if (b == NULL)
    {
        return a;
    }
 
    Node *result = NULL;
    switch(i)
    {
        case 1:
        {
            if (my_strcmp(a->data->name, b->data->name) == -1)
            {
                result = a;
                result->next = sorted_merge(a->next, b, i);
            } 
            else
            {
                result = b;
                result->next = sorted_merge(a, b->next, i);
            }
            break;
        }
        case 2:
        {
            if (my_strcmp(a->data->surname, b->data->surname) == -1 )
            {
                result = a;
                result->next = sorted_merge(a->next, b, i);
            }
            else
            {
                result = b;
                result->next = sorted_merge(a, b->next, i);
            }
            break;
        }
        case 3:
        {
            if (a->data->number <= b->data->number)
            {
                result = a;
                result->next = sorted_merge(a->next, b, i);
            }  
            else
            {
                result = b;
                result->next = sorted_merge(a, b->next, i);
            }
 
            break;
        }
        case 4:
        {
            if (a->data->year <= b->data->year  && a->data->month <= b->data->month && a->data->day <= b->data->day )
            {
                result = a;
                result->next = sorted_merge(a->next, b, i);
            } 
            else
            {
                result = b;
                result->next = sorted_merge(a, b->next, i);
            }
            break;
        }
    }
    
    return result;
}
 
void front_back_split(Node *source, Node **frontRef, Node **backRef)
{
    if (source == NULL || source->next == NULL)
    {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
 
    Node *slow = source;
    Node *fast = source->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}
 
void merge_sort(Node **head, int i)
{
    if (*head == NULL || (*head)->next == NULL) 
    {
        return;
    }
 
   Node* a;
   Node* b;
 
    front_back_split(*head, &a, &b);

    merge_sort(&a, i);
    merge_sort(&b, i);
 
    *head = sorted_merge(a, b, i);
}
 

int main()
{
    // FILE *fp;
    // fp = fopen(«file.txt», «w»);
    // fprintf(fp, «Hello, world!\n»);
    // fclose(fp);
    
    Data *data_1 = (Data *)malloc(sizeof(Data));
    Data *data_2 = (Data *)malloc(sizeof(Data));
    Data *data_3 = (Data *)malloc(sizeof(Data));
    Data *data_4 = (Data *)malloc(sizeof(Data));
    printf("Введите данные первого контакта:\nВведите имя:\n ");
    scanf("%s", data_1->name );
    printf("Введите фамилию:\n");
    scanf("%s", data_1->surname );
    printf("Введите номер телефона:\n");
    scanf("%d", &data_1->number );
    printf("Введите дату рождения:\nЧисло:\n");
    scanf("%d", &data_1->day );
    printf("Месяц:\n");
    scanf("%d", &data_1->month );
    printf("Год:\n");
    scanf("%d", &data_1->year );
    printf("\n\n");
    
    printf("Введите данные второго контакта:\nВведите имя:\n ");
    scanf("%s", data_2->name );
    printf("Введите фамилию:\n");
    scanf("%s", data_2->surname );
    printf("Введите номер телефона:\n");
    scanf("%d", &data_2->number );
    printf("Введите дату рождения:\nЧисло:\n");
    scanf("%d", &data_2->day );
    printf("Месяц:\n");
    scanf("%d", &data_2->month );
    printf("Год:\n");
    scanf("%d", &data_2->year );
    printf("\n\n");
    
    printf("Введите данные третьего контакта:\nВведите имя:\n ");
    scanf("%s", data_3->name );
    printf("Введите фамилию:\n");
    scanf("%s", data_3->surname );
    printf("Введите номер телефона:\n");
    scanf("%d", &data_3->number );
    printf("Введите дату рождения:\nЧисло:\n");
    scanf("%d", &data_3->day );
    printf("Месяц:\n");
    scanf("%d", &data_3->month );
    printf("Год:\n");
    scanf("%d", &data_3->year );
    printf("\n\n");
    
    
    printf("Введите данные четвертого контакта:\nВведите имя:\n ");
    scanf("%s", data_4->name );
    printf("Введите фамилию:\n");
    scanf("%s", data_4->surname );
    printf("Введите номер телефона:\n");
    scanf("%d", &data_4->number );
    printf("Введите дату рождения:\nЧисло:\n");
    scanf("%d", &data_4->day );
    printf("Месяц:\n");
    scanf("%d", &data_4->month );
    printf("Год:\n");
    scanf("%d", &data_4->year );
    printf("\n\n");
    
    Node *head = create_list(data_1);
    add_node_end(head, data_2);
    add_node_end(head, data_3);
    add_node_end(head, data_4);
    print_list(head);
    
    
    delete_node(&head, data_2);
    printf("обновленный массив:\n");
    print_list(head);
    
    printf("выберите поле сортировки\n");
    printf("Для выбора имени нажмите 1\n");
    printf("Для выбора фамилии нажмите 2\n");
    printf("Для выбора номера нажмите 3\n");
    printf("Для выбора даты рождения нажмите 4\n");
    int i;
    scanf("%d", &i);
    
    merge_sort(&head, i);
    printf("отсортированный массив:\n");
    print_list(head);
    
    // printf("выберите поле сортировки\n");
    // printf("Для выбора имени нажмите 1\n");
    // printf("Для выбора фамилии нажмите 2\n");
    // printf("Для выбора номера нажмите 3\n");
    // printf("Для выбора даты рождения нажмите 4\n");
    // scanf("%d", &i);
    
    // merge_sort(&head, i);
    // printf("отсортированный массив:\n");
    // print_list(head);
    
    // printf("выберите поле сортировки\n");
    // printf("Для выбора имени нажмите 1\n");
    // printf("Для выбора фамилии нажмите 2\n");
    // printf("Для выбора номера нажмите 3\n");
    // printf("Для выбора даты рождения нажмите 4\n");
    // scanf("%d", &i);
    
    // merge_sort(&head, i);
    // printf("отсортированный массив:\n");
    // print_list(head);
    
    // printf("выберите поле сортировки\n");
    // printf("Для выбора имени нажмите 1\n");
    // printf("Для выбора фамилии нажмите 2\n");
    // printf("Для выбора номера нажмите 3\n");
    // printf("Для выбора даты рождения нажмите 4\n");
    // scanf("%d", &i);
    
    // merge_sort(&head, i);
    // printf("отсортированный массив:\n");
    // print_list(head);
    
    return 0;
}
