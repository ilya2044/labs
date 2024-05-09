#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void FillRand(int **x, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            x[i][j] = rand() % 90 + 10;
        }
    }
}

void PrintMas(int **x, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%i ", x[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int n;
    int m;
    scanf("%i", &m);
    scanf("%i", &n);
    int **B = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        B[i] = (int *)malloc(sizeof(int) * n);
    }
    FillRand(B, m, n);
    PrintMas(B, m, n);

    int **C = (int **)malloc(sizeof(int *) * (m + 1));

    for (int i = 0; i < m + 1; i++)
    {
        C[i] = (int *)malloc(sizeof(int) * (n + 1));
    }
    int sumall = 0;
    for (int i = 0; i < m; i++)
    {
        int sumj = 0;
        for (int j = 0; j < n; j++)
        {
            C[i][j] = B[i][j];
            sumj += B[i][j];
            sumall += B[i][j];
            int sumi = 0;
            for (int q = 0; q < m; q++)
            {
                sumi += C[q][j];
            }
            C[n][j] = sumi;
        }
        C[i][m] = sumj;
    }
    C[n][m] = sumall;
    PrintMas(C, m + 1, n + 1);
}
