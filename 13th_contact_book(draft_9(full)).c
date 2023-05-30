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
    if (new_node == NULL)
    {
        exit(1);
    }
    if (head == NULL)
    {
        head = new_node;
        return;
    }
    Node *current_node = head;
    while (current_node->next != NULL) 
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
}

// void add_node_top(Node *head, Data *old_data)
// {
//     Node *new_node = (Node *)malloc(sizeof(Node));
//     new_node->data = (Data *)malloc(sizeof(Data));
//     memcpy( new_node->data->name, old_data->name, 100 );
//     memcpy( new_node->data->surname, old_data->surname, 100 );
//     new_node->data->number = old_data->number;
//     new_node->data->day = old_data->day;
//     new_node->data->month = old_data->month;
//     new_node->data->year = old_data->year;
//     new_node->next = head;
//     head = new_node;
// }


void save_list_to_file(Node *head)
{
    FILE* file = fopen("list.txt", "w");
    if (file == NULL) 
    {
        exit(1);
    }

    for (Node* current = head; current != NULL; current = current->next) 
    {
        fprintf(file, "%s, ", current->data->surname);
        fprintf(file, "%s, ", current->data->surname);
        fprintf(file, "%d, ", current->data->number);
        fprintf(file, "%d, ", current->data->day);
        fprintf(file, "%d, ", current->data->month);
        fprintf(file, "%d, ", current->data->year);
    }
    fclose(file);
}

// void save_list_to_file(Node *head, const char *filename)
// {
//     FILE* file = fopen(filename, "wb"); 
//     if (file == NULL)
//     {
//         printf("Error: cannot open file %s\n", filename);
//         return;
//     }
//     Node *current = head;
//     while (current != NULL)
//     {
//         fwrite(current, sizeof(Node), 1, file); 
//         current = current->next;
//     }
//     fclose(file); 
//     while (current != NULL)
//     {
//         Node *temp = current;
//         current = current->next;
//         free(temp->data);
//         free(temp);
//     }
// }

void load_list_from_file(Node **head) 
{
    FILE* file = fopen("list.txt", "r");
    if (file == NULL) 
    {
        printf("файл пуст");
        exit(2);
    }
    Data *new_data;
    while(fscanf(file, "%s, ", new_data->name) > 0
    && fscanf(file, "%s, ", new_data->surname) > 0
    && fscanf(file, "%d, ", &new_data->number) > 0 
    && fscanf(file, "%d, ", &new_data->day) > 0
    && fscanf(file, "%d, ", &new_data->month) > 0
    && fscanf(file, "%d, ", &new_data->year) > 0) 
    {
        add_node_end( *head, new_data);
    }
    fclose(file);
}

// Node *load_list_from_file(const char *filename)
// {
//     FILE *file = fopen(filename, "rb"); 
//     if (file == NULL)
//     {
//         printf("Error: cannot open file %s\n", filename);
//         return NULL;
//     }
//     Node *head = NULL;
//     Node *current = NULL;
//     while (!feof(file))
//     {
//         Node *new_node = malloc(sizeof(Node)); 
//         fread(new_node, sizeof(Node), 1, file); 
//         if (feof(file))
//         { 
//             free(new_node->data);
//             free(new_node);
//             break;
//         }
//         new_node->next = NULL;
//         if (head == NULL)
//         { 
//             head = new_node;
//             current = new_node;
//         }
//         else
//         { 
//             current->next = new_node;
//             current = new_node;
//         }
//     }
//     fclose(file);
//     return head; 
// }


void free_node(Node *head)
{
    Node *current_node = head;
    while (current_node != NULL)
    {
        Node *tmp = current_node;
        current_node = current_node->next;
        free(tmp->data);
        free(tmp);
    }
    head = NULL;
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

void delete_node(Node **head, char *name, char *surname)
{
    Node *current_node = *head;
    Node *prev_node = NULL;
    
    while (current_node != NULL)
    {
        if (my_strcmp(current_node->data->name, name) == 0 && 
        my_strcmp(current_node->data->surname, surname) == 0 )
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
    printf("главное меню\nвведите первый контакт:\n ");
    Data *data_1 = (Data *)malloc(sizeof(Data));
    printf("Введите данные контакта:\nВведите имя:\n ");
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
    Node *head = create_list(data_1);
    save_list_to_file(head);
    int i = - 1;
    while(i != 0)
    {
        printf("главное меню\nвыберите действие:\n ");
        printf("нажмите 1 чтобы\nсоздать контакт:\n ");
        printf("нажмите 2 чтобы\nудалить контакт:\n ");
        printf("нажмите 3 чтобы\nсортировать контакты:\n ");
        printf("нажмите 0 чтобы\nзакрыть программу\n ");
        scanf("%d", &i);
        switch(i)
        {
            case 1:
            {
                
                Data *new_data = (Data *)malloc(sizeof(Data));
                printf("Введите данные контакта:\nВведите имя:\n ");
                scanf("%s", new_data->name );
                printf("Введите фамилию:\n");
                scanf("%s", new_data->surname );
                printf("Введите номер телефона:\n");
                scanf("%d", &new_data->number );
                printf("Введите дату рождения:\nЧисло:\n");
                scanf("%d", &new_data->day );
                printf("Месяц:\n");
                scanf("%d", &new_data->month );
                printf("Год:\n");
                scanf("%d", &new_data->year );
                printf("\n\n");
                printf("ошибка");
                load_list_from_file(&head);
                print_list(head);
                add_node_end(head, new_data);
                print_list(head);
                save_list_to_file(head);
                break;
            }
             case 2:
            {   
                char name[100];
                char surname[100];
                printf("Введите имя и фамилию контакта, который хотите удалить\n");
                printf("Имя:\n");
                scanf("%s", name);
                printf("фамилия:\n");
                scanf("%s", surname);
                load_list_from_file(&head);
                delete_node(&head, name, surname );
                printf("обновленный массив:\n");
                print_list(head);
                save_list_to_file(head);
                break;
            }
             case 3:
            {
                printf("выберите поле сортировки\n");
                printf("Для выбора имени нажмите 1\n");
                printf("Для выбора фамилии нажмите 2\n");
                printf("Для выбора номера нажмите 3\n");
                printf("Для выбора даты рождения нажмите 4\n");
                int j;
                scanf("%d", &j);
                load_list_from_file(&head);
                merge_sort(&head, j);
                printf("отсортированный массив:\n");
                print_list(head);
                save_list_to_file(head);
                break;
            }
        }
    }
    free_node(head);
    return 0;
}
