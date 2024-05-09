#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

void FillRand(int *x, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        x[i] = rand() % 1000 + 1;
    }
}

void PrintMas(int *x, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", x[i]);
    }
}

int CheckSum(int *a, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += a[i];
    return sum;
}

int RunNumber(int *a, int size)
{
    int count = 1;
    for (int i = 1; i < size; i++)
    {
        count = (a[i] < a[i - 1]) ? count + 1 : count;
    }
    return count;
}

void shakerSort(int *mass, int count, int &M, int &C)
{
    C = 0, M = 0;
    int left = 0, right = count - 1;
    int flag = 1;
    while ((left < right) && flag > 0)
    {
        flag = 0;
        for (int i = left; i < right; i++)
        {
            C++;
            if (mass[i] > mass[i + 1])
            {
                double t = mass[i];
                mass[i] = mass[i + 1];
                mass[i + 1] = t;
                flag = 1;
                M = M + 3;
            }
        }
        right--;
        for (int i = right; i > left; i--)
        {
            C++;
            if (mass[i - 1] > mass[i])
            {
                double t = mass[i];
                mass[i] = mass[i - 1];
                mass[i - 1] = t;
                flag = 1;
                M = M + 3;
            }
        }
        left++;
    }
}

void bubbleSort(int *array, int size, int &flag1, int &flag2)
{
    flag1 = 0, flag2 = 0;
    for (int step = 0; step < size - 1; ++step)
    {
        for (int i = 0; i < size - step - 1; ++i)
        {
            flag1++;
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                flag2 = flag2 + 3;
            }
        }
    }
}

void insertionSort(int *array, int size, int &flag1, int &flag2)
{
    flag1 = 0, flag2 = 0;
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
            flag1++;
            flag2 = flag2 + 1;
        }
        array[j + 1] = key;
    }
}

void selectionSort(int *num, int size, int &flag1, int &flag2)
{
    flag1 = 0, flag2 = 0;
    int min, temp;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            flag1 = flag1 + 1;
            if (num[j] < num[min])
                min = j;
        }
        temp = num[i];
        num[i] = num[min];
        num[min] = temp;
        flag2 = flag2 + 3;
    }
}

int main()
{
    // setlocale(LC_ALL, "rus");
    int *arr, N, M2, C2, M, C, M3, C3, C4, M4, a, b;

    N = 100;
    arr = new int[N];

    FillRand(arr, N);
    PrintMas(arr, N);
    printf("\nКонтрольная сумма : %d", CheckSum(arr, N));
    printf("\nКол-во серий : %d", RunNumber(arr, N));
    printf("\n\n");

    insertionSort(arr, N, a, b);
    PrintMas(arr, N);
    printf("\nКонтрольная сумма : %d", CheckSum(arr, N));
    printf("\nКол-во серий : %d", RunNumber(arr, N));
    printf("\n\n");
    printf("---------------------------------------------------------------------------------------------------------");
    printf("\n|n\t|\t  Выбором\t|\t Пузырьком  \t|\t Шейкерная  \t|\t Вставкой   \t|");
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------\n");

    FillRand(arr, N);
    selectionSort(arr, N, C, M);
    printf("|%d\t|\t  %d\t\t|", N, C + M);
    FillRand(arr, N);
    bubbleSort(arr, N, C2, M2);
    printf("\t %d\t\t|", C2 + M2);
    FillRand(arr, N);
    shakerSort(arr, N, C3, M3);
    printf("\t %d\t\t|", C3 + M3);
    FillRand(arr, N);
    insertionSort(arr, N, C4, M4);
    printf("\t %d\t\t|", C4 + M4);
    printf("\n");

    N = 200;
    arr = new int[N];

    FillRand(arr, N);
    selectionSort(arr, N, C, M);
    printf("|%d\t|\t  %d\t\t|", N, C + M);
    FillRand(arr, N);
    bubbleSort(arr, N, C2, M2);
    printf("\t %d\t\t|", C2 + M2);
    FillRand(arr, N);
    shakerSort(arr, N, C3, M3);
    printf("\t %d\t\t|", C3 + M3);
    FillRand(arr, N);
    insertionSort(arr, N, C4, M4);
    printf("\t %d\t\t|", C4 + M4);
    printf("\n");

    N = 300;
    arr = new int[N];

    FillRand(arr, N);
    selectionSort(arr, N, C, M);
    printf("|%d\t|\t  %d\t\t|", N, C + M);
    FillRand(arr, N);
    bubbleSort(arr, N, C2, M2);
    printf("\t %d\t\t|", C2 + M2);
    FillRand(arr, N);
    shakerSort(arr, N, C3, M3);
    printf("\t %d\t\t|", C3 + M3);
    FillRand(arr, N);
    insertionSort(arr, N, C4, M4);
    printf("\t %d\t\t|", C4 + M4);
    printf("\n");

    N = 400;
    arr = new int[N];

    FillRand(arr, N);
    selectionSort(arr, N, C, M);
    printf("|%d\t|\t  %d\t\t|", N, C + M);
    FillRand(arr, N);
    bubbleSort(arr, N, C2, M2);
    printf("\t %d\t\t|", C2 + M2);
    FillRand(arr, N);
    shakerSort(arr, N, C3, M3);
    printf("\t %d\t\t|", C3 + M3);
    FillRand(arr, N);
    insertionSort(arr, N, C4, M4);
    printf("\t %d\t\t|", C4 + M4);
    printf("\n");

    N = 500;
    arr = new int[N];

    FillRand(arr, N);
    selectionSort(arr, N, C, M);
    printf("|%d\t|\t  %d\t|", N, C + M);
    FillRand(arr, N);
    bubbleSort(arr, N, C2, M2);
    printf("\t %d\t\t|", C2 + M2);
    FillRand(arr, N);
    shakerSort(arr, N, C3, M3);
    printf("\t %d\t\t|", C3 + M3);
    FillRand(arr, N);
    insertionSort(arr, N, C4, M4);
    printf("\t %d\t\t|", C4 + M4);
    printf("\n");
    printf("---------------------------------------------------------------------------------------------------------");
    printf("\n");
}