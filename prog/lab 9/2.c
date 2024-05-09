#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef struct Students
{
    char *surname;
    int marks[4];
    struct Students *next;
    struct Students *prev;
} Students;

Students *get_last(Students *head)
{
    while (head->next)
    {
        head = head->next;
    }
    return head;
}

Students *push(Students *head, char *surname, int length, int *marks)
{
    if (!head)
    {
        Students *tmp = (Students *)malloc(sizeof(Students));
        tmp->surname = (char *)malloc(sizeof(char) * (length + 1));
        for (int i = 0; i < length; i++)
        {
            tmp->surname[i] = surname[i];
        }
        tmp->surname[length] = 0;
        for (int i = 0; i < 4; i++)
        {
            tmp->marks[i] = marks[i];
        }
        tmp->next = 0;
        tmp->prev = 0;
        return tmp;
    }
    Students *tmp = get_last(head);
    tmp->next = push(tmp->next, surname, length, marks);
    tmp->next->prev = tmp;
    return head;
}

void print_list(Students *head)
{
    while (head)
    {
        printf("%s - %i, %i, %i, %i\n", head->surname, head->marks[0], head->marks[1], head->marks[2], head->marks[3]);
        head = head->next;
    }
}

Students *sort(Students *head)
{
    Students *tmp = head;
    while (tmp)
    {
        int flag = 0;
        for (int i = 0; i < 4; i++)
        {
            if (tmp->marks[i] < 3)
            {
                Students *tmp2 = tmp->prev;
                if (!tmp2)
                {
                    if (!tmp->next)
                    {
                        free(tmp);
                        return 0;
                    }
                    tmp = tmp->next;
                    tmp->prev = 0;
                    free(head);
                    head = tmp;
                    flag = 1;
                    break;
                }
                tmp2->next = tmp->next;
                free(tmp);
                tmp = tmp2;
                break;
            }
        }
        if (!flag)
            tmp = tmp->next;
    }
    return head;
}

int main()
{
    int n;
    printf("Введите кол-во студентов\n");
    scanf("%d", &n);
    printf("Введите фамилии студентов и их оценки \n");
    Students *head = 0;
    for (int i = 0; i < n; i++)
    {
        char surname[256] = {0};
        int marks[4];
        scanf("%255s %i %i %i %i", surname, &marks[0], &marks[1], &marks[2], &marks[3]);
        head = push(head, surname, strlen(surname), marks);
    }
    printf("_____________________________________\n");
    printf("Вы ввели:\n");
    print_list(head);
    printf("_____________________________________\n");
    printf("Студенты, у которых нет неудовлетворительных оценок:\n");
    head = sort(head);
    print_list(head);
}