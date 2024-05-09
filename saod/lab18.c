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