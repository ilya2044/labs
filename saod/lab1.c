#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
void FillInc(int *, int);
void FillDec(int *, int);
void FillRand(int *, int);
int CheckSum(int *, int);
int RunNumber(int *, int);
void PrintMas(int *, int);
int main(void)
{
    int a[N], count, sum, count1, sum1, count2, sum2, c[N];
    printf("\nВозрастающий массив:");
    FillInc(a, N);
    count = RunNumber(a, N);
    sum = CheckSum(a, N);
    PrintMas(a, N);
    printf("Кол-во серий: %d \n", count);
    printf("\nСумма элементов массива: %d \n", sum);

    printf("\nУбывающий массив:");
    FillDec(a, N);
    count1 = RunNumber(a, N);
    sum1 = CheckSum(a, N);
    PrintMas(a, N);
    printf("Кол-во серий: %d \n", count1);
    printf("\nСумма элементов массива: %d \n", sum1);

    printf("\nРандомный массив:");
    FillRand(c, N);
    count2 = RunNumber(c, N);
    sum2 = CheckSum(c, N);
    PrintMas(c, N);
    printf("Кол-во серий: %d \n", count2);
    printf("\nСумма элементов массива: %d \n", sum2);
}

void FillInc(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = i;
    }
}

void FillDec(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = n - i;
    }
}

void FillRand(int *c, int n)
{
    srand((unsigned int)time(NULL) / 2);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        c[i] = rand() % 100;
    }
}

int CheckSum(int *a, int n)
{
    int sum = 0;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        sum += a[i];
    }
    return sum;
}

int RunNumber(int a[], int n)
{
    int serii = 0;
    for (int i = 0; i < n; i++)
    {
        while (a[i] < a[i + 1])
        {
            i++;
        }
        serii++;
    }
    return serii;
}

void PrintMas(int *a, int n)
{
    for (int i = 0; i < n; i++)
        printf(" %d", a[i]);
    puts("\n");
}