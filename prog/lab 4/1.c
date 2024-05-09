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

void FindMax(int **x, int m, int n, int *imax, int *jmax)
{
    int mx = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (x[i][j] > mx)
            {
                mx = x[i][j];
                *imax = i;
                *jmax = j;
            }
        }
    }
}

int main()
{
    int n = 5;
    int m;
    scanf("%i", &m);
    int **B = (int **)malloc(sizeof(int *) * m);
    for (int i = 0; i < m; i++)
    {
        B[i] = (int *)malloc(sizeof(int) * n);
    }
    FillRand(B, m, n);
    PrintMas(B, m, n);
    int imax = 0;
    int jmax = 0;
    FindMax(B, m, n, &imax, &jmax);
    int **C = (int **)malloc(sizeof(int *) * (m - 1));
    int k = 0;
    int l = 0;
    for (int i = 0; i < m - 1; i++)
    {
        C[i] = (int *)malloc(sizeof(int) * (n - 1));
    }
    for (int i = 0; i < m - 1; i++)
    {
        l = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (i != imax && j != jmax)
            {
                C[i][j] = B[i + k][j + l];
            }
            else
            {
                if (i == imax)
                {
                    k = 1;
                }
                if (j == jmax)
                {
                    l = 1;
                }
                C[i][j] = B[i + k][j + l];
            }
        }
    }
    PrintMas(C, m - 1, n - 1);
}
