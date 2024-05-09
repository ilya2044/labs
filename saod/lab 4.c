#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void FillInc(int *array, int n, int max);
void FillDec(int *array, int n, int max);
void FillRand(int *array, int n, int max);
int CheckSum(int *array, int n);
int RunNumber(int *array, int n);
void BubbleSort(int *array, int n);
void ShakerSort(int *array, int n);

int main()
{
    int z = 100, x = 200, v = 300, m = 400, n = 500, array[];
    printf("------------------------------------\n");
    printf("|   | M + C   |     Мфакт  +  Сфакт|\n");
    printf("| n |         |--------------------|\n");
    printf("|   |Теоретич.| Убыв.| Случ.| Возр.|\n");
    printf("|----------------------------------|\n");
    printf("|%d | %d   |   ", z, 3 * (z * z - z) / 4 + (z * z - z) / 2);
    int a[z];
    int b[z];
    int c[z];
    FillDec(b, z, 100);
    BubbleSort(b, z);
    FillRand(c, z, 100);
    BubbleSort(c, z);
    FillInc(a, z, 100);
    BubbleSort(a, z);
    printf("\n------------------------------------");

    printf("\n|%d|   %d   | ", x, 3 * (x * x - x) / 4 + (x * x - x) / 2);
    int d[x];
    int e[x];
    int f[x];
    FillDec(e, x, 200);
    BubbleSort(e, x);
    FillRand(f, x, 200);
    BubbleSort(f, x);
    FillInc(d, x, 200);
    BubbleSort(d, x);
    printf("\n------------------------------------");

    printf("\n|%d|   %d |", v, 3 * (v * v - v) / 4 + (v * v - v) / 2);
    int g[v];
    int h[v];
    int i[v];
    FillDec(h, v, 300);
    BubbleSort(h, v);
    FillRand(i, v, 300);
    BubbleSort(i, v);
    FillInc(g, v, 300);
    BubbleSort(g, v);
    printf("\n------------------------------------");

    printf("\n|%d|  %d  |", m, 3 * (m * m - m) / 4 + (m * m - m) / 2);
    int j[m];
    int k[m];
    int l[m];
    FillDec(k, m, 400);
    BubbleSort(k, m);
    FillRand(l, m, 400);
    BubbleSort(l, m);
    FillInc(j, m, 400);
    BubbleSort(j, m);
    printf("\n------------------------------------");

    printf("\n|%d|  %d |", n, 3 * (n * n - n) / 4 + (n * n - n) / 2);
    int o[n];
    int p[n];
    int q[n];
    FillDec(p, n, 500);
    BubbleSort(p, n);
    FillRand(q, n, 500);
    BubbleSort(q, n);
    FillInc(o, n, 500);
    BubbleSort(o, n);
    printf("\n------------------------------------\n");

    printf("\nРандомный массив:");
    FillRand(array, n);
    PrintMas(array, n);
    ShakerSort(array, n)
}

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

void FillRand(int *array, int n, int max)
{
    srand((unsigned int)time(NULL) / 2);
    for (size_t i = 0; i < n; i++)
    {
        array[i] = rand() % n;
    }
}

int CheckSum(int *array, int n)
{
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        a += array[i];
    }
    return a;
}

int RunNumber(int *array, int n)
{
    int cnt = 0;
    int arrTwo[n + 1];
    for (int i = 0; i < n; i++)
    {
        arrTwo[i] = array[i];
    }
    arrTwo[n] = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (arrTwo[i] > arrTwo[i + 1])
            cnt++;
    }
    return cnt;
}

void PrintMas(int *array, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void BubbleSort(int *array, int n)
{
    int C = 0;
    int M = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = (n - 1); j > i; j--)
        {

            if (array[j - 1] > array[j])
            {

                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
                M += 3;
            }
            C++;
        }
    }
    printf("%d|", M + C);
}

void ShakerSort(int *array, int n)
{
    int tmp = 0, high = 0, low = (n - 1);
    while (high < low)
    {
        for (int i = high; i < low; i++)
        {
            if (array[i] > array[i + 1])
            {
                tmp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = tmp;
            }
        }
        low--;

        for (int j = low; j > high; j--)
        {
            if (array[j] < array[j - 1])
            {

                array = array[j];
                array[j] = array[j - 1];
                array[j - 1] = tmp;
            }
        }
        high++;
    }
}
