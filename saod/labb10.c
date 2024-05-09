#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int *A;
int *M = 0;
int *C = 0;

void swap(int *a, int *b)
{

    int temp = *a;
    *a = *b;
    *b = temp;
}

int control_summ(int *A, int n)
{
    int i;
    int summ = 0;
    for (i = 0; i < n; i++)
    {

        summ += A[i];
    }
    return summ;
}

int control_series(int *A, int n)
{
    int i;
    int k = 1;
    for (i = 0; i < n - 1; i++)
    {

        if (A[i] <= A[i + 1])
        {

            continue;
        }

        k += 1;
    }

    return k;
}

void direct_inclusion_sort(int *A, int n, int *M, int *C)
{
    int i, j, t;
    for (i = 1; i < n; i++)
    {
        *M += 1;
        t = A[i];
        j = i - 1;
        *C += 2;
        while (j >= 0 && t < A[j])
        {
            *M += 1;
            A[j + 1] = A[j];
            j = j - 1;
            *C += 2;
        }
        *M += 1;
        A[j + 1] = t;
    }
}

void quick_sort(int *A, int L, int n, int *M, int *C)
{
    int R = n;
    *M += 1;
    int x = A[L];
    int i = L;
    int j = R;

    while (i <= j)
    {
        *C += 1;
        while (A[i] < x)
        {
            i++;
            *C += 1;
        }
        //        *C += 1;
        while (A[j] > x)
        {
            j--;
            *C += 1;
        }
        if (i <= j)
        {
            *M += 3;
            swap(&A[i], &A[j]);
            i++;
            j--;
        }
    }
    if (L < j)
        quick_sort(A, L, j, M, C);
    if (i < R)
        quick_sort(A, i, R, M, C);
}

void array_random(int *A, int n)
{
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {

        A[i] = rand() % n;
    }
}
void array_descending(int *A, int n)
{

    int i, j = 100;
    for (i = 0; i < n; i++)
    {

        A[i] = j;
        j -= 4;
    }
}
void array_growing(int *A, int n)
{

    int i, j = 0;
    for (i = 0; i < n; i++)
    {

        A[i] = j;
        j += 7;
    }
}
void array_print(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {

        printf(" %d", A[i]);
    }
    printf("\n");
}

void printa(int *A, int n, int *M, int *C)
{
    printf("Quick_sort\n------------------------------------------------------\n");
    array_random(A, n);
    printf("Random array:");
    array_print(A, n);
    printf("Control summ: %d\n", control_summ(A, n));
    printf("Series: %d\n", control_series(A, n));
    printf("\n");

    quick_sort(A, 0, n - 1, M, C);
    printf("Sorted array:");
    array_print(A, n);
    printf("Control summ: %d\n", control_summ(A, n));
    printf("Series: %d\n", control_series(A, n));
    printf("\n");

    printf("Theory M = %d, C = %d\n", (3 * (n - 1)), ((n * n + 5 * n + 4) / 2));
    printf("My M: %d, C: %d, M + C: %d\n", *M, *C, *M + *C);
    *M = 0;
    *C = 0;
    printf("\n");
    printf("------------------------------------------------------");
    printf("\n");

    array_descending(A, n);
    printf("Descending array:");
    array_print(A, n);
    printf("Control summ: %d\n", control_summ(A, n));
    printf("Series: %d\n", control_series(A, n));
    printf("\n");

    quick_sort(A, 0, n - 1, M, C);
    printf("Sorted array:");
    array_print(A, n);
    printf("Control summ: %d\n", control_summ(A, n));
    printf("Series: %d\n", control_series(A, n));
    printf("\n");

    printf("Theory M = %d, C = %d\n", (3 * (n - 1)), ((n * n + 5 * n + 4) / 2));
    printf("My M: %d, C: %d, M + C: %d\n", *M, *C, *M + *C);
    *M = 0;
    *C = 0;
    printf("\n");
    printf("------------------------------------------------------");
    printf("\n");

    array_growing(A, n);
    printf("Growing array:");
    array_print(A, n);
    printf("Control summ: %d\n", control_summ(A, n));
    printf("Series: %d\n", control_series(A, n));
    printf("\n");

    quick_sort(A, 0, n - 1, M, C);
    printf("Sorted array:");
    array_print(A, n);
    printf("Control summ: %d\n", control_summ(A, n));
    printf("Series: %d\n", control_series(A, n));
    printf("\n");

    printf("Theory M = %d, C = %d\n", (3 * (n - 1)), ((n * n + 5 * n + 4) / 2));
    printf("My M: %d, C: %d, M + C: %d\n", *M, *C, *M + *C);
    *M = 0;
    *C = 0;
    printf("\n");
    printf("------------------------------------------------------");
    printf("\n");
}

int main()
{
    int n, i;

    M = calloc(1, sizeof(int));
    C = calloc(1, sizeof(int));

    A = calloc(n, sizeof(int));

    printf("--------------------------------------------\n");
    printf("|   |          Мф.+Сф. QuickSort           |\n");
    printf("| n |--------------------------------------|\n");
    printf("|   |    Убыв.   |    Возр.   |    Случ.   |\n");
    printf("|------------------------------------------|\n");
    for (i = 100; i <= 500; i += 100)
    {
        printf("|%d", i);
        printf("|");
        array_growing(A, i);
        quick_sort(A, 0, i - 1, M, C);
        if (*M + *C < 9999)
            printf("    %d    |      ", *M + *C);
        else if (*M + *C > 9999 && *M + *C < 100000)
            printf("   %d    |      ", *M + *C);
        else if (*M + *C > 99999 && *M + *C < 1000000)
            printf("  %d    |      ", *M + *C);
        *M = 0;
        *C = 0;

        array_descending(A, i);
        quick_sort(A, 0, i - 1, M, C);
        if (*M + *C < 9999)
            printf("%d  |\t", *M + *C);
        else if (*M + *C > 9999 && *M + *C < 100000)
            printf("%d |\t", *M + *C);
        else if (*M + *C > 99999 && *M + *C < 1000000)
            printf("%d|\t", *M + *C);

        *M = 0;
        *C = 0;

        array_random(A, i);
        quick_sort(A, 0, i - 1, M, C);
        if (*M + *C < 9999)
            printf("  %d     |\t", *M + *C);
        else if (*M + *C > 9999 && *M + *C < 100000)
            printf(" %d     |\t", *M + *C);
        else if (*M + *C > 99999 && *M + *C < 1000000)
            printf("%d     |\t", *M + *C);

        *M = 0;
        *C = 0;

        printf("\n");
    }
    printf("--------------------------------------------");
    printf("\n");
    free(A);
    free(M);
    free(C);
    return 0;
}