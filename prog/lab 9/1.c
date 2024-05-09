#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))

typedef struct Students
{
    char *surname;
    int marks[4];
    struct Students *next;
} Students;

void print_list(Students *head)
{
    while (head)
    {
        printf("%2s - %i, %i, %i, %i\n", head->surname, head->marks[0], head->marks[1], head->marks[2], head->marks[3]);
        head = head->next;
    }
}

Students *sort(Students *head, Students *elem)
{
    if (strcmp(head->surname, elem->surname) > 0)
    {
        elem->next = head;
        return elem;
    }
    Students *tmp = head;
    while (tmp->next)
    {
        if (strcmp(tmp->next->surname, elem->surname) > 0)
        {
            elem->next = tmp->next;
            tmp->next = elem;
            return head;
        }
        tmp = tmp->next;
    }
    tmp->next = elem;
    return head;
}

Students *push_and_sort(Students *head, char *surname, int length, int *marks)
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
        return tmp;
    }
    Students *tmp = 0;
    tmp = push_and_sort(tmp, surname, length, marks);
    tmp = sort(head, tmp);
    return tmp;
}

int main()
{
    int n;
    printf("Введите кол-во студентов:\n");
    scanf("%d", &n);
    printf("Введите фамилии студентов и их оценки:\n");
    Students *head = 0;
    for (int i = 0; i < n; i++)
    {
        char surname[256] = {0};
        int marks[4];
        scanf("%255s %i %i %i %i", surname, &marks[0], &marks[1], &marks[2], &marks[3]);
        head = push_and_sort(head, surname, strlen(surname), marks);
    }
    printf("________________________\n");
    printf("Сортировка по фамилии:\n");
    print_list(head);
}