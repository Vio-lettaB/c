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

void save_list_to_file(Node *head, const char *filename) 
{
    FILE* file = fopen(filename, "wb"); // открываем файл для записи в бинарном режиме
    if (file == NULL) 
    {
        printf("Error: cannot open file %s\n", filename);
        return;
    }
    Node *current = head;
    while (current != NULL) 
    {
        fwrite(current, sizeof(Node), 1, file); // записываем текущий узел в файл
        current = current->next;
    }
    fclose(file); // закрываем файл
    while (current != NULL)
    {
        Node *temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
}


Node *load_list_from_file(const char *filename) 
{
    FILE *file = fopen(filename, "rb"); // открываем файл для чтения в бинарном режиме
    if (file == NULL)
    {
        printf("Error: cannot open file %s\n", filename);
        return NULL;
    }
    Node *head = NULL;
    Node *current = NULL;
    while (!feof(file)) 
    {
        Node *new_node = malloc(sizeof(Node)); // выделяем память под новый узел
        fread(new_node, sizeof(Node), 1, file); // читаем данные из файла в новый узел
        if (feof(file))
        { // если достигнут конец файла, освобождаем выделенную память и выходим из цикла
            free(new_node->data);
            free(new_node);
            break;
        }
        new_node->next = NULL;
        if (head == NULL) 
        { // если это первый узел, делаем его головой списка
            head = new_node;
            current = new_node;
        } 
        else
        { // иначе добавляем узел в конец списка
            current->next = new_node;
            current = new_node;
        }
    }
    fclose(file); // закрываем файл
    return head; // возвращаем указатель на голову списка
}


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

void add_node_end( const char *filename, Data *old_data) 
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
    
    Node *current_node = load_list_from_file("list.bin");
    while (current_node->next != NULL) 
    {
        current_node = current_node->next;
    }
    current_node->next = new_node;
    save_list_to_file(current_node, "list.bin");
    // while (current_node != NULL)
    // {
    //     Node *temp = current_node;
    //     current_node = current_node->next;
    //     free(temp->data);
    //     free(temp);
    // }
}

void add_node_top(const char *filename, Data *old_data)
{
    Node *head = (Node *)malloc(sizeof(Node)); 
    head->data = (Data *)malloc(sizeof(Data));
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = (Data *)malloc(sizeof(Data));
    memcpy( new_node->data->name, old_data->name, 100 );
    memcpy( new_node->data->surname, old_data->surname, 100 );
    new_node->data->number = old_data->number;
    new_node->data->day = old_data->day;
    new_node->data->month = old_data->month;
    new_node->data->year = old_data->year;
    new_node->next = load_list_from_file("list.bin");
    head = new_node;
    save_list_to_file(head, "list.bin");
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

void delete_node(const char *filename, char *name, char *surname)
{
    Node *current_node = load_list_from_file("list.bin") ;
    Node *prev_node = NULL;
    
    while (current_node != NULL)
    {
        if (my_strcmp(current_node->data->name, name) == 0 && 
        my_strcmp(current_node->data->surname, surname) == 0 )
        {
            if (prev_node == NULL)
            {
               current_node = current_node->next;
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
    save_list_to_file(current_node, "list.bin");
}

void print_Data( Data *data)
{
    printf("Имя: %s\n", data->name);
    printf("Фамилия: %s\n", data->surname);
    printf("Номер телефона: %d\n", data->number);
    printf("Дата рождения: %d.%d.%d\n", data->day, data->month, data->year);
    printf("\n\n");
}

void print_list(const char *filename)
{
    
    Node *current_node = load_list_from_file("list.bin");
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
 
void front_back_split(const char *filename, Node **frontRef, Node **backRef)
{
    Node *source = load_list_from_file("list.bin");
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
 
void merge_sort(Node **head, int i, const char *filename)
{
    
    if (*head == NULL || (*head)->next == NULL) 
    {
        return;
    }
 
   Node* a;
   Node* b;
 
    front_back_split("list.bin", &a, &b);

    merge_sort(&a, i, "list.bin");
    merge_sort(&b, i, "list.bin");
 
    *head = sorted_merge(a, b, i);
    save_list_to_file(*head, "list.bin");
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
    save_list_to_file(head, "list.bin");
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
                
                add_node_end("list.bin", new_data);
                print_list("list.bin");
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
                delete_node("list.bin", name, surname );
                printf("обновленный массив:\n");
                print_list("list.bin");
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
                Node *head = load_list_from_file("list.bin");
                merge_sort(&head, j, "list.bin");
                printf("отсортированный массив:\n");
                print_list("list.bin");
                break;
            }
        }
    }
    return 0;
}
