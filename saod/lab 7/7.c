#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void FillRand(int *array, int n, int max)
{
    srand((unsigned int)time(NULL) / 2);
    for (size_t i = 0; i < n; i++)
    {
        array[i] = rand() % n;
    }
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
}

BSearch1(int *a, int n, int X)
{
    int L = 0, R = n, m, T, M = 0, C = 0;
    while (L <= R)
    {
        m = (L + R) / 2;
        C++;
        if (a[m] = X)
        {
            break;
        }
        C++;
        if (a[m] < X)
            L = m + 1;
        else
            R = m - 1;

        T = C;
    }
    printf("%d|\n", T);
}

BSearch2(int *a, int n, int X)
{
    int L = 0, R = n, m, T, M = 0, C = 0;
    while (L < R)
    {
        m = (L + R) / 2;
        C++;
        if (a[m] < X)
            L = m + 1;
        else
            R = m;
    }
    C++;
    if (a[R] == X)
    {
    }
    T = C;
    printf("%d|", T);
}
int main()
{
    int z = 100, x = 200, v = 300, m = 400, n = 500, o = 600, l = 700, u = 800, f = 900, q = 1000;
    int xx = 5;
    int idx1, idx2;
    int cnt1 = 0, cnt2 = 0;
    printf("-----------------------------------------------|\n");
    printf("|  N  |      BSearch1      |      BSearch2     |");
    printf("\n");
    printf("-----------------------------------------------|\n");
    printf("|%d  |", z);

    int a[z];
    int b[z];
    FillRand(a, z, 100);
    Shellsort(a, z);
    BSearch1(a, z, 100);
    BSearch2(b, z, 100);

    printf("|%d  |", x);

    int aa[x];
    int bb[x];
    FillRand(aa, x, 200);
    Shellsort(aa, x);
    BSearch1(aa, x, 200);
    BSearch2(bb, x, 200);

    printf("|%d  |", v);

    int aaa[v];
    int bbb[v];
    FillRand(aaa, v, 300);
    Shellsort(aaa, v);
    BSearch1(aaa, v, 300);
    BSearch2(bbb, v, 300);

    printf("|%d  |", m);

    int aaaa[m];
    int bbbb[m];
    FillRand(aaaa, m, 400);
    Shellsort(aaaa, m);
    BSearch1(aaaa, m, 400);
    BSearch2(bbbb, m, 400);

    printf("|%d  |", n);

    int aaaaa[n];
    int bbbbb[n];
    FillRand(aaaaa, n, 500);
    Shellsort(aaaaa, n);
    BSearch1(aaaaa, n, 500);
    BSearch2(bbbbb, n, 500);

    printf("|%d  |", o);

    int aaaaaa[o];
    int bbbbbb[o];
    FillRand(aaaaaa, o, 600);
    Shellsort(aaaaaa, o);
    BSearch1(aaaaaa, o, 600);
    BSearch2(bbbbbb, o, 600);

    printf("|%d  |", l);

    int aaaaaaa[l];
    int bbbbbbb[l];
    FillRand(aaaaaaa, l, 700);
    Shellsort(aaaaaaa, l);
    BSearch1(aaaaaaa, l, 700);
    BSearch2(bbbbbbb, l, 700);

    printf("|%d  |", u);

    int aaaaaaaa[u];
    int bbbbbbbb[u];
    FillRand(aaaaaaaa, u, 800);
    Shellsort(aaaaaaaa, u);
    BSearch1(aaaaaaaa, u, 800);
    BSearch2(bbbbbbbb, u, 800);

    printf("|%d  |", f);

    int aaaaaaaaa[f];
    int bbbbbbbbb[f];
    FillRand(aaaaaaaaa, f, 900);
    Shellsort(aaaaaaaaa, f);
    BSearch1(aaaaaaaaa, f, 900);
    BSearch2(bbbbbbbbb, f, 900);

    printf("|%d  |", q);

    int aaaaaaaaaa[q];
    int bbbbbbbbbb[q];
    FillRand(aaaaaaaaaa, q, 1000);
    Shellsort(aaaaaaaaaa, q);
    BSearch1(aaaaaaaaaa, q, 1000);
    BSearch2(bbbbbbbbbb, q, 1000);

    printf("------------------------------------------------|");

    return 0;
}
