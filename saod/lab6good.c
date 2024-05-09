#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void FillRand(int *array, int n, int max)
{
    srand((unsigned int)time(NULL) / 2);
    for (size_t i = 0; i < n; i++)
    {
        array[i] = rand() % n;
    }
}

void InsertSort(int *array, int n)
{
    int t, i, j, c = 0, m = 0;
    for (i = 1; i < n; i++)
    {
        t = array[i];
        j = i - 1;
        c++;
        while (j >= 0 && t < array[j])
        {
            c++;
            m++;
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = t;
    }
    printf("   %d\t       |", m + c);
}

int Shellsort(int *array, int n)
{
    int h = 2, i, j, temp, k, t, m = 0, c = 0;
    for (k = h; k > 0; k--)
    {
        for (i = k; i < n; i++)
        {
            t = array[i];
            j = i - k;
            c++;
            while (j >= 0 && t < array[j])
            {
                c++;
                temp = array[j + k];
                array[j + k] = array[j];
                array[j] = temp;
                j = j - k;
            }
            m += 3;
            t = array[j + k];
        }
    }
    printf("\t %d    |\n", m + c);
}

int main()
{
    int z = 100, x = 200, v = 300, m = 400, n = 500, ksort1 = 5, ksort2 = 6, ksort3 = 6, ksort4 = 6, ksort5 = 7;

    printf("-------------------------------------------------------------------------|\n");
    printf("|  N  |   Количество К-сортировок   |   Insert Мф+Сф   |   Shell Мф+Сф   |");
    printf("\n");
    printf("-------------------------------------------------------------------------|\n");
    printf("|%d  |\t \t%d\t\t    |", z, ksort1);

    int a[z];
    int b[z];
    FillRand(a, z, 100);
    InsertSort(a, z);
    FillRand(b, z, 100);
    Shellsort(b, z);

    printf("|%d  |\t \t%d\t\t    |", x, ksort2);

    int aa[x];
    int bb[x];
    FillRand(aa, x, 200);
    InsertSort(aa, x);
    FillRand(bb, x, 200);
    Shellsort(bb, x);

    printf("|%d  |\t \t%d\t\t    |", v, ksort3);

    int aaa[v];
    int bbb[v];
    FillRand(aaa, v, 300);
    InsertSort(aaa, v);
    FillRand(bbb, v, 300);
    Shellsort(bbb, v);

    printf("|%d  |\t \t%d\t\t    |", m, ksort4);

    int aaaa[m];
    int bbbb[m];
    FillRand(aaaa, m, 400);
    InsertSort(aaaa, m);
    FillRand(bbbb, m, 400);
    Shellsort(bbbb, m);

    printf("|%d  |\t \t%d\t\t    |", n, ksort5);

    int aaaaa[n];
    int bbbbb[n];
    FillRand(aaaaa, n, 500);
    InsertSort(aaaaa, n);
    FillRand(bbbbb, n, 500);
    Shellsort(bbbbb, n);

    printf("-------------------------------------------------------------------------|");

    return 0;
}