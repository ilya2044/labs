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
void SelectSort(int *, int);
int main(void)
{
    int a[N], cnt1, cnt2, sum, Mt = 0, Ct = 0, Tt = 0;

    printf("Vozrastaushee");
    FillInc(a, N);
    PrintMas(a, N);
    SelectSort(a, N);
    printf("Sortirovka \n");
    PrintMas(a, N);
    cnt1 = RunNumber(a, N);
    printf("Serii = %d\n", cnt1);
    sum = CheckSum(a, N);
    printf("Summa = %d\n", sum);
    printf("\n");

    printf("Ubivaushie");
    FillDec(a, N);
    PrintMas(a, N);
    SelectSort(a, N);
    printf("Sortirovka \n");
    PrintMas(a, N);
    cnt2 = RunNumber(a, N);
    printf("serii = %d\n", cnt2);
    sum = CheckSum(a, N);
    printf("Summa = %d\n", sum);
    printf("\n");

    printf("Sluchainie");
    FillRand(a, N);
    PrintMas(a, N);
    SelectSort(a, N);
    printf("Sortirovka \n");
    PrintMas(a, N);
    sum = CheckSum(a, N);
    printf("Summa = %d\n", sum);

    Mt = 3 * (10 - 1);
    Ct = (10 * 10 - 10) / 2;
    Tt = Mt + Ct;
    printf("Teoria\n");
    printf("M(T)=%d C(T)=%d T(T)=%d", Mt, Ct, Tt);
    printf("\nVozrastaushee\n");
    printf("M= %d C= %d T= %d", M, C, T);
    printf("\nUbivaushie\n");
    printf("M= %d C= %d T= %d", M, C, T);
    printf("\nSluchainie\n");
    printf("M= %d C= %d T= %d", M, C, T);
    return 0;
}

void FillInc(int *a, int size)
{
    for (int i = 0; i < size; i++)
        a[i] = i;
}

void FillDec(int *a, int size)
{
    for (int i = 0; i < size; i++)
        a[i] = N - i;
}

void FillRand(int *a, int size)
{
    srand((unsigned int)time(NULL) / 2);
    for (int i = 0; i < size; i++)
        a[i] = rand() % 100;
}

int CheckSum(int *a, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum = sum + a[i];
    return sum;
}

int RunNumber(int a[], int size)
{
    int k, count = 0;
    for (int i = 0; i < size; i++, count++)
    {
        for (k = 1; k < size - i && a[i + k - 1] < a[i + k]; k++)
            ;
        i += k - 1;
    }
    return count;
}

void SelectSort(int A[], int size)
{
    int i, j, k, temp;
    M = 0, C = 0, T = 0;
    for (i = 0; i < 10; i++)
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
        M = M + 3;
    }
    T = M + C;
    printf("M= %d C= %d T= %d", M, C, T);
}

void PrintMas(int *a, int size)
{
    for (int i = 0; i < size; i++)
        printf(" %d", a[i]);
    puts("\n");
}