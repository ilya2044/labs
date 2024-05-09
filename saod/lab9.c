#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
int M = 0, C = 0, T;

void FillInc(int *array, int n, int max)
{
    int step = max / n;
    for (int i = 0; i < n; i++)
    {
        array[i] = (step * (i + 1));
    }
}

void FillDec(int *array, int n, int max)
{
    int step = max / n;
    for (int i = 0; i < n; i++)
    {
        array[i] = (max - (step * (i)));
    }
}

void FillRand(int *arr, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10;
    }
}

void PrintMas(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int do_heap(int *A, int L, int R)
{
    int M = 0;
    int C = 0;
    L = L - 1;
    M += 1;
    int x = A[L];
    int i = L;
    int j;

    while (1)
    {
        j = 2 * i;
        if (j > R)
            break;
        C += 1;
        if ((j < R) && (A[j + 1] <= A[j]))
            j = j + 1;
        C += 1;
        if (x <= A[j])
            break;
        M += 1;
        A[i] = A[j];
        i = j;
    }

    M += 1;
    A[i] = x;
    return (M + C);
}
void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}
void HeapSort(int *A, int n)
{
    int L = (n / 2);
    int R;
    int HMC = 0;

    while (L > 0)
    {
        HMC += (do_heap(A, L, n - 1));
        L = L - 1;
    }

    R = n - 1;

    while (R >= 1)
    {
        HMC += 3;
        swap(&A[0], &A[R]);
        R = R - 1;
        HMC += (do_heap(A, 1, R));
    }
    if (HMC < 1000)
    {
        printf("   %d      |", HMC);
    }
    else if ((HMC > 1000) && (HMC < 9999))
    {
        printf("   %d     |", HMC);
    }
    else if (HMC > 9999)
    {
        printf("   %d    |", HMC);
    }
}

main()
{
    int z = 100, x = 200, v = 300, m = 400, n = 500;
    printf("--------------------------------------------\n");
    printf("|   |          Мф.+Сф. HeapSort            |\n");
    printf("| n |--------------------------------------|\n");
    printf("|   |    Убыв.   |    Случ.   |    Возр.   |\n");
    printf("|------------------------------------------|\n");
    printf("|%d|", z);
    int a[z];
    int b[z];
    int c[z];
    int ash[z], bsh[z], csh[z];
    FillDec(b, z, 100);
    HeapSort(b, z);
    FillRand(c, z);
    HeapSort(c, z);
    FillInc(a, z, 100);
    HeapSort(a, z);

    printf("\n|%d|", x);
    int d[x];
    int e[x];
    int f[x];
    FillDec(e, x, 200);
    HeapSort(e, x);
    FillRand(f, x);
    HeapSort(f, x);
    FillInc(d, x, 200);
    HeapSort(d, x);

    printf("\n|%d|", v);
    int g[v];
    int h[v];
    int i[v];
    FillDec(h, v, 300);
    HeapSort(h, v);
    FillRand(i, v);
    HeapSort(i, v);
    FillInc(g, v, 300);
    HeapSort(g, v);

    printf("\n|%d|", m);
    int j[m];
    int k[m];
    int l[m];
    FillDec(k, m, 400);
    HeapSort(k, m);
    FillRand(l, m);
    HeapSort(l, m);
    FillInc(j, m, 400);
    HeapSort(j, m);

    printf("\n|%d|", n);
    int o[n];
    int p[n];
    int q[n];
    FillDec(p, n, 500);
    HeapSort(p, n);
    FillRand(q, n);
    HeapSort(q, n);
    FillInc(o, n, 500);
    HeapSort(o, n);

    printf("\n--------------------------------------------\n");
}