#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

void FillRand(int x[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        x[i] = rand() % 101 - 50;
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

int Positive(int x[], int n)
{
    int i, m = 0;
    for (i = 0; i < n; i++)
    {
        if (x[i] > -1)
            m += 1;
    }
    return m;
}

void FillPos(int x[], int c[], int n)
{
    int i, h = 0;
    for (i = 0; i < n; i++)
    {
        if (x[i] > -1)
            c[h++] = x[i];
    }
}

void FillNeg(int x[], int d[], int n)
{
    int i, h = 0;
    for (i = 0; i < n; i++)
    {
        if (x[i] < 0)
            d[h++] = x[i];
    }
}

int main()
{
    int *b, *c, *d, n, m, k;
    scanf("%i", &n);
    b = (int *)malloc(sizeof(int) * n);
    FillRand(b, n);
    PrintMas(b, n);
    m = Positive(b, n);
    k = n - m;
    printf("%d положительных \n", m);
    printf("%d отрицательных \n", k);
    c = (int *)malloc(sizeof(int) * m);
    d = (int *)malloc(sizeof(int) * k);
    FillPos(b, c, n);
    PrintMas(c, m);
    FillNeg(b, d, n);
    PrintMas(d, k);
    free(b);
    free(c);
    free(d);
}
