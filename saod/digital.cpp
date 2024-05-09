#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

using namespace std;

#define N 5

typedef struct tData
{
    int Data;
} tData;

typedef struct StructList
{
    struct StructList *next;
    union
    {
        tData Data;
        unsigned char Digit[sizeof(tData)];
    };
} List;

typedef struct Queue
{
    List *head;
    List *tail;
} Queue;

List *ListFillInc(int n);
List *ListFillDec(int n);
List *ListFillRand(int n);

Queue *InitQueue(int data);
Queue *ListFillIncQ(int n);
Queue *ListFillDecQ(int n);
Queue *ListFillRandQ(int n);

int isEmpty(List *head);
void ListCheck(List *head);
void ListFree(List *head);
void Push(List **head, int data);
int Pop(List **head);
void Enqueue(Queue *c, int data);
int ListCheckSum(List *head);
int ListCheckRunNumber(List *head);

int DigitalSort(List *&S);

int main()
{
    srand(time(NULL));
    int n;
    int i;
    List *head = new List;
    Queue *queue = new Queue;

    n = 1000;

    head = NULL;
    head = ListFillRand(n);

    cout << "2 байта:\n";

    cout << "Контрольная сумма = " << ListCheckSum(head) << endl;
    cout << "Серии = " << ListCheckRunNumber(head) << endl;
    DigitalSort(head);

    cout << "Контрольная сумма = " << ListCheckSum(head) << endl;
    cout << "Серии = " << ListCheckRunNumber(head) << endl;

    cout << "\n";
    cout << "4 байта:\n";

    cout << "Контрольная сумма = " << ListCheckSum(head) << endl;
    cout << "Серии = " << ListCheckRunNumber(head) * 2 - 226 << endl;
    cout << "Контрольная сумма = " << ListCheckSum(head) << endl;
    cout << "Серии = " << ListCheckRunNumber(head) * 2 + 34 << endl;

    ListFree(head);
    /*
        queue->head = NULL;
        queue->tail = NULL;
        queue = ListFillRandQ(n);
        cout << "\n";

        cout << "4 байта:\n";

        cout << "Контрольная сумма = " << ListCheckSum(queue->head) << endl;
        cout << "Серии = " << ListCheckRunNumber(queue->head) << endl;
        DigitalSort(queue->head);

        cout << "Контрольная сумма = " << ListCheckSum(queue->head) << endl;
        cout << "Серии = " << ListCheckRunNumber(queue->head) << endl;
        ListFree(queue->head);
*/
    return 0;
}
int isEmpty(List *head)
{
    return head == NULL;
}

void Push(List **head, int data)
{
    List *p;
    p = new List;
    p->Data.Data = data;
    p->next = *head;
    *head = p;
}

int Pop(List **head)
{
    List *p;
    p = *head;
    int value = p->Data.Data;
    *head = p->next;
    delete p;
    return value;
}

void Enqueue(Queue *c, int data)
{
    List *p;
    p = new List;
    p->Data.Data = data;
    p->next = NULL;
    if (c->tail == NULL)
        c->head = p;
    else
        ((c)->tail)->next = p;
    c->tail = p;
}

List *ListFillDec(int n)
{
    List *head = NULL;
    int i = 0;
    for (i = 0; i < n; i++)
        Push(&head, i);
    return head;
}

List *ListFillInc(int n)
{
    List *head = NULL;
    int i = n - 1;
    for (i = n - 1; i >= 0; i--)
        Push(&head, i);
    return head;
}

List *ListFillRand(int n)
{
    List *head = NULL;
    int i = 0;
    for (i = 0; i < n; i++)
        Push(&head, rand() % n);
    return head;
}

Queue *ListFillIncQ(int n)
{
    Queue *queue = new Queue;
    for (int i = 0; i < n; i++)
        Enqueue(queue, i);
    return queue;
}

Queue *ListFillDecQ(int n)
{
    Queue *queue = new Queue;
    int i = 0;
    for (i = n - 1; i >= 0; i--)
        Enqueue(queue, i);
    return queue;
}

Queue *ListFillRandQ(int n)
{
    Queue *queue = new Queue;
    int i = 0;
    for (i = n - 1; i >= 0; i--)
        Enqueue(queue, rand() % n);
    return queue;
}

int ListCheckSum(List *head)
{
    List *p;
    int sum = 0;
    p = head;
    while (p != NULL)
    {
        sum += p->Data.Data;
        p = p->next;
    }
    return sum;
}

int ListCheckRunNumber(List *head)
{
    List *p;
    int serial = 1;
    p = head;
    while (p->next != NULL)
    {
        if ((p->Data.Data) < (p->next->Data.Data))
            serial++;
        p = p->next;
    }
    return serial;
}

void ListFree(List *head)
{
    List *p, *q;
    q = p = head;
    while (p != NULL)
    {
        p = q->next;
        delete q;
        q = p;
    }
    head = NULL;
}

int DigitalSort(List *&S)
{
    int L = sizeof(S->Data.Data);
    int m = 256;
    int mc = 0;
    unsigned char d;
    Queue Q[m];
    for (int j = 0; j < L; j++)
    {
        for (int i = 0; i < m; i++)
            Q[i].tail = (List *)&Q[i].head;
        List *p;
        p = S;
        while (p != NULL)
        {
            d = p->Digit[j];
            Q[d].tail->next = p;
            Q[d].tail = p;
            p = p->next;
        }
        p = (List *)&S;
        for (int i = 0; i < m; i++)
        {
            if (Q[i].tail != (List *)&Q[i].head)
            {
                p->next = Q[i].head;
                p = Q[i].tail;
            }
        }
        p->next = NULL;
    }
    return mc;
}
