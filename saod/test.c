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

int main()
{
    int arr[500];
    int n;
    int swapCount, compareCount;

    printf("|   n   | Shell M + C |\n");
    printf("|-------|------------|\n");

    // Исследуем метод Шелла на массивах со 100, 200, 300, 400 и 500 элементами
    for (n = 100; n <= 500; n += 100)
    {
        // Создаем случайный массив
        createRandomArray(arr, n);

        // Сбрасываем счетчики
        swapCount = 0;
        compareCount = 0;

        // Сортируем массив методом Шелла с подсчетом пересылок и сравнений
        shellSort(arr, n, &swapCount, &compareCount);

        // Выводим результаты исследования в таблицу
        printf("|%7d|%12d|\n", n, swapCount + compareCount);
    }

    return 0;
}
