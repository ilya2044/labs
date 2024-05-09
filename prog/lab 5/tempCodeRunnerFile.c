void PrintMas(int **x, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%i ", x[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int i, m, k, j, ost;
    int *A, **B;

    scanf("%d", &m);
    scanf("%d", &k);

    A = (int *)malloc(sizeof(int) * m);

    for (i = 0; i < m; i++)
    {
        A[i] = rand() % 90 + 10;
        printf("%d ", A[i]);
    }
    printf("\n\n");

    if (m % k != 0)
    {
        ost = m / k + m / k + 1;
    }
    else
    {
        ost = m / k;
    }

    B = (int **)malloc(sizeof(int *) * ost);

    for (i = 0; i < ost; i++)
    {
        B[i] = (int *)malloc(sizeof(int) * k);

        for (j = 0; j < k; j++)
        {
            if (i * k + j < m)
            {
                B[i][j] = A[i * k + j];
            }
            else
            {
                B[i][j] = 0;
            }
        }
    }

    PrintMas(B, ost, k);

    for (i = 0; i < ost; i++)
    {
        free(B[i]);
    }
    free(A);
    free(B);
}