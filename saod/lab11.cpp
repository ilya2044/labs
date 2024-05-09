#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <cmath>
#include <iomanip>
#define par int

using namespace std;

int comparisons = 0, shipments = 0;

typedef struct st
{
    struct st *next;
    union
    {
        int data;
        unsigned char digit[sizeof(data)];
    };
} list;

typedef struct queue
{
    list *head = NULL;
    list *tail = NULL;
} line;

int rnd()
{
    int r = 1 + rand() % (10 + 1 - 1);
    return r;
}

void ATTB(list *&head, int i)
{
    list *p;
    p = new list[1];
    p->data = i;
    p->next = head;
    head = p;
}

void FillInc(list *&head, int len)
{
    for (int i = 0; i < len; i++)
        ATTB(head, i + 1);
}

void FillDec(list *&head, int len)
{
    for (int i = 0; i < len; i++)
        ATTB(head, len - i);
}

void FillRand(list *&head, int len)
{
    srand(time(NULL));
    for (int i = 0; i < len; i++)
    {
        ATTB(head, rnd());
    }
}

void PrintList(list *&head)
{
    list *p;
    p = head;
    if (p)
    {
        PrintList(p->next);
        cout << p->data << " ";
    }
}

int ChecklSum(list *&head)
{
    int sum = 0;
    list *p;
    p = head;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    printf("Сумма: ");
    return sum;
}

int Rundataber(list *&head)
{
    int k = 1;
    list *p;
    p = head;
    while (p->next)
    {
        if (p->data < p->next->data)
            k++;
        p = p->next;
    }
    printf("Кол-во серий: ");
    return k;
}

int main()
{
    list *head;
    list *tail;
    int len = 10;

    head = NULL;
    printf("-----------------\n");
    printf("Случайный массив: \n");

    comparisons = 0, shipments = 0;
    head = NULL;
    FillRand(head, len);
    PrintList(head);
    cout << endl;
    cout << ChecklSum(head) << endl;
    cout << Rundataber(head) << endl;

    printf("-----------------\n");
    printf("Возрастающий массив:\n");
    comparisons = 0, shipments = 0;
    head = NULL;
    FillInc(head, len);
    PrintList(head);
    cout << endl;
    cout << ChecklSum(head) << endl;
    cout << Rundataber(head) << endl;

    printf("-----------------\n");
    printf("Убывающий массив\n");
    comparisons = 0, shipments = 0;
    head = NULL;
    FillDec(head, len);
    PrintList(head);
    cout << endl;
    cout << ChecklSum(head) << endl;
    cout << Rundataber(head) << endl;
    printf("-----------------\n");

    return 0;
}
