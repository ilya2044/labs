#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void InsertSort(int x[], int n)
{
    int dp = 0, cp = 0, mp = 0;
    for (int i = 1; i < n; i++)
    {
        int elm = x[i];
        int num = i;
        while ((num > 0) && (x[num - 1] < elm))
        {
            cp++;
            x[num] = x[num - 1];
            num--;
            mp++;
        }
        x[num] = elm;
        mp++;
    }
}

void PrintMas(int x[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
    printf("\n");
}

void FillRand(int x[], int n)
{
    int i;
    for (i = n; i >= 0; i--)
    {
        x[i] = rand() % 100;
    }
}

int BruteForceSearch(int x[], int e, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (x[i] == e)
            return i;
    }
    return -1;
}

int BinarySearch(int x[], int e, int n)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        middle = (low + high) / 2;
        if (e > x[middle])
            high = middle - 1;
        else if (e < x[middle])
            low = middle + 1;
        else
            return middle;
    }
    return 0;
}

int main()
{
    int key, e;
    int *a, n, p;
    printf("Введите n \n");
    scanf("%i", &n);
    a = (int *)malloc(sizeof(int) * n);
    FillRand(a, n);
    InsertSort(a, n);
    PrintMas(a, n);

    printf("Способ? 1 = перебор 2 = бинарный \n");
    scanf("%i", &key);
    if (key == 1)
    {
        printf("Элемент, который ищем \n");
        scanf("%i", &e);
        p = BruteForceSearch(a, e, n);
        printf("Номер элемента %i", p);
    }
    if (key == 2)
    {
        printf("Элемент, который ищем \n");
        scanf("%i", &e);
        p = BinarySearch(a, e, n);
        if (p == 0)
        {
            printf("Не найден");
        }
        else
        {
            printf("Номер элемента %i", p);
        }
    }
}