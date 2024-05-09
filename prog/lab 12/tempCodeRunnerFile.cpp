#include <iostream>
#include <ctime>
#include <random>
#include <locale.h>
#include "sorts.h"
using namespace std;
double timer(int tip_sort, int a[], long long n)
{
    unsigned int start = clock();
    if (tip_sort == 1)
    {
        selectionSort(a, n);
    }
    else if (tip_sort == 2)
    {
        bubbleSort(a, n);
    }
    else if (tip_sort == 3)
    {
        insertionSort(a, n);
    }
    else if (tip_sort == 4)
    {
        mergeSort(a, n);
    }
    else
    {
        quickSort(a, n);
    }
    return (clock() - start) / 1000.0;
}

double timer(int tip_sort, float a[], long long n)
{
    unsigned int start = clock();
    if (tip_sort == 1)
    {
        selectionSort(a, n);
    }
    else if (tip_sort == 2)
    {
        bubbleSort(a, n);
    }
    else if (tip_sort == 3)
    {
        insertionSort(a, n);
    }
    else if (tip_sort == 4)
    {
        mergeSort(a, n);
    }
    else
    {
        quickSort(a, n);
    }
    return (clock() - start) / 1000.0;
}
int main()
{
    setlocale(LC_ALL, "Russian");

    long long choice, len, type;
    double time;
    while (true)
    {
        cout << "Type sort:\n(0) exit\n(1) selectionSort\n(2) bubbleSort\n(3) insertionSort\n(4)  mergeSort\n(5) quickSort\n";
        cin >> choice;
        if (choice == 0)
            return 0;
        cout << "dlina massiva:\n";
        cin >> len;
        cout << "type massive:\n(0) int\n(1) float\n";
        cin >> type;
        if (type == 0)
        {
            int m[100000];
            for (long long i = 0; i < len; i++)
                m[i] = rand();
            cout << timer(choice, m, len) << "s\n";
        }
        else if (type == 1)
        {
            float m[100000];
            for (long long i = 0; i < len; i++)
                m[i] = rand();
            cout << timer(choice, m, len) << "s\n";
        }
        else
        {
            cout << "I dont kmow what the type";
        }
    }
}
