#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100
#define Z 100
#define X 100
#define L 100
#define V 100
int M = 0, C = 0, T = 0, M2 = 0, C2 = 0, T2 = 0, M3 = 0, C3 = 0, T3 = 0, M4 = 0, C4 = 0, T4 = 0, M5 = 0, C5 = 0, T5 = 0;
void FillInc(int *, int);
void FillDec(int *, int);
void FillRand(int *, int);
int CheckSum(int *, int);
int RunNumber(int *, int);
void PrintMas(int *, int);
void BubbleSort(int *, int);
void BubbleSort2(int *, int);
void BubbleSort3(int *, int);
void BubbleSort4(int *, int);
void BubbleSort5(int *, int);
int main(void)
{
    int a[N], Mt = 0, Ct = 0, Tt = 0, count, sum, count1, sum1, count2, sum2, c[N], Mt2 = 0, Ct2 = 0, Tt2 = 0, Mt3 = 0, Ct3 = 0, Tt3 = 0, Mt4 = 0, Ct4 = 0, Tt4 = 0, Mt5 = 0, Ct5 = 0, Tt5 = 0;
    printf("\nВозрастающий массив:");
    FillInc(a, N);
    count = RunNumber(a, N);
    sum = CheckSum(a, N);
    PrintMas(a, N);
    printf("Кол-во серий: %d \n", count);
    printf("\nСумма элементов массива: %d \n", sum);
    printf("\n \n");
    printf("\nСортировка пузырьком: ");
    BubbleSort(a, N);
    BubbleSort2(a, Z);
    BubbleSort3(a, X);
    BubbleSort4(a, L);
    BubbleSort5(a, V);
    PrintMas(a, N);

    printf("\nУбывающий массив:");
    FillDec(a, N);
    count1 = RunNumber(a, N);
    sum1 = CheckSum(a, N);
    PrintMas(a, N);
    printf("Кол-во серий: %d \n", count1);
    printf("\nСумма элементов массива: %d \n", sum1);
    printf("\n \n");
    BubbleSort(a, N);
    BubbleSort2(a, Z);
    BubbleSort3(a, X);
    BubbleSort4(a, L);
    BubbleSort5(a, V);

    printf("\nРандомный массив:");
    FillRand(c, N);
    count2 = RunNumber(c, N);
    sum2 = CheckSum(c, N);
    PrintMas(c, N);
    BubbleSort(a, N);
    BubbleSort2(a, Z);
    BubbleSort3(a, X);
    BubbleSort4(a, L);
    BubbleSort5(a, V);
    printf("Кол-во серий: %d \n", count2);
    printf("\nСумма элементов массива: %d \n", sum2);
    int count3, sum3;
    count3 = RunNumber(c, N);
    sum3 = CheckSum(c, N);
    Mt = 3 * (100 - 1);
    Ct = (100 * 100 - 100) / 2;
    Tt = Mt + Ct;
    Mt2 = 3 * (200 - 1);
    Ct2 = (200 * 200 - 200) / 2;
    Tt2 = Mt2 + Ct2;
    Mt3 = 3 * (300 - 1);
    Ct3 = (300 * 300 - 300) / 2;
    Tt3 = Mt3 + Ct3;
    Mt4 = 3 * (400 - 1);
    Ct4 = (400 * 400 - 400) / 2;
    Tt4 = Mt4 + Ct4;
    Mt5 = 3 * (500 - 1);
    Ct5 = (500 * 500 - 500) / 2;
    Tt5 = Mt5 + Ct5;
    printf("\nТеоретическая\n");
    printf("M(T) = %d C(T) = %d T(T) = %d", Mt, Ct, Tt);
    printf("\nВозрастающие\n");
    printf("M = %d C = %d T = %d", M, C, T);
    printf("\nУбывающие\n");
    printf("M = %d C = %d T = %d", M, C, T);
    printf("\nСлучайные\n");
    printf("M = %d C = %d T = %d", M, C, T);

    printf("\n \n");
    printf("n          M + C Теоритич.             Мфакт + Сфакт");
    printf("\n                                 Убыв.     Случ.      Возр.");
    printf("\n100              %d             %d      %d      %d", Tt, T, T, T);
    printf("\n200              %d             %d      %d      %d", Tt2, T2, T2, T2);
    printf("\n300              %d             %d      %d      %d", Tt3, T3, T3, T3);
    printf("\n400              %d             %d      %d      %d", Tt4, T4, T4, T4);
    printf("\n500              %d             %d      %d      %d", Tt5, T5, T5, T5);

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

void Swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void BubbleSort(int A[], int n)
{
    int i, j;
    for (i = 0; i < 99; i++)
    {
        M += 3;
        for (j = 0; j < n - i - 1; j++)
        {
            C++;
            if (A[j] > A[j + 1])
                Swap(&A[j], &A[j + 1]);
        }
    }
    T = (M + C) / 3;
    printf("M = %d C = %d T = %d", M, C, T);
}

void BubbleSort2(int A[], int r)
{
    int i, j;
    r = 200;
    for (i = 0; i < r - 1; i++)
    {
        M2 += 3;
        for (j = 0; j < r - i - 1; j++)
        {
            C2++;
            if (A[j] > A[j + 1])
                Swap(&A[j], &A[j + 1]);
        }
    }
    T2 = (M2 + C2) / 3;
    printf("M = %d C = %d T = %d", M2, C2, T2);
}

void BubbleSort3(int A[], int q)
{
    q = 300;
    int i, j;
    for (i = 0; i < q - 1; i++)
    {
        M3 += 3;
        for (j = 0; j < q - i - 1; j++)
        {
            C3++;
            if (A[j] > A[j + 1])
                Swap(&A[j], &A[j + 1]);
        }
    }
    T3 = (M3 + C3) / 3;
    printf("M = %d C = %d T = %d", M3, C3, T3);
}

void BubbleSort4(int A[], int w)
{
    int i, j;
    w = 400;
    for (i = 0; i < w - 1; i++)
    {
        M4 += 3;
        for (j = 0; j < w - i - 1; j++)
        {
            C4++;
            if (A[j] > A[j + 1])
                Swap(&A[j], &A[j + 1]);
        }
    }
    T4 = (M4 + C4) / 3;
    printf("M = %d C = %d T = %d", M4, C4, T4);
}

void BubbleSort5(int A[], int e)
{
    int i, j;
    e = 500;
    for (i = 0; i < e - 1; i++)
    {
        M5 += 3;
        for (j = 0; j < e - i - 1; j++)
        {
            C5++;

            if (A[j] > A[j + 1])
                Swap(&A[j], &A[j + 1]);
        }
    }
    T5 = (M5 + C5) / 3;
    printf("M = %d C = %d T = %d", M5, C5, T5);
}