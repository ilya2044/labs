#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int X, T, M = 0, C = 0, A[500], F1[500], F[500], T1 = 0;
void FillRand(int *arr, int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 10;
    }
}
void FillInc(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
}
void PrintMas(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%2d", A[i]);
    }
}
void FillDec(int *arr, int n)
{
    int b = n;
    for (int i = 0; i < n; i++)
    {
        arr[i] = b - 1;
        b = b - 1;
    }
}
int InsSort(int *a, int n)
{
    int k, M = 0, C = 0;
    for (int i = 1; i < n; i++)
    {
        k = a[i];
        int j = i - 1;
        M += 1;
        int f = 0; // C++;
        while (j >= 0 and k < a[j])
        {
            a[j + 1] = a[j];
            j--;
            M++;
            C++;
            f = 1;
        }
        if (f == 0)
            C++;
        a[j + 1] = k;
        M++;
    }
    int T = M + C;
    return T;
}

int BSearch1(int *a, int n, int X)
{
    int L = 0, R = n, m;
    while (L <= R)
    {
        m = (L + R) / 2;
        C++;
        if (a[m] == X)
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
    return T;
}

int BSearch2(int *a, int n, int X)
{
    int L = 0, R = n, m;
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
    return T;
}

int vivod(int B[], int n)
{
    int k = log2(n), g;
    if (n > 999)
    {
        printf("|%d|\t%d   |", n, k);
    }
    else
    {
        printf("|%d |\t%d   |", n, k);
    }

    M = 0, C = 0;
    FillRand(A, n);
    for (int i = 0; i < n; i++)
        F[i] = A[i];
    M = 0, C = 0;
    T = InsSort(F1, n);

    M = 0, C = 0;
    g = rand() % 10;

    T = BSearch1(F, n, g);
    M = 0, C = 0;
    if (T > 9)
    {
        printf("\t%d   |", T);
    }
    else
    {
        printf("\t%d    |", T);
    }
    T = BSearch2(F1, n, g);
    if (T > 9)
    {
        printf("\t%d     |\n", T);
    }
    else
    {
        printf("\t%d      |\n", T);
    }
    return T;
}
int main()
{
    printf("--------------------------------\n");
    printf("|N   | teor |BSearch1 |BSearch2|\n");
    printf("--------------------------------\n");
    T1 = vivod(A, 100);
    T1 = vivod(A, 200);
    T1 = vivod(A, 300);
    T1 = vivod(A, 400);
    T1 = vivod(A, 500);
    T1 = vivod(A, 600);
    T1 = vivod(A, 700);
    T1 = vivod(A, 800);
    T1 = vivod(A, 900);
    T1 = vivod(A, 1000);
    printf("--------------------------------\n");
    return 0;
}
