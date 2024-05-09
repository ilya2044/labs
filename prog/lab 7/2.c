#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{

    int **matrix, n;
    printf("Введите количество строк \n");
    scanf("%d", &n);

    matrix = (int **)malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        int s = rand() % 10 + 1;
        matrix[i] = (int *)malloc(sizeof(int) * s);
        matrix[i][0] = s;
        printf("%i ", s);
        for (int j = 1; j < s; j++)
        {
            matrix[i][j] = rand() % 101;
            printf("%i ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("Сумма %i строки - ", i + 1);
        int s = 0;
        for (int j = 0; j < matrix[i][0]; j++)
        {
            s += matrix[i][j];
        }
        printf("%i\n", s);
    }
}
