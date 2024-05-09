#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define N 10
int M = 0, C = 0, T = 0;
void FillInc(int *, int);
void FillDec(int *, int);
void FillRand(int *, int);
int CheckSum(int *, int);
int RunNumber(int *, int);
void PrintMas(int *, int);
void SelectorSort(int *, int);
void SelectSort(int *, int);
int main(void)
{
    int a[N], Mt = 0, Ct = 0, Tt = 0, count, sum, count1, sum1, count2, sum2, c[N];
    printf("\nВозрастающий массив:");
    FillInc(a, N);
    count = RunNumber(a, N);
    sum = CheckSum(a, N);
    PrintMas(a, N);
    printf("Кол-во серий: %d \n", count);
    printf("\nСумма элементов массива: %d \n", sum);
    printf("\nОтсортированный массив: ");
    SelectSort(a, N);
    PrintMas(a, N);
    SelectorSort(a, N);
    printf("\n \n");

    printf("\nУбывающий массив:");
    FillDec(a, N);
    count1 = RunNumber(a, N);
    sum1 = CheckSum(a, N);
    PrintMas(a, N);
    printf("Кол-во серий: %d \n", count1);
    printf("\nСумма элементов массива: %d \n", sum1);
    printf("\nОтсортированный массив: ");
    SelectSort(a, N);
    PrintMas(a, N);
    SelectorSort(a, N);
    printf("\n \n");

    printf("\nРандомный массив:");
    FillRand(c, N);
    count2 = RunNumber(c, N);
    sum2 = CheckSum(c, N);
    PrintMas(c, N);
    printf("Кол-во серий: %d \n", count2);
    printf("\nСумма элементов массива: %d \n", sum2);
    printf("\nОтсортированный массив: \n");
    SelectSort(c, N);
    printf("\n \n");
    PrintMas(c, N);
    SelectorSort(c, N);
    int count3, sum3;
    count3 = RunNumber(c, N);
    sum3 = CheckSum(c, N);
    printf("\nКол-во серий в отсортированном массиве: %d \n", count3);
    printf("\nСумма элементов отсортированного массива: %d \n", sum3);

    Mt = 3 * (10 - 1);
    Ct = (10 * 10 - 10) / 2;
    Tt = Mt + Ct;
    printf("\nТеоретическая\n");
    printf("M(T) = %d C(T) = %d T(T) = %d", Mt, Ct, Tt);
    printf("\nВозрастающие\n");
    printf("M = %d C = %d T = %d", M, C, T);
    printf("\nУбывающие\n");
    printf("M = %d C = %d T = %d", M, C, T);
    printf("\nСлучайные\n");
    printf("M = %d C = %d T = %d", M, C, T);
    return 0;
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
        while (a[i] <= a[i + 1])
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

void SelectSort(int a[], int n)
{
    int i, j, k, temp;
    for (i = 0; i < n; i++)
    {
        k = i;
        for (j = i + 1; j < 10; j++)
        {
            if (a[j] < a[k])
                k = j;
        }
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
    }
}

void SelectorSort(int A[], int size)
{
    int i, j, k, temp;
    M = 0, C = 0, T = 0;
    for (i = 0; i < 9; i++)
    {
        k = i;
        for (j = i + 1; j < 10; j++)
        {
            C++;
            if (A[j] < A[k])
                k = j;
        }
        temp = A[i];
        A[i] = A[k];
        A[k] = temp;
        M += 3;
    }
    T = M + C;
    printf("M = %d C = %d T = %d", M, C, T);
}