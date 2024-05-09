#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
    // printf("%d \n", a);
    return a;
}

int RunNumber(int *array, int n)
{
    int counter = 0;
    int arrayTwo[n + 1];
    for (int i = 0; i < n; i++)
    {
        arrayTwo[i] = array[i];
    }
    arrayTwo[n] = 0;
    for (int i = 0; i < n + 1; i++)
    {
        if (arrayTwo[i] > arrayTwo[i + 1])
            counter++;
    }
    // printf("\n %d \n", counter);
    return counter;
}

void SelectSort(int *array, int n)
{
    int min, temp;
    int c = 0;
    int m = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            c++;
            if (array[j] < array[min])
                min = j;
        }
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
        m += 3;
    }
    printf("M teor - %d, C teor - %d, M fact - %d, C fact - %d \n", 3 * (n - 1), (n * n - n) / 2, m, c);
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
    int c = 0;
    int m = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = (n - 1); j > i; j--)
        {

            if (array[j - 1] > array[j])
            {

                int temp = array[j - 1];
                array[j - 1] = array[j];
                array[j] = temp;
                m += 3;
            }
            c++;
        }
    }
    printf("\t%d", m + c);
}

void ShakerSort(int *array, int n)
{
    int i, j, step = 1, t, M = 0, C = 0, SMC = 0;
    // for (step=1; step<n/2; step++){
    for (int i = step; i < n; i++)
    {
        t = array[i];
        for (j = i; j >= step; j -= step)
        {
            C++;
            if (t < array[j - step])
            {
                array[j] = array[j - step];
                M += 3;
            }
            else
                break;
        }
        array[j] = t;
    }
    //}
    SMC = M + C;
    printf("\t%d", SMC);
}

int main()
{
    int z = 100, x = 200, v = 300, m = 400, n = 500;
    printf(" -----------------------------------------------------------\n");
    printf("|   | M + C|      Мф.+Сф. пузырьковая  |  Мф.+Сф. шейкерная |\n");
    printf("| n |      |---------------------------|--------------------|\n");
    printf("|   | Теор.|   Убыв.  |  Случ. |  Возр.| Убыв.| Случ.| Возр.|\n");
    printf("|-----------------------------------------------------------|\n");
    printf("|%d| %d| ", z, 3 * (z * z - z) / 4 + (z * z - z) / 2);
    int a[z];
    int b[z];
    int c[z];
    int ash[z], bsh[z], csh[z];
    FillDec(b, z, 100);
    BubbleSort(b, z);
    FillRand(c, z, 100);
    BubbleSort(c, z);
    FillInc(a, z, 100);
    BubbleSort(a, z);

    FillDec(bsh, z, 100);
    ShakerSort(bsh, z);
    FillRand(csh, z, 100);
    ShakerSort(csh, z);
    FillInc(ash, z, 100);
    ShakerSort(ash, z);
    printf("  |");

    printf("\n|%d| %d| ", x, 3 * (x * x - x) / 4 + (x * x - x) / 2);
    int d[x];
    int e[x];
    int f[x];
    int dsh[x], esh[x], fsh[x];
    FillDec(e, x, 200);
    BubbleSort(e, x);
    FillRand(f, x, 200);
    BubbleSort(f, x);
    FillInc(d, x, 200);
    BubbleSort(d, x);

    FillDec(esh, x, 200);
    ShakerSort(esh, x);
    FillRand(fsh, x, 200);
    ShakerSort(fsh, x);
    FillInc(dsh, x, 200);
    ShakerSort(dsh, x);
    printf(" |");

    printf("\n|%d|%d|", v, 3 * (v * v - v) / 4 + (v * v - v) / 2);
    int g[v];
    int h[v];
    int i[v];
    int gsh[v], hsh[v], ish[v];
    FillDec(h, v, 300);
    BubbleSort(h, v);
    FillRand(i, v, 300);
    BubbleSort(i, v);
    FillInc(g, v, 300);
    BubbleSort(g, v);

    FillDec(hsh, v, 300);
    ShakerSort(hsh, v);
    FillRand(ish, v, 300);
    ShakerSort(ish, v);
    FillInc(gsh, v, 300);
    ShakerSort(gsh, v);
    printf(" |");

    printf("\n|%d|%d|", m, 3 * (m * m - m) / 4 + (m * m - m) / 2);
    int j[m];
    int k[m];
    int l[m];
    int jsh[m], ksh[m], lsh[m];
    FillDec(k, m, 400);
    BubbleSort(k, m);
    FillRand(l, m, 400);
    BubbleSort(l, m);
    FillInc(j, m, 400);
    BubbleSort(j, m);

    FillDec(ksh, m, 400);
    ShakerSort(ksh, m);
    FillRand(lsh, m, 400);
    ShakerSort(lsh, m);
    FillInc(jsh, m, 400);
    ShakerSort(jsh, m);
    printf(" |");

    printf("\n|%d|%d|", n, 3 * (n * n - n) / 4 + (n * n - n) / 2);
    int o[n];
    int p[n];
    int q[n];
    int osh[n], psh[n], qsh[n];
    FillDec(p, n, 500);
    BubbleSort(p, n);
    FillRand(q, n, 500);
    BubbleSort(q, n);
    FillInc(o, n, 500);
    BubbleSort(o, n);

    FillDec(psh, n, 500);
    ShakerSort(psh, n);
    FillRand(qsh, n, 500);
    ShakerSort(qsh, n);
    FillInc(osh, n, 500);
    ShakerSort(osh, n);
    printf(" |");
    printf("\n ------------------------------------------------------------\n");
}