#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Выводит массив arr размера n на экран
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Создает массив arr размера n с случайными целыми числами в диапазоне [0, 99]
void createRandomArray(int arr[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
}

// Сортирует массив arr размера n методом Шелла с подсчетом пересылок и сравнений
void shellSort(int arr[], int n, int *swapCount, int *compareCount)
{
    int gap, i, j, temp;

    // Выбираем начальный размер промежутка
    for (gap = n / 2; gap > 0; gap /= 2)
    {

        // Выполняем сортировку вставками с шагом gap
        for (i = gap; i < n; i++)
        {
            temp = arr[i];

            // Сдвигаем элементы, чтобы найти место для вставки
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
                (*swapCount)++;
                (*compareCount)++;
            }

            // Вставляем элемент на найденное место
            arr[j] = temp;
            (*swapCount)++;
        }
    }
}

// Сортирует массив arr размера n методом прямого включения с подсчетом пересылок и сравнений
void insertionSort(int arr[], int n, int *swapCount, int *compareCount)
{
    int i, j, temp;
    *swapCount = 0;
    *compareCount = 0;

    for (i = 1; i < n; i++)
    {
        temp = arr[i];
        j = i - 1;
        (*compareCount)++;
        while (j >= 0 && temp < arr[j])
        {
            (*compareCount)++;
            (*swapCount)++;
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }

    printf(" %15d |", *swapCount + *compareCount);
}

int main()
{
    int arr[500];
    int n;
    int swapCount, compareCount;

    printf("|   n   | Shell M + C | Insertion M + C |\n");
    printf("|-------|------------|-----------------|\n");

    // Исследуем метод Шелла и метод прямого включения на массивах со 100, 200, 300, 400 и 500 элементами
    for (n = 100; n <= 500; n += 100)
    {
        // Создаем случайный массив
        createRandomArray(arr, n);

        // Инициализируем счетчики пересылок и сравнений
        swapCount = 0;
        compareCount = 0;

        // Сортируем методом Шелла
        shellSort(arr, n, &swapCount, &compareCount);
        printf("| %5d | %10d |", n, swapCount + compareCount);

        // Инициализируем счетчики пересылок и сравнений
        swapCount = 0;
        compareCount = 0;

        // Сортируем методом прямого включения
        insertionSort(arr, n, &swapCount, &compareCount);
        printf(" %15d |\n", swapCount + compareCount);
    }

    return 0;
}
