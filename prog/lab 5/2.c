#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **A;
    A = (int **)malloc(sizeof(int *) * 9);
    for (int i = 0; i < 9; i++)
    {
        A[i] = (int *)malloc(sizeof(int) * (i + 1));
        for (int j = 0; j < i + 1; j++)
        {
            A[i][j] = (j + 1) * (i + 1);
            printf("%i ", A[i][j]);
        }
        printf("\n");
        free(A[i]);
    }
    free(A);
}